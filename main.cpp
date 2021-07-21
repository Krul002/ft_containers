#include "headers.hpp"

int		main(int narg, char **args) {
	mkdir("./test", 0777);
	if (narg < 2) {
		test_vector();
		// test_stack();
		// test_map();
	}
	else {
		for (int i = 0; i < narg; ++i) {
			if (std::string(args[i]) == "vector")
				test_vector();
			// if (std::string(args[i]) == "stack")
			// 	test_stack();
			// if (std::string(args[i]) == "map")
			// 	test_map();
		}
	}
	return 0;
}