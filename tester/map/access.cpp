#include "../headers/test_map.hpp"
#include <utility>

void	access2() {
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
	/*  OPERATOR[]  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		std::list<std::pair<int, int> >::iterator	std_it = lst_std.begin();
		std::list<ft::pair<int, int> >::iterator	ft_it = lst_ft.begin();

		bool	one = true;
		for (int i = 0; i < lst_std.size() && i < lst_ft.size() && one == true; ++i, ++std_it, ++ft_it) {
			one = std_vec[std_it->first] == ft_vec[ft_it->first];
			list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, std::make_pair(std_it->first, std_vec[std_it->first]), ft::make_pair(ft_it->first, ft_vec[ft_it->first]));
			print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, i + 1, "./test/map/operator[]");
		}
		print_result(one, true);
	}
	std::cout << std::endl;
}