// pair::pair example
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout
#include "../../include/utility.hpp"

int main () {
  std::cout << "==============  std:: ===============" << std::endl;
  std::pair <std::string,double> product1;                     // default constructor
  std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  std::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

  std::cout << "==============  ft:: ===============" << std::endl;
  ft::pair <std::string,double> product4;                     // default constructor
  ft::pair <std::string,double> product5 ("tomatoes",2.30);   // value init
  ft::pair <std::string,double> product6 (product5);          // copy constructor

  product4 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)5
  product5.first = "shoes";                  // the type of first is strin6
  product5.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product4.first << " is $" << product4.second << '\n';
  std::cout << "The price of " << product5.first << " is $" << product5.second << '\n';
  std::cout << "The price of " << product6.first << " is $" << product6.second << '\n';
  return 0;
}