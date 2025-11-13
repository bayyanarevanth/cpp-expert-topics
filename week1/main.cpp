
#include<iostream>
#include"Movies.hpp"


using namespace std;
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, short int watched);




int main()
{

    Movies my_movies;
    cout<<"Hello World!"<<endl;
    my_movies.display_all_movies();

    add_movie(my_movies, "Big", "PG-13",2);                 // OK
    add_movie(my_movies,"Star Wars", "PG",5);             // OK
    add_movie(my_movies,"Cinderella", "PG",7);           // OK

    my_movies.display_all_movies();   // Big, Star Wars, Cinderella

    add_movie(my_movies,"Cinderella", "PG",7);            // Already exists
    add_movie(my_movies,"Ice Age", "PG",12);              // OK

    my_movies.display_all_movies();    // Big, Star Wars, Cinderella, Ice Age
    cout<< my_movies.increment_watched("Cinderella"); 

    increment_watched(my_movies,"Big");                    // OK
    increment_watched(my_movies,"Ice Age");              // OK

    my_movies.display_all_movies();    // Big and Ice Age watched count incremented by 1

    increment_watched(my_movies,"XXX");         // XXX not found

    return 0;


}

void add_movie(Movies &movies, std::string name, std::string rating, short int watched) {
    if (movies.add_movie(name,rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
        movies.display_all_movies();
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}