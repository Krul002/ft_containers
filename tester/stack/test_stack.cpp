#include "../headers/test_stack.hpp"
#include <cstddef>
#include <exception>
#include <iostream>
#include <list>
#include <ostream>
#include <vector>

void	test_stack() {
	mkdir("./test/stack", 0777);
	std::cout << GREEN << "STACK:" << RESET << std::endl;
	print_test("Methods\t", "cons-r, empty, size, top, push, pop", 6);
	methods();
	std::cout << std::endl;
	print_test("Operators", "==, !=, <, <=, >, >=", 6);
	operators2();
	std::cout << std::endl;
}