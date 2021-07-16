#include "headers.hpp"
#include "vector.hpp"
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <ostream>
#include <vector>
#include "iterator.hpp"


int		main() {
	ft::vector<int>	vec;
	vec.push_back(12);
	std::cout << vec[0] << std::endl;
	return 0;
}