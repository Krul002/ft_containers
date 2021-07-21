#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <iterator>
#include <memory>
#include <ostream>
#include <string>
#include <sys/stat.h>

#define RED "\33[1;31m"
#define GREEN "\33[1;32m"
#define YELLOW "\33[1;33m"
#define BLUE "\33[1;34m"
#define CIAN "\33[1;36m"
#define RESET "\33[0m"

#define ERR std::cout << RED

#define OK std::cout << GREEN
#define END	RESET << std::endl

void	test_vector();
void	test_stack();
void	test_map();