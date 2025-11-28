//
// Created by revanth on 14.11.25.
//

/* macro defines */

#include "../ObjectsAndClasses/Movies.hpp"
#include "../operator-overloading/operator-overload.hpp"
#if INH_SRC_ENABLE == 1
#include "../inheritance/inheritance.hpp"
#endif
#if POLY_SRC_ENABLE == 1
#include "../polymorphism/Account_Util.h"
#endif

#include "../strings/strings_assignment.hpp"

#ifndef CPP_PROJECT_ADDITIONAL_HPP
#define CPP_PROJECT_ADDITIONAL_HPP

using namespace std;
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, short int watched);

#endif //CPP_PROJECT_ADDITIONAL_HPP