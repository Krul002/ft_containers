#include "../headers/test_map.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>
#include <utility>

void	operations() {
	std::cout << "\t\t|";
	std::list<std::pair<int, int> >	lst_std;
	lst_std.push_back(std::pair<int, int>(10, 12));
	lst_std.push_back(std::pair<int, int>(99, 1300));
	lst_std.push_back(std::pair<int, int>(761, 987));
	lst_std.push_back(std::pair<int, int>(-19, 9));
	lst_std.insert(lst_std.end(), std::pair<int, int>(999, 999));
	lst_std.push_back(std::pair<int, int>(975, 992));
	lst_std.push_back(std::pair<int, int>(500, -87));

	std::list<ft::pair<int, int> >	lst_ft;
	lst_ft.push_back(ft::pair<int, int>(10, 12));
	lst_ft.push_back(ft::pair<int, int>(99, 1300));
	lst_ft.push_back(ft::pair<int, int>(761, 987));
	lst_ft.push_back(ft::pair<int, int>(-19, 9));
	lst_ft.insert(lst_ft.end(), ft::pair<int, int>(999, 999));
	lst_ft.push_back(ft::pair<int, int>(975, 992));
	lst_ft.push_back(ft::pair<int, int>(500, -87));
	/*  FIND  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		std::list<std::pair<int, int> >::iterator	std_it = lst_std.begin();
		std::list<ft::pair<int, int> >::iterator	ft_it = lst_ft.begin();

		bool	one = true;
		for (size_t i = 0; std_it != lst_std.end() && ft_it != lst_ft.end() && one; ++i, ++std_it, ++ft_it) {
			std::map<int, int>::iterator it_std = std_vec.find(std_it->first);
			ft::map<int, int>::iterator it_ft = ft_vec.find(ft_it->first);
			one = it_std->first == it_ft->first && it_std->second == it_ft->second;
			list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *it_std, *it_ft);
			print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, i + 1, "./test/map/find");
		}
		print_result(one, true);
	}
	/*  COUNT  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, size_t> >				std_lst;
		std::list<ft::pair<int, size_t> >				ft_lst;
		std::list<std::pair<int, int> >::iterator	std_it = lst_std.begin();
		std::list<ft::pair<int, int> >::iterator	ft_it = lst_ft.begin();

		bool	one = true;
		size_t i = 0;
		for (; std_it != lst_std.end() && ft_it != lst_ft.end() && one; ++i, ++std_it, ++ft_it) {
			size_t	std_c = std_vec.count(std_it->first);
			size_t	ft_c = ft_vec.count(ft_it->first);
			one = std_c == ft_c;
			list_push<std::pair<int, size_t>, ft::pair<int, size_t> >(std_lst, ft_lst, std::make_pair(std_it->first, std_c), ft::make_pair(ft_it->first, ft_c));
			print_test_iterator<std::pair<int, size_t>, ft::pair<int, size_t>, std::list<std::pair<int, size_t> >::iterator, std::list<ft::pair<int, size_t> >::iterator>(std_lst, ft_lst, mode, i + 1, "./test/map/count");
		}
		size_t	std_c = std_vec.count(900177);
		size_t	ft_c = ft_vec.count(900177);
		one = one && std_c == ft_c;
		list_push<std::pair<int, size_t>, ft::pair<int, size_t> >(std_lst, ft_lst, std::make_pair(900177, std_c), ft::make_pair(900177, ft_c));
		print_test_iterator<std::pair<int, size_t>, ft::pair<int, size_t>, std::list<std::pair<int, size_t> >::iterator, std::list<ft::pair<int, size_t> >::iterator>(std_lst, ft_lst, mode, i + 1, "./test/map/count");
		print_result(one, true);
	}
	/*  LOWER_BOUND  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;

		std::map<int, int>::iterator it_std = std_vec.lower_bound(16);
		ft::map<int, int>::iterator it_ft = ft_vec.lower_bound(16);
		bool	one = it_std->first == it_ft->first && it_std->second == it_ft->second;
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *it_std, *it_ft);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/lower_bound");

		it_std = std_vec.lower_bound(99);
		it_ft = ft_vec.lower_bound(99);
		one = one && it_std->first == it_ft->first && it_std->second == it_ft->second;
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *it_std, *it_ft);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 2, "./test/map/lower_bound");
		
		it_std = std_vec.lower_bound(-100);
		it_ft = ft_vec.lower_bound(-100);
		one = one && it_std->first == it_ft->first && it_std->second == it_ft->second;
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *it_std, *it_ft);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 3, "./test/map/lower_bound");
		
		it_std = std_vec.lower_bound(87);
		it_ft = ft_vec.lower_bound(87);
		one = one && it_std->first == it_ft->first && it_std->second == it_ft->second;
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *it_std, *it_ft);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 4, "./test/map/lower_bound");
		print_result(one, true);
	}
	/*  UPPER_BOUND  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;

		std::map<int, int>::iterator it_std = std_vec.upper_bound(16);
		ft::map<int, int>::iterator it_ft = ft_vec.upper_bound(16);
		bool	one = it_std->first == it_ft->first && it_std->second == it_ft->second;
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *it_std, *it_ft);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/upper_bound");

		it_std = std_vec.upper_bound(99);
		it_ft = ft_vec.upper_bound(99);
		one = one && it_std->first == it_ft->first && it_std->second == it_ft->second;
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *it_std, *it_ft);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 2, "./test/map/upper_bound");
		
		it_std = std_vec.upper_bound(-100);
		it_ft = ft_vec.upper_bound(-100);
		one = one && it_std->first == it_ft->first && it_std->second == it_ft->second;
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *it_std, *it_ft);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 3, "./test/map/upper_bound");
		
		it_std = std_vec.upper_bound(87);
		it_ft = ft_vec.upper_bound(87);
		one = one && it_std->first == it_ft->first && it_std->second == it_ft->second;
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *it_std, *it_ft);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 4, "./test/map/upper_bound");
		print_result(one, true);
	}
	/*  EQUAL_RANGE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator>	std_eq;
		ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator>	ft_eq;

		std_eq = std_vec.equal_range(99);
		ft_eq = ft_vec.equal_range(99);
		bool	one = std_eq.first->first == ft_eq.first->first && std_eq.first->second == ft_eq.first->second && std_eq.second->first == ft_eq.second->first && std_eq.second->second == ft_eq.second->second;
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(std_eq.first), *(ft_eq.first));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/equal_range");
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(std_eq.second), *(ft_eq.second));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/equal_range");
		print_result(one, true);
	}
	std::cout << std::endl;
}