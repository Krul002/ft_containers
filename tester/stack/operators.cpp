#include "../headers/test_stack.hpp"

void	operators2() {
	std::cout << "\t\t|";
	/*  OPERATOR==  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec1;
		ft::stack<int>		ft_vec1;
		std::stack<int>	std_vec2;
		ft::stack<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 == ft_vec2) == (std_vec1 == std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 == std_vec2, ft_vec1 == ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/stack/operator==");

		std_vec1.push(12);
		ft_vec1.push(12);
		bool	two = (ft_vec1 == ft_vec2) == (std_vec1 == std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 == std_vec2, ft_vec1 == ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/stack/operator==");

		std_vec2.push(15);
		ft_vec2.push(15);
		bool	three = (ft_vec1 == ft_vec2) == (std_vec1 == std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 == std_vec2, ft_vec1 == ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/stack/operator==");

		std_vec1.pop();
		ft_vec1.pop();
		bool	four = (ft_vec1 == ft_vec2) == (std_vec1 == std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 == std_vec2, ft_vec1 == ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/stack/operator==");

		print_result(one && two && three && four, true);
	}
	/*  OPERATOR!=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec1;
		ft::stack<int>		ft_vec1;
		std::stack<int>	std_vec2;
		ft::stack<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 != ft_vec2) == (std_vec1 != std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 != std_vec2, ft_vec1 != ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/stack/operator!=");

		std_vec1.push(12);
		ft_vec1.push(12);
		bool	two = (ft_vec1 != ft_vec2) == (std_vec1 != std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 != std_vec2, ft_vec1 != ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/stack/operator!=");

		std_vec2.push(15);
		ft_vec2.push(15);
		bool	three = (ft_vec1 != ft_vec2) == (std_vec1 != std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 != std_vec2, ft_vec1 != ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/stack/operator!=");

		std_vec1.pop();
		ft_vec1.pop();
		bool	four = (ft_vec1 != ft_vec2) == (std_vec1 != std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 != std_vec2, ft_vec1 != ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/stack/operator!=");

		print_result(one && two && three && four, true);
	}
	/*  OPERATOR<  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec1;
		ft::stack<int>		ft_vec1;
		std::stack<int>	std_vec2;
		ft::stack<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 < ft_vec2) == (std_vec1 < std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 < std_vec2, ft_vec1 < ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/stack/operator<");

		std_vec1.push(12);
		ft_vec1.push(12);
		bool	two = (ft_vec1 < ft_vec2) == (std_vec1 < std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 < std_vec2, ft_vec1 < ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/stack/operator<");

		std_vec2.push(15);
		ft_vec2.push(15);
		bool	three = (ft_vec1 < ft_vec2) == (std_vec1 < std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 < std_vec2, ft_vec1 < ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/stack/operator<");

		std_vec1.pop();
		ft_vec1.pop();
		bool	four = (ft_vec1 < ft_vec2) == (std_vec1 < std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 < std_vec2, ft_vec1 < ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/stack/operator<");

		print_result(one && two && three && four, true);
	}
	/*  OPERATOR<=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec1;
		ft::stack<int>		ft_vec1;
		std::stack<int>	std_vec2;
		ft::stack<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 <= ft_vec2) == (std_vec1 <= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 <= std_vec2, ft_vec1 <= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/stack/operator<=");

		std_vec1.push(12);
		ft_vec1.push(12);
		bool	two = (ft_vec1 <= ft_vec2) == (std_vec1 <= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 <= std_vec2, ft_vec1 <= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/stack/operator<=");

		std_vec2.push(15);
		ft_vec2.push(15);
		bool	three = (ft_vec1 <= ft_vec2) == (std_vec1 <= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 <= std_vec2, ft_vec1 <= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/stack/operator<=");

		std_vec1.pop();
		ft_vec1.pop();
		bool	four = (ft_vec1 <= ft_vec2) == (std_vec1 <= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 <= std_vec2, ft_vec1 <= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/stack/operator<=");

		print_result(one && two && three && four, true);
	}
	/*  OPERATOR>  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec1;
		ft::stack<int>		ft_vec1;
		std::stack<int>	std_vec2;
		ft::stack<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 > ft_vec2) == (std_vec1 > std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 > std_vec2, ft_vec1 > ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/stack/operator>");

		std_vec1.push(12);
		ft_vec1.push(12);
		bool	two = (ft_vec1 > ft_vec2) == (std_vec1 > std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 > std_vec2, ft_vec1 > ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/stack/operator>");

		std_vec2.push(15);
		ft_vec2.push(15);
		bool	three = (ft_vec1 > ft_vec2) == (std_vec1 > std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 > std_vec2, ft_vec1 > ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/stack/operator>");

		std_vec1.pop();
		ft_vec1.pop();
		bool	four = (ft_vec1 > ft_vec2) == (std_vec1 > std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 > std_vec2, ft_vec1 > ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/stack/operator>");

		print_result(one && two && three && four, true);
	}
	/*  OPERATOR>=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::stack<int>	std_vec1;
		ft::stack<int>		ft_vec1;
		std::stack<int>	std_vec2;
		ft::stack<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 >= ft_vec2) == (std_vec1 >= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 >= std_vec2, ft_vec1 >= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/stack/operator>=");

		std_vec1.push(12);
		ft_vec1.push(12);
		bool	two = (ft_vec1 >= ft_vec2) == (std_vec1 >= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 >= std_vec2, ft_vec1 >= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/stack/operator>=");

		std_vec2.push(15);
		ft_vec2.push(15);
		bool	three = (ft_vec1 >= ft_vec2) == (std_vec1 >= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 >= std_vec2, ft_vec1 >= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/stack/operator>=");

		std_vec1.pop();
		ft_vec1.pop();
		bool	four = (ft_vec1 >= ft_vec2) == (std_vec1 >= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 >= std_vec2, ft_vec1 >= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/stack/operator>=");

		print_result(one && two && three && four, true);
	}
	std::cout << std::endl;
}