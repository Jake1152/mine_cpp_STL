#ifndef FT_CONTAINER_HPP
# define FT_CONTAINER_HPP

# include <iostream>
# include <string>
# include <deque>
# include <stdlib.h>

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m-"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

const std::string GREEN = "\x1B[1;32m";
const std::string REDD = "\x1B[1;31m";
const std::string YELLOW = "\x1B[1;33m";
const std::string WHITE = "\x1B[1;39m";
const std::string RESET = "\033[0m";

using std::cout;
using std::endl;

# if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <utility>
	namespace ft = std;
	#define NAMESPACE std
    #define TYPE "std"
# else
	// #include "../include/map.hpp"
	#include "../include/stack.hpp"
	#include "../include/vector.hpp"
	#include "../include/utility.hpp"
	#define NAMESPACE ft
    #define TYPE "ft"
# endif

# define MAX_RAM 4294967296
# define BUFFER_SIZE 4096
# define CONTOUR "-------------------------------------------------"

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

void    test1_subject(void);
void	test2_vector(void);
void	test3_stack(void);
void	test4_map(void);

#endif