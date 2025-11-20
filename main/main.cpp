
#include<iostream>
#include "additional.hpp"

using namespace std;
//#define OBJ_CLASS_CHALLENG
//#define OPER_OVERLOADING


int main()
{

    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.emplace_back();
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);

    // Savings

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    // Checking

    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account {} );
    //In most compilers, an empty {} is considered an initializer-list
    check_accounts.push_back(Checking_Account {"Kirk"} );
    check_accounts.push_back(Checking_Account {"Spock", 2000} );
    check_accounts.push_back(Checking_Account {"Bones", 5000} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust

    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {} );
    trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0} );
    trust_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0} );
    trust_accounts.push_back(Trust_Account {"Aramis", 30000} );

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);

    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);




#ifdef OPER_OVERLOADING
    cout << boolalpha << endl;
    StringOperations a {"Franka"};
    StringOperations b {"Frank"};
    cout << (a==b) << endl;         // true
    cout << (a!=b) << endl;           // false
    
    b = "george";
    cout << (a==b) << endl;         // false
    cout << (a!=b) << endl;          // true
     cout << (a<b) << endl;         // true
    cout << (a>b) << endl;          // false
    
    StringOperations s1 {"FranK"};
    s1 = ++s1;
    cout << s1 << endl;             // FRANK
    s1 = -s1;
    cout << s1 << endl;             // frank              

     s1 = s1 + StringOperations{"*****"};
    cout << s1 << endl;             // frank*****       

    s1 += "-----";                      // frank*****-----
    cout << s1 << endl;
    
    StringOperations s2{"12345"};
    s1 = (s2 * 3);
    cout << s1 << endl;           // 123451234512345
    
    StringOperations s3{"abcdef"};  
    s3 *= 5;
    cout << s3 << endl;             // abcdefabcdefabcdefabcdefabcdef
    
    StringOperations repeat_string;
    int repeat_times;
    cout << "Enter a string to repeat: " << endl;
    cin >> repeat_string;
    cout << "How many times would you like it repeated? " << endl;
    cin >> repeat_times;
    repeat_string *= repeat_times;
    cout << "The resulting string is: " << repeat_string << endl;
    
    cout << (repeat_string * 12) << endl;
    
    repeat_string = "RepeatMe";
    cout << (repeat_string + repeat_string + repeat_string) << endl;
    
    repeat_string += (repeat_string * 3);
    cout << repeat_string << endl;
    
    repeat_string = "RepeatMe";
    repeat_string += (repeat_string + repeat_string + repeat_string);


    StringOperations s = "frank";
    ++s;
    cout << s << endl;                  // FRANK
    
    s = -s; 
    cout << s << endl;                  // frank
    StringOperations result;
    result = ++s;
    cout << s << endl;                  // FRANK
    cout << result << endl;           // FRANK
    
    s = "Frank";
    cout << s << endl;                  //"Frank"
    ++s;
    cout << s << endl;                  // FRANK
    
    s = -s;
    cout << s << endl;                  // frank
    result = ++s;
    cout << s << endl;                  // FRANK
    cout << result << endl;           // frank */
#endif

#ifdef OBJ_CLASS_CHALLENG
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
#endif
    return 0;
}

