//
// Created by revanth on 24.11.25.
//#include <stdint.h>

#define PERIPH_BASE       0x40000000UL
#define AHB1PERIPH_BASE   (PERIPH_BASE + 0x00020000UL)
#define APB2PERIPH_BASE   (PERIPH_BASE + 0x00010000UL)

#define RCC_BASE          (AHB1PERIPH_BASE + 0x3800)
#define RCC_AHB1ENR       (*(volatile uint32_t*)(RCC_BASE + 0x30))
#define RCC_APB2ENR       (*(volatile uint32_t*)(RCC_BASE + 0x44))

#define GPIOA_BASE        (AHB1PERIPH_BASE + 0x0000)
#define GPIOA_MODER       (*(volatile uint32_t*)(GPIOA_BASE + 0x00))

#define ADC1_BASE         (APB2PERIPH_BASE + 0x2000)
#define ADC1_SR           (*(volatile uint32_t*)(ADC1_BASE + 0x00))
#define ADC1_CR1          (*(volatile uint32_t*)(ADC1_BASE + 0x04))
#define ADC1_CR2          (*(volatile uint32_t*)(ADC1_BASE + 0x08))
#define ADC1_SMPR2        (*(volatile uint32_t*)(ADC1_BASE + 0x10))
#define ADC1_SQR3         (*(volatile uint32_t*)(ADC1_BASE + 0x34))

#define DMA2_BASE         (AHB1PERIPH_BASE + 0x6400)
#define DMA2_Stream0_CR   (*(volatile uint32_t*)(DMA2_BASE + 0x010))
#define DMA2_Stream0_NDTR (*(volatile uint32_t*)(DMA2_BASE + 0x014))
#define DMA2_Stream0_PAR  (*(volatile uint32_t*)(DMA2_BASE + 0x018))
#define DMA2_Stream0_M0AR (*(volatile uint32_t*)(DMA2_BASE + 0x01C))
#define DMA2_LIFCR        (*(volatile uint32_t*)(DMA2_BASE + 0x008))

#define ADC1_DR           (*(volatile uint32_t*)(ADC1_BASE + 0x4C))

// 50-sample circular buffer
volatile uint16_t adc_buf[50];

void delay(volatile uint32_t d)
{
    while(d--);
}

int main(void)
{
    // -------- 1) ENABLE CLOCKS ----------
    RCC_AHB1ENR |= (1 << 0);   // GPIOA EN
    RCC_AHB1ENR |= (1 << 22);  // DMA2 EN
    RCC_APB2ENR |= (1 << 8);   // ADC1 EN

    // -------- 2) CONFIGURE PA5 AS ANALOG ----------
    GPIOA_MODER |= (3 << (5 * 2));   // analog mode (11)

    // -------- 3) CONFIGURE DMA2 STREAM 0 ----------
    DMA2_Stream0_CR &= ~1;            // disable stream
    while (DMA2_Stream0_CR & 1);      // wait till disabled

    DMA2_LIFCR = 0x3D;                // clear all flags

    DMA2_Stream0_CR =
        (0 << 25) |        // Channel 0 (ADC1)
        (0 << 23) |        // priority low
        (1 << 10) |        // memory increment
        (0 << 11) |        // peripheral fixed
        (1 << 13) |        // MSIZE = 16-bit
        (1 << 11) |        // PSIZE = 16-bit
        (1 << 8)  |        // circular mode
        (0 << 6)  |        // peripheral → memory
        (1 << 4);          // transfer complete interrupt OFF (simple mode)

    DMA2_Stream0_NDTR = 50;               // number of samples
    DMA2_Stream0_PAR  = (uint32_t)&ADC1_DR;
    DMA2_Stream0_M0AR = (uint32_t)adc_buf;

    DMA2_Stream0_CR |= 1;                 // enable DMA stream

    // -------- 4) CONFIGURE ADC1 ----------
    ADC1_CR1 = 0;                         // 12-bit
    ADC1_SMPR2 |= (4 << 15);              // ch5 sample time (55 cycles for stable conversion)
    ADC1_SQR3  = 5;                       // channel 5 first in sequence

    ADC1_CR2 =
        (1 << 8)  |   // DMA mode
        (1 << 9)  |   // DMA continuous requests
        (1 << 1)  |   // continuous conversion
        (1 << 0);     // ADC ON

    // -------- 5) SET SAMPLING RATE TO ~100 Hz ----------
    // For STM32F4, continuous mode speed is set by sample time + ADC prescaler.
    // Here we add delay in the while loop to simulate ~100Hz sampling.
    // Real implementation uses timer trigger + external event.
    delay(10000);

    // -------- 6) START ADC ----------
    ADC1_CR2 |= (1 << 30);    // SWSTART

    // -------- APPLICATION LOOP ----------
    while(1)
    {
        // adc_buf[] continuously updated by DMA circular mode
        // Do something with adc_buf here...
    }
}
