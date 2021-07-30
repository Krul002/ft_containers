#include "../headers/test_map.hpp"
#include <cstddef>
#include <utility>

void	capacity2() {
	std::cout << "\t\t|";
	/*  SIZE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec;
		ft::map<int, int>		ft_vec;
		std::list<std::pair<size_t, bool> >	std_lst;
		std::list<ft::pair<size_t, bool> >	ft_lst;

		bool	one = std_vec.size() == ft_vec.size();
		list_push<std::pair<size_t, bool>, ft::pair<size_t, bool> >(std_lst, ft_lst, std::make_pair(std_vec.size(), true), ft::make_pair(ft_vec.size(), true));
		print_test_iterator<std::pair<size_t, bool>, ft::pair<size_t, bool>, std::list<std::pair<size_t, bool> >::iterator, std::list<ft::pair<size_t, bool> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/size");

		std_vec.insert(std::pair<int, int>(10, 45));
		std_vec.insert(std::pair<int, int>(15, 35));
		std_vec.insert(std::pair<int, int>(8, -9));
		std_vec.insert(std::pair<int, int>(-9, 34));

		ft_vec.insert(ft::pair<int, int>(10, 45));
		ft_vec.insert(ft::pair<int, int>(15, 35));
		ft_vec.insert(ft::pair<int, int>(8, -9));
		ft_vec.insert(ft::pair<int, int>(-9, 34));
		bool	two = std_vec.size() == ft_vec.size();
		list_push<std::pair<size_t, bool>, ft::pair<size_t, bool> >(std_lst, ft_lst, std::make_pair(std_vec.size(), true), ft::make_pair(ft_vec.size(), true));
		print_test_iterator<std::pair<size_t, bool>, ft::pair<size_t, bool>, std::list<std::pair<size_t, bool> >::iterator, std::list<ft::pair<size_t, bool> >::iterator>(std_lst, ft_lst, mode, 2, "./test/map/size");

		std_vec.erase(-9);
		ft_vec.erase(-9);
		bool	three = std_vec.size() == ft_vec.size();
		list_push<std::pair<size_t, bool>, ft::pair<size_t, bool> >(std_lst, ft_lst, std::make_pair(std_vec.size(), true), ft::make_pair(ft_vec.size(), true));
		print_test_iterator<std::pair<size_t, bool>, ft::pair<size_t, bool>, std::list<std::pair<size_t, bool> >::iterator, std::list<ft::pair<size_t, bool> >::iterator>(std_lst, ft_lst, mode, 3, "./test/map/size");

		bool	four = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 4, "./test/map/size");
		print_result(one && two && three && four, true);
	}
	/*  MAX_SIZE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec;
		ft::map<int, int>		ft_vec;
		std::list<std::pair<size_t, bool> >	std_lst;
		std::list<ft::pair<size_t, bool> >	ft_lst;

		bool	one = std_vec.max_size() == ft_vec.max_size();
		list_push<std::pair<size_t, bool>, ft::pair<size_t, bool> >(std_lst, ft_lst, std::make_pair(std_vec.max_size(), true), ft::make_pair(ft_vec.max_size(), true));
		print_test_iterator<std::pair<size_t, bool>, ft::pair<size_t, bool>, std::list<std::pair<size_t, bool> >::iterator, std::list<ft::pair<size_t, bool> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/max_size");

		std_vec.insert(std::pair<int, int>(10, 45));
		std_vec.insert(std::pair<int, int>(15, 35));
		std_vec.insert(std::pair<int, int>(8, -9));
		std_vec.insert(std::pair<int, int>(-9, 34));

		ft_vec.insert(ft::pair<int, int>(10, 45));
		ft_vec.insert(ft::pair<int, int>(15, 35));
		ft_vec.insert(ft::pair<int, int>(8, -9));
		ft_vec.insert(ft::pair<int, int>(-9, 34));
		bool	two = std_vec.max_size() == ft_vec.max_size();
		list_push<std::pair<size_t, bool>, ft::pair<size_t, bool> >(std_lst, ft_lst, std::make_pair(std_vec.max_size(), true), ft::make_pair(ft_vec.max_size(), true));
		print_test_iterator<std::pair<size_t, bool>, ft::pair<size_t, bool>, std::list<std::pair<size_t, bool> >::iterator, std::list<ft::pair<size_t, bool> >::iterator>(std_lst, ft_lst, mode, 2, "./test/map/max_size");

		std_vec.erase(-9);
		ft_vec.erase(-9);
		bool	three = std_vec.max_size() == ft_vec.max_size();
		list_push<std::pair<size_t, bool>, ft::pair<size_t, bool> >(std_lst, ft_lst, std::make_pair(std_vec.max_size(), true), ft::make_pair(ft_vec.max_size(), true));
		print_test_iterator<std::pair<size_t, bool>, ft::pair<size_t, bool>, std::list<std::pair<size_t, bool> >::iterator, std::list<ft::pair<size_t, bool> >::iterator>(std_lst, ft_lst, mode, 3, "./test/map/max_size");

		bool	four = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 4, "./test/map/max_size");
		print_result(true, one && two && three && four);
	}
	/*  EMPTY  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec;
		ft::map<int, int>		ft_vec;
		std::list<std::pair<size_t, bool> >	std_lst;
		std::list<ft::pair<size_t, bool> >	ft_lst;

		bool	one = std_vec.empty() == ft_vec.empty();
		list_push<std::pair<size_t, bool>, ft::pair<size_t, bool> >(std_lst, ft_lst, std::make_pair(1, std_vec.empty()), ft::make_pair(1, ft_vec.empty()));
		print_test_iterator<std::pair<size_t, bool>, ft::pair<size_t, bool>, std::list<std::pair<size_t, bool> >::iterator, std::list<ft::pair<size_t, bool> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/empty");

		std_vec.insert(std::pair<int, int>(10, 45));
		std_vec.insert(std::pair<int, int>(15, 35));
		std_vec.insert(std::pair<int, int>(8, -9));
		std_vec.insert(std::pair<int, int>(-9, 34));

		ft_vec.insert(ft::pair<int, int>(10, 45));
		ft_vec.insert(ft::pair<int, int>(15, 35));
		ft_vec.insert(ft::pair<int, int>(8, -9));
		ft_vec.insert(ft::pair<int, int>(-9, 34));
		bool	two = std_vec.empty() == ft_vec.empty();
		list_push<std::pair<size_t, bool>, ft::pair<size_t, bool> >(std_lst, ft_lst, std::make_pair(1, std_vec.empty()), ft::make_pair(1, ft_vec.empty()));
		print_test_iterator<std::pair<size_t, bool>, ft::pair<size_t, bool>, std::list<std::pair<size_t, bool> >::iterator, std::list<ft::pair<size_t, bool> >::iterator>(std_lst, ft_lst, mode, 2, "./test/map/empty");

		std_vec.erase(-9);
		ft_vec.erase(-9);
		bool	three = std_vec.empty() == ft_vec.empty();
		list_push<std::pair<size_t, bool>, ft::pair<size_t, bool> >(std_lst, ft_lst, std::make_pair(std_vec.empty(), true), ft::make_pair(ft_vec.empty(), true));
		print_test_iterator<std::pair<size_t, bool>, ft::pair<size_t, bool>, std::list<std::pair<size_t, bool> >::iterator, std::list<ft::pair<size_t, bool> >::iterator>(std_lst, ft_lst, mode, 3, "./test/map/empty");

		bool	four = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 4, "./test/map/empty");
		print_result(one && two && three && four, true);
	}
	std::cout << std::endl;
}