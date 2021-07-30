#include "headers/test_vector.hpp"
#include "headers/test_map.hpp"

void	print_test(std::string name, std::string args, int num_args) {
	std::cout << name << "\t|";
	int	pos = 0;
	int end = 0;
	for (int i = 0; i < num_args; ++i) {
		end = args.find(", ", pos);
		std::cout << CIAN << args.substr(pos, end - pos) << RESET << "\t|";
		pos = end + 2;
	}
	std::cout << std::endl;
}

void	print_result(bool res, bool capacity) {
	if (res) {
		if (capacity)
			std::cout << GREEN << "  [OK]" << RESET << "\t|";
		else
			std::cout << YELLOW << "  [OK]" << RESET << "\t|";
	}
	else
		std::cout << RED << "  [KO]" << RESET << "\t|";
}