#include "../headers/test_stack.hpp"
#include <iostream>
#include <ostream>

void	methods() {
	std::cout << "\t\t|";
	/*  CONSTRUCTOR  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec;
		ft::stack<int>		ft_vec;

		bool	one = test_stack<int>(std_vec, ft_vec);
		print_test_stack<int>(std_vec, ft_vec, mode, 1, "./test/stack/default_construct");
		print_result(one, true);
	}
	/*  EMPTY  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec;
		ft::stack<int>		ft_vec;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = std_vec.empty() == ft_vec.empty();
		list_push<bool>(std_lst, ft_lst, std_vec.empty(), ft_vec.empty());
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/stack/empty");

		test_push_back(std_vec, ft_vec, 13, 10);
		bool	two = std_vec.empty() == ft_vec.empty();
		list_push<bool>(std_lst, ft_lst, std_vec.empty(), ft_vec.empty());
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/stack/empty");

		bool	three = test_stack<int>(std_vec, ft_vec);
		print_test_stack<int>(std_vec, ft_vec, mode, 4, "./test/stack/empty");
		print_result(one && two && three, true);
	}
	/*  SIZE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec;
		ft::stack<int>		ft_vec;
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		std_vec.push(10);
		ft_vec.push(10);
		bool	one = std_vec.size() == ft_vec.size();
		list_push<size_t>(std_lst, ft_lst, std_vec.size(), ft_vec.size());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 1, "./test/stack/size");

		test_push_back(std_vec, ft_vec, 13, 10);
		bool	two = std_vec.size() == ft_vec.size();
		list_push<size_t>(std_lst, ft_lst, std_vec.size(), ft_vec.size());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 2, "./test/stack/size");

		test_pop_back(std_vec, ft_vec, 6);
		bool	three = std_vec.size() == ft_vec.size();
		list_push<size_t>(std_lst, ft_lst, std_vec.size(), ft_vec.size());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 3, "./test/stack/size");

		bool	four = test_stack<int>(std_vec, ft_vec);
		print_test_stack<int>(std_vec, ft_vec, mode, 4, "./test/stack/size");
		print_result(one && two && three && four, true);
	}
	/*  TOP  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec;
		ft::stack<int>		ft_vec;
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		bool	one = true;
		for (int i = 0; i < 5 && one == true; ++i) {
			ft_vec.push(i);
			std_vec.push(i);
			one = std_vec.top() == ft_vec.top();
			list_push<size_t>(std_lst, ft_lst, std_vec.top(), ft_vec.top());
			print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, i + 1, "./test/stack/top");
		}
		print_result(one, true);
	}
	/*  PUSH  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec;
		ft::stack<int>		ft_vec;

		bool	one = true;
		for (int i = 0; i < 100 && one == true; ++i) {
			std_vec.push(i);
			ft_vec.push(i);
			one = test_stack<int>(std_vec, ft_vec);
		}
		print_test_stack<int>(std_vec, ft_vec, mode, 1, "./test/stack/push");
		print_result(one, true);
	}
	/*  POP  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec;
		ft::stack<int>		ft_vec;

		bool	one = true;
		for (int i = 0; i < 100 && one == true; ++i) {
			std_vec.push(i);
			ft_vec.push(i);
		}
		for (int i = 0; i < 100 && one == true; ++i) {
			std_vec.pop();
			ft_vec.pop();
			one = test_stack<int>(std_vec, ft_vec);
		}
		print_test_stack<int>(std_vec, ft_vec, mode, 1, "./test/stack/pop");
		print_result(one, true);
	}
	std::cout << std::endl;
}