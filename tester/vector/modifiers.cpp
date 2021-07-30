#include "../headers/test_vector.hpp"

void	modifiers() {
	std::cout << "Default\t\t|";
	/*  ASSIGN */
	{
		std::cout << "\t|";
	}
	/*  PUSH_BACK */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;

		bool	one = true;
		for (int i = 0; i < 100 && one == true; ++i) {
			std_vec.push_back(i);
			ft_vec.push_back(i);
			one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		}
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/push_back");
		print_result(one, std_vec.capacity() == ft_vec.capacity());
	}
	/*  POP_BACK */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;

		bool	one = true;
		for (int i = 0; i < 100 && one == true; ++i) {
			std_vec.push_back(i);
			ft_vec.push_back(i);
		}
		for (int i = 0; i < 100 && one == true; ++i) {
			std_vec.pop_back();
			ft_vec.pop_back();
			one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		}
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/pop_back");
		print_result(one, std_vec.capacity() == ft_vec.capacity());
	}
	/*  INSERT */
	{
		std::cout << "\t|";
	}
	/*  ERASE */
	{
		std::cout << "\t|";
	}
	/*  SWAP */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec1;
		ft::vector<int>		ft_vec1;
		std::vector<int>	std_vec2;
		ft::vector<int>		ft_vec2;

		for (int i = 0; i < 100; ++i) {
			std_vec1.push_back(i);
			ft_vec1.push_back(i);
		}
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec1, ft_vec1, mode, 1, "./test/vector/swap");
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec2, ft_vec2, mode, 2, "./test/vector/swap");
		std_vec1.swap(std_vec2);
		ft_vec1.swap(ft_vec2);
		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec1, ft_vec1) && test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec2, ft_vec2);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec1, ft_vec1, mode, 1, "./test/vector/swap");
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec2, ft_vec2, mode, 2, "./test/vector/swap");
		print_result(one, std_vec1.capacity() == ft_vec1.capacity() && std_vec2.capacity() == ft_vec2.capacity());
	}
	/*  CLEAR */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;

		for (int i = 0; i < 100; ++i) {
			std_vec.push_back(i);
			ft_vec.push_back(i);
		}
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/clear");
		std_vec.clear();
		ft_vec.clear();
		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/clear");
		print_result(one, std_vec.capacity() == ft_vec.capacity());
	}
	std::cout << std::endl;
	std::cout << "Single\t\t|";
	/*  ASSIGN */
	{
		std::cout << "\t|";
	}
	/*  PUSH_BACK */
	{
		std::cout << "\t|";
	}
	/*  POP_BACK */
	{
		std::cout << "\t|";
	}
	/*  INSERT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;
		std::vector<int>::iterator	std_it;
		ft::vector<int>::iterator	ft_it;
		std::list<int>	std_lst;
		std::list<int>	ft_lst;
		

		bool	one = true;
		for (int i = 0; i < 100 && one == true; ++i) {
			std_it = std_vec.insert(std_vec.begin(), i);
			ft_it = ft_vec.insert(ft_vec.begin(), i);
			one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec) && *std_it == *ft_it;
			list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
			print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, i + 1, "./test/vector/insert_single");
		}
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 101, "./test/vector/insert_single");
		print_result(one, std_vec.capacity() == ft_vec.capacity());
	}
	/*  ERASE */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;
		std::vector<int>::iterator	std_it;
		ft::vector<int>::iterator	ft_it;
		std::list<int>	std_lst;
		std::list<int>	ft_lst;

		for (int i = 0; i < 100; ++i) {
			std_it = std_vec.insert(std_vec.end(), i);
			ft_it = ft_vec.insert(ft_vec.end(), i);
		}
		bool	one = true;
		for (int i = 99; i >= 0 && one == true; --i) {
			std_it = std_vec.erase(std_vec.begin() + i);
			ft_it = ft_vec.erase(ft_vec.begin() + i);
			one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec) && *std_it == *ft_it;
			list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
			print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 100 - i, "./test/vector/erase_single");
		}
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 101, "./test/vector/erase_single");
		print_result(one, std_vec.capacity() == ft_vec.capacity());
	}
	/*  SWAP */
	{
		std::cout << "\t|";
	}
	/*  CLEAR */
	{
		std::cout << "\t|";
	}
	std::cout << std::endl;
	std::cout << "Range\t\t|";
	std::list<int>	lst;
	lst.push_back(87);
	lst.push_back(-12);
	lst.push_back(9765);
	lst.push_back(982);
	lst.push_back(0);
	lst.push_back(25);
	lst.push_back(-90);
	/*  ASSIGN */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec(130, 1);
		ft::vector<int>		ft_vec(130, 1);

		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/assing_range");

		std_vec.assign(lst.begin(), lst.end());
		ft_vec.assign(lst.begin(), lst.end());
		bool	two = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 2, "./test/vector/assing_range");
		print_result(one && two, std_vec.capacity() == ft_vec.capacity());
	}
	/*  PUSH_BACK */
	{
		std::cout << "\t|";
	}
	/*  POP_BACK */
	{
		std::cout << "\t|";
	}
	/*  INSERT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec(130, 1);
		ft::vector<int>		ft_vec(130, 1);

		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/insert_range");

		std_vec.insert(std_vec.begin() + 5, lst.begin(), lst.end());
		ft_vec.insert(ft_vec.begin() + 5, lst.begin(), lst.end());
		bool	two = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 2, "./test/vector/insert_range");
		print_result(one && two, std_vec.capacity() == ft_vec.capacity());
	}
	/*  ERASE */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;
		std::vector<int>::iterator	std_it;
		ft::vector<int>::iterator	ft_it;
		std::list<int>	std_lst;
		std::list<int>	ft_lst;

		for (int i = 0; i < 130; ++i) {
			std_vec.push_back(i);
			ft_vec.push_back(i);
		}
		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/erase_range");

		std_it = std_vec.erase(std_vec.begin() + 5, std_vec.end() - 8);
		ft_it = ft_vec.erase(ft_vec.begin() + 5, ft_vec.end() - 8);
		bool	two = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec) && *ft_it == *std_it;
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 2, "./test/vector/erase_range");

		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./test/vector/erase_range");
		print_result(one && two, std_vec.capacity() == ft_vec.capacity());
	}
	/*  SWAP */
	{
		std::cout << "\t|";
	}
	/*  CLEAR */
	{
		std::cout << "\t|";
	}
	std::cout << std::endl;
	std::cout << "Fill\t\t|";
	/*  ASSIGN */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec(130, 1);
		ft::vector<int>		ft_vec(130, 1);

		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/assing_fill");

		std_vec.assign(15, 2);
		ft_vec.assign(15, 2);
		bool	two = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 2, "./test/vector/assing_fill");
		print_result(one && two, std_vec.capacity() == ft_vec.capacity());
	}
	/*  PUSH_BACK */
	{
		std::cout << "\t|";
	}
	/*  POP_BACK */
	{
		std::cout << "\t|";
	}
	/*  INSERT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec(130, 1);
		ft::vector<int>		ft_vec(130, 1);

		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/insert_fill");

		std_vec.insert(std_vec.begin() + 5, 15, 2);
		ft_vec.insert(ft_vec.begin() + 5, 15, 2);
		bool	two = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 2, "./test/vector/insert_fill");
		print_result(one && two, std_vec.capacity() == ft_vec.capacity());
	}
	/*  ERASE */
	{
		std::cout << "\t|";
	}
	/*  SWAP */
	{
		std::cout << "\t|";
	}
	/*  CLEAR */
	{
		std::cout << "\t|";
	}
	std::cout << std::endl;
}