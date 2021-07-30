#include "../headers/test_map.hpp"
#include <iostream>
#include <iterator>

void	constructors2() {
	std::cout << "\t\t|";
	// std::list<int>	lst;
	// lst.push_back(87);
	// lst.push_back(-12);
	// lst.push_back(9765);
	// lst.push_back(982);
	// lst.push_back(0);
	// lst.push_back(25);
	// lst.push_back(-90);
	// std::list<std::pair<int, int> >	lst;
	// lst.push_back(std::pair<int, int>(10, 12));
	// lst.push_back(std::pair<int, int>(99, 1300));
	// lst.push_back(std::pair<int, int>(761, 987));
	// lst.push_back(std::pair<int, int>(-19, 9));
	// lst.insert(lst.end(), std::pair<int, int>(999, 999));
	// lst.push_back(std::pair<int, int>(975, 992));
	// lst.push_back(std::pair<int, int>(500, -87));

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
	/*  DEFAULT  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec;
		ft::map<int, int>		ft_vec;

		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/default_construct");
		print_result(one, true);
	}
	/*  RANGE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());

		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/range_construct");
		print_result(one, true);
	}
	/*  COPY  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec_copy(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec_copy(lst_ft.begin(), lst_ft.end());
		std::map<int, int>	std_vec(std_vec_copy);
		ft::map<int, int>	ft_vec(ft_vec_copy);

		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/copy_construct");
		print_result(one, true);
	}
	/*  OPERATOR=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec_copy(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec_copy(lst_ft.begin(), lst_ft.end());
		std::map<int, int>	std_vec;
		ft::map<int, int>	ft_vec;

		std_vec = std_vec_copy;
		ft_vec = ft_vec_copy;

		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/operator=");
		print_result(one, true);
	}
	std::cout << std::endl;
}