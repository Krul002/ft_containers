#include "headers.hpp"
#include <functional>
#include <ios>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
#include "map.hpp"
#include "vector.hpp"
#include "red_black_tree.hpp"
#include "new_iterator.hpp"
#include <stack>
#include "stack.hpp"

int		main(int narg, char **args) {
	if (narg < 2) {
		// test_vector();
		// test_stack();
		// test_map();
	}
	else {
		for (int i = 0; i < narg; ++i) {
			// if (std::string(args[i]) == "vector")
				// test_vector();
			// if (std::string(args[i]) == "stack")
			// 	test_stack();
			// if (std::string(args[i]) == "map")
			// 	test_map();
		}
	}
	return 0;
}