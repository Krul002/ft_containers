#include "../headers/test_vector.hpp"
#include <cstddef>
#include <exception>
#include <iostream>
#include <list>
#include <ostream>
#include <vector>

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