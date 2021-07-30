#include "../headers/test_map.hpp"
#include <iostream>
#include <ostream>
#include <utility>

void	observers() {
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
	/*  KEY_COMP  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, bool> >				std_lst;
		std::list<ft::pair<int, bool> >				ft_lst;
		std::map<int, int>::key_compare		std_comp = std_vec.key_comp();
		ft::map<int, int>::key_compare		ft_comp = ft_vec.key_comp();
		std::list<std::pair<int, int> >::iterator	std_it = lst_std.begin();
		std::list<ft::pair<int, int> >::iterator	ft_it = lst_ft.begin();

		bool	one = true;
		for (int i = 0; std_it != lst_std.end() && ft_it != lst_ft.end() && one == true; ++i, ++ft_it, ++std_it) {
			one = std_comp(std_it->first, std_vec.rbegin()->first) == ft_comp(ft_it->first, ft_vec.rbegin()->first);
			list_push<std::pair<int, bool>, ft::pair<int, bool> >(std_lst, ft_lst, std::make_pair(std_it->first, std_comp(std_it->first, std_vec.rbegin()->first)), ft::make_pair(ft_it->first, ft_comp(ft_it->first, ft_vec.rbegin()->first)));
			print_test_iterator<std::pair<int, bool>, ft::pair<int, bool>, std::list<std::pair<int, bool> >::iterator, std::list<ft::pair<int, bool> >::iterator>(std_lst, ft_lst, mode, i + 1, "./test/map/key_comp");
		}
		print_result(one, true);
	}
	/*  VALUE_COMP  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, bool> >				std_lst;
		std::list<ft::pair<int, bool> >				ft_lst;
		std::map<int, int>::value_compare		std_comp = std_vec.value_comp();
		ft::map<int, int>::value_compare		ft_comp = ft_vec.value_comp();
		std::list<std::pair<int, int> >::iterator	std_it = lst_std.begin();
		std::list<ft::pair<int, int> >::iterator	ft_it = lst_ft.begin();

		bool	one = true;
		for (int i = 0; std_it != lst_std.end() && ft_it != lst_ft.end() && one == true; ++i, ++ft_it, ++std_it) {
			one = std_comp(*std_it, *std_vec.rbegin()) == ft_comp(*ft_it, *ft_vec.rbegin());
			list_push<std::pair<int, bool>, ft::pair<int, bool> >(std_lst, ft_lst, std::make_pair(std_it->first, std_comp(*std_it, *std_vec.rbegin())), ft::make_pair(ft_it->first, ft_comp(*ft_it, *ft_vec.rbegin())));
			print_test_iterator<std::pair<int, bool>, ft::pair<int, bool>, std::list<std::pair<int, bool> >::iterator, std::list<ft::pair<int, bool> >::iterator>(std_lst, ft_lst, mode, i + 1, "./test/map/value_comp");
		}
		print_result(one, true);
	}
	std::cout << std::endl;
}