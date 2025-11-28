cmake_minimum_required(VERSION 3.15)
project(cpp_project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(INH_SRC_OPT "Enable Inheritance files" OFF)
option(POLY_SRC_OPT "Enable Inheritance files" ON)

set (ALL_SRC
        # set uses ALL_SRC as variable so you dont need to parse ${ALL_SRC}
        main/main.cpp
        ObjectsAndClasses/Movie.cpp
        ObjectsAndClasses/Movie.hpp
        ObjectsAndClasses/Movies.cpp
        ObjectsAndClasses/Movies.hpp
        operator-overloading/operator-overload.cpp
        operator-overloading/operator-overload.hpp
        main/additional.cpp
        main/additional.hpp
        strings/strings_assignment.hpp
        strings/strings_assignment.cpp
)

if(INH_SRC_OPT)
    # list uses ALL_SRC as variable so you dont need to parse ${ALL_SRC}
    list(APPEND ALL_SRC
            inheritance/inheritance.cpp
            inheritance/inheritance.hpp
            inheritance/Account.cpp
            inheritance/Account.h
            inheritance/Account_Util.cpp
            inheritance/Account_Util.h
            inheritance/Savings_Account.cpp
            inheritance/Savings_Account.h
            inheritance/Checking_Account.cpp
            inheritance/Checking_Account.hpp
            inheritance/Trust_Account.cpp
            inheritance/Trust_Account.hpp
    )
endif()

if(POLY_SRC_OPT)
    # list uses ALL_SRC as variable so you dont need to parse ${ALL_SRC}
    list (APPEND ALL_SRC
        polymorphism/Account.cpp
        polymorphism/Account.h
        polymorphism/Account_Util.cpp
        polymorphism/Account_Util.h
        polymorphism/Savings_Account.cpp
        polymorphism/Savings_Account.h
        polymorphism/Checking_Account.cpp
        polymorphism/Checking_Account.h
        polymorphism/Trust_Account.cpp
        polymorphism/Trust_Account.h)

endif()


# add_executable takes the second argument as value of a variable so you need ${}
add_executable(cpp_project
        ${ALL_SRC})

if(INH_SRC_OPT)
    target_compile_definitions(cpp_project PRIVATE INH_SRC_ENABLE=1)
else ()
    target_compile_definitions(cpp_project PRIVATE INH_SRC_ENABLE=0)
endif()

if(POLY_SRC_OPT)
    target_compile_definitions(cpp_project PRIVATE POLY_SRC_ENABLE=1)
else ()
    target_compile_definitions(cpp_project PRIVATE POLY_SRC_ENABLE=0)
endif()

message(STATUS "INH_SRC_OPT = ${INH_SRC_OPT}")