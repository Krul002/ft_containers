#include "../headers/test_map.hpp"
#include <cstddef>
#include <exception>
#include <iostream>
#include <list>
#include <ostream>
#include <vector>

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

void	test_map() {
	mkdir("./test/map", 0777);
	std::cout << GREEN << "VECTOR:" << RESET << std::endl;
	print_test("Iterator", "*, ->, ++, --, ==, !=", 6);
	iterator2();
	const_iterator2();
	reverse_iterator2();
	const_reverse_iterator2();
	std::cout << std::endl;
	print_test("Constructors", "def, range, copy, =", 4);
	constructors2();
	std::cout << std::endl;
	print_test("Capacity", "size, max, empty", 3);
	capacity2();
	std::cout << std::endl;
	print_test("Access\t", "[]", 1);
	access2();
	std::cout << std::endl;
	print_test("Modifiers", "insert, erase, swap, clear", 4);
	modifiers2();
	std::cout << std::endl;
	print_test("Observers", "key, val", 2);
	observers();
	std::cout << std::endl;
	print_test("Operations", "find, count, lower, upper, equal", 5);
	operations();
	std::cout << std::endl;
}