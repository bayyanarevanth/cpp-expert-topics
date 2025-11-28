//
// Created by revanth on 21.11.25.
//


/*
 *    If the user enters the string "ABC", then your program should display:
 *      A
 *     ABA
 *    ABCBA
 *    If the user enters the string, "12345", then your program should display:
 *        1
 *       121
 *      12321
 *     1234321
 *    123454321
 *
 **/

#include "strings_assignment.hpp"



void stringDisplay(const std::string& s1)
{
    for ( int i = 0; i < s1.length(); i++)
    {
        std::string loc{s1.substr(0,i+1)};
        std::string sp(s1.size()-i, ' ');
        std::cout << sp + loc;
        loc = loc.erase(i,1);
        std::reverse(loc.begin(),loc.end());
        std::cout<<loc<<std::endl;
    }
}