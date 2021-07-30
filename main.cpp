#include "headers.hpp"
#include <functional>
#include <ios>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include "map.hpp"
#include "vector.hpp"
#include "red_black_tree.hpp"
#include "new_iterator.hpp"
#include <stack>
#include "stack.hpp"


int		main(int narg, char **args) {
	mkdir("./test", 0777);
	if (narg < 2) {
		test_vector();
		test_map();
		test_stack();
	}
	else {
		if (std::string(args[1]) == "map")
			test_map();
		if (std::string(args[1]) == "vector")
			test_vector();
		if (std::string(args[1]) == "stack")
			test_stack();
	}
	return 0;
}