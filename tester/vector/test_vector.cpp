#include "../headers/test_vector.hpp"
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

void	test_vector() {
	mkdir("./test/vector", 0777);
	std::cout << GREEN << "VECTOR:" << RESET << std::endl;
	print_test("Iterator", "*, ->, ++, --, +=, -=, [], ==, !=, <, <=, >, >=, +, -", 15);
	iterator();
	const_iterator();
	reverse_iterator();
	const_reverse_iterator();
	std::cout << std::endl;
	print_test("Constructors", "def, fill, range, copy, =", 5);
	constructors();
	std::cout << std::endl;
	print_test("Capacity", "size, max, resize, cap-ty, empty, res-ve", 6);
	capacity();
	std::cout << std::endl;
	print_test("Access\t", "[], at, front, back", 4);
	access();
	std::cout << std::endl;
	print_test("Modifiers", "assign, push, pop, insert, erase, swap, clear", 7);
	modifiers();
	std::cout << std::endl;
	print_test("Operators", "==, !=, <, <=, >, >=", 6);
	operators();
	std::cout << std::endl;
}