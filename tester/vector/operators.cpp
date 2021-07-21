#include "../headers/test_vector.hpp"

void	operators() {
	std::cout << "\t\t|";
	/*  OPERATOR==  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec1;
		ft::vector<int>		ft_vec1;
		std::vector<int>	std_vec2;
		ft::vector<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 == ft_vec2) == (std_vec1 == std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 == std_vec2, ft_vec1 == ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/vector/operator==");

		std_vec1.push_back(12);
		ft_vec1.push_back(12);
		bool	two = (ft_vec1 == ft_vec2) == (std_vec1 == std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 == std_vec2, ft_vec1 == ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/vector/operator==");

		std_vec2.push_back(15);
		ft_vec2.push_back(15);
		bool	three = (ft_vec1 == ft_vec2) == (std_vec1 == std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 == std_vec2, ft_vec1 == ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/vector/operator==");

		std_vec1[0] = 15;
		ft_vec1[0] = 15;
		bool	four = (ft_vec1 == ft_vec2) == (std_vec1 == std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 == std_vec2, ft_vec1 == ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/vector/operator==");

		print_result(one && two && three && four, std_vec1.capacity() == ft_vec1.capacity() && std_vec2.capacity() == ft_vec2.capacity());
	}
	/*  OPERATOR!=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec1;
		ft::vector<int>		ft_vec1;
		std::vector<int>	std_vec2;
		ft::vector<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 != ft_vec2) == (std_vec1 != std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 != std_vec2, ft_vec1 != ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/vector/operator!=");

		std_vec1.push_back(12);
		ft_vec1.push_back(12);
		bool	two = (ft_vec1 != ft_vec2) == (std_vec1 != std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 != std_vec2, ft_vec1 != ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/vector/operator!=");

		std_vec2.push_back(15);
		ft_vec2.push_back(15);
		bool	three = (ft_vec1 != ft_vec2) == (std_vec1 != std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 != std_vec2, ft_vec1 != ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/vector/operator!=");

		std_vec1[0] = 15;
		ft_vec1[0] = 15;
		bool	four = (ft_vec1 != ft_vec2) == (std_vec1 != std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 != std_vec2, ft_vec1 != ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/vector/operator!=");

		print_result(one && two && three && four, std_vec1.capacity() == ft_vec1.capacity() && std_vec2.capacity() == ft_vec2.capacity());
	}
	/*  OPERATOR<  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec1;
		ft::vector<int>		ft_vec1;
		std::vector<int>	std_vec2;
		ft::vector<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 < ft_vec2) == (std_vec1 < std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 < std_vec2, ft_vec1 < ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/vector/operator<");

		std_vec1.push_back(12);
		ft_vec1.push_back(12);
		bool	two = (ft_vec1 < ft_vec2) == (std_vec1 < std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 < std_vec2, ft_vec1 < ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/vector/operator<");

		std_vec2.push_back(15);
		ft_vec2.push_back(15);
		bool	three = (ft_vec1 < ft_vec2) == (std_vec1 < std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 < std_vec2, ft_vec1 < ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/vector/operator<");

		std_vec1[0] = 15;
		ft_vec1[0] = 15;
		bool	four = (ft_vec1 < ft_vec2) == (std_vec1 < std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 < std_vec2, ft_vec1 < ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/vector/operator<");

		print_result(one && two && three && four, std_vec1.capacity() == ft_vec1.capacity() && std_vec2.capacity() == ft_vec2.capacity());
	}
	/*  OPERATOR<=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec1;
		ft::vector<int>		ft_vec1;
		std::vector<int>	std_vec2;
		ft::vector<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 <= ft_vec2) == (std_vec1 <= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 <= std_vec2, ft_vec1 <= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/vector/operator<=");

		std_vec1.push_back(12);
		ft_vec1.push_back(12);
		bool	two = (ft_vec1 <= ft_vec2) == (std_vec1 <= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 <= std_vec2, ft_vec1 <= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/vector/operator<=");

		std_vec2.push_back(15);
		ft_vec2.push_back(15);
		bool	three = (ft_vec1 <= ft_vec2) == (std_vec1 <= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 <= std_vec2, ft_vec1 <= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/vector/operator<=");

		std_vec1[0] = 15;
		ft_vec1[0] = 15;
		bool	four = (ft_vec1 <= ft_vec2) == (std_vec1 <= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 <= std_vec2, ft_vec1 <= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/vector/operator<=");

		print_result(one && two && three && four, std_vec1.capacity() == ft_vec1.capacity() && std_vec2.capacity() == ft_vec2.capacity());
	}
	/*  OPERATOR>  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec1;
		ft::vector<int>		ft_vec1;
		std::vector<int>	std_vec2;
		ft::vector<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 > ft_vec2) == (std_vec1 > std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 > std_vec2, ft_vec1 > ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/vector/operator>");

		std_vec1.push_back(12);
		ft_vec1.push_back(12);
		bool	two = (ft_vec1 > ft_vec2) == (std_vec1 > std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 > std_vec2, ft_vec1 > ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/vector/operator>");

		std_vec2.push_back(15);
		ft_vec2.push_back(15);
		bool	three = (ft_vec1 > ft_vec2) == (std_vec1 > std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 > std_vec2, ft_vec1 > ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/vector/operator>");

		std_vec1[0] = 15;
		ft_vec1[0] = 15;
		bool	four = (ft_vec1 > ft_vec2) == (std_vec1 > std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 > std_vec2, ft_vec1 > ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/vector/operator>");

		print_result(one && two && three && four, std_vec1.capacity() == ft_vec1.capacity() && std_vec2.capacity() == ft_vec2.capacity());
	}
	/*  OPERATOR>=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec1;
		ft::vector<int>		ft_vec1;
		std::vector<int>	std_vec2;
		ft::vector<int>		ft_vec2;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = (ft_vec1 >= ft_vec2) == (std_vec1 >= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 >= std_vec2, ft_vec1 >= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./test/vector/operator>=");

		std_vec1.push_back(12);
		ft_vec1.push_back(12);
		bool	two = (ft_vec1 >= ft_vec2) == (std_vec1 >= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 >= std_vec2, ft_vec1 >= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./test/vector/operator>=");

		std_vec2.push_back(15);
		ft_vec2.push_back(15);
		bool	three = (ft_vec1 >= ft_vec2) == (std_vec1 >= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 >= std_vec2, ft_vec1 >= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./test/vector/operator>=");

		std_vec1[0] = 15;
		ft_vec1[0] = 15;
		bool	four = (ft_vec1 >= ft_vec2) == (std_vec1 >= std_vec2);
		list_push<bool>(std_lst, ft_lst, std_vec1 >= std_vec2, ft_vec1 >= ft_vec2);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 4, "./test/vector/operator>=");

		print_result(one && two && three && four, std_vec1.capacity() == ft_vec1.capacity() && std_vec2.capacity() == ft_vec2.capacity());
	}
	std::cout << std::endl;
}