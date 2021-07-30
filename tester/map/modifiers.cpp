#include "../headers/test_map.hpp"
#include <ios>
#include <iostream>
#include <iterator>

void	modifiers2() {
	std::cout << "Default\t\t|";
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
		std::map<int, int>	std_vec1(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec1(lst_ft.begin(), lst_ft.end());
		lst_std.pop_back();
		lst_std.pop_back();
		lst_ft.pop_back();
		lst_ft.pop_back();
		std::map<int, int>	std_vec2(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec2(lst_ft.begin(), lst_ft.end());
		lst_std.push_back(std::pair<int, int>(975, 992));
		lst_std.push_back(std::pair<int, int>(500, -87));
		lst_ft.push_back(ft::pair<int, int>(975, 992));
		lst_ft.push_back(ft::pair<int, int>(500, -87));

		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec1, ft_vec1);
		one = one && test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec2, ft_vec2);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec1, ft_vec1, mode, 1, "./test/map/swap");
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec2, ft_vec2, mode, 2, "./test/map/swap");

		std_vec1.swap(std_vec2);
		ft_vec1.swap(ft_vec2);

		bool	two = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec1, ft_vec1);
		two = two && test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec2, ft_vec2);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec1, ft_vec1, mode, 1, "./test/map/swap");
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec2, ft_vec2, mode, 2, "./test/map/swap");
		print_result(one && two, true);
	}
	/*  CLEAR */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());

		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/clear");

		std_vec.clear();
		ft_vec.clear();

		bool	two = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 2, "./test/map/clear");
		print_result(one && two, true);
	}
	std::cout << std::endl;
	std::cout << "Single\t\t|";
	/*  INSERT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec;
		ft::map<int, int>		ft_vec;
		std::list<std::pair<int, int> >::iterator	it_std = lst_std.begin();
		std::list<ft::pair<int, int> >::iterator	it_ft = lst_ft.begin();

		std_vec.insert(*it_std);
		ft_vec.insert(*it_ft);
		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/insert_single");

		for (; it_ft != lst_ft.end() && it_std != lst_std.end(); ++it_ft, ++it_std) {
			std_vec.insert(*it_std);
			ft_vec.insert(*it_ft);
		}
		bool	two = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 2, "./test/map/insert_single");
		print_result(one && two, true);
	}
	/*  ERASE */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >::iterator	it_std = lst_std.begin();
		std::list<ft::pair<int, int> >::iterator	it_ft = lst_ft.begin();

		std_vec.erase(it_std->first);
		ft_vec.erase(it_ft->first);
		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/erase_single");

		++it_std;
		++it_std;
		++it_ft;
		++it_ft;
		for (; it_ft != lst_ft.end() && it_std != lst_std.end(); ++it_ft, ++it_std) {
			std_vec.erase(it_std->first);
			ft_vec.erase(it_ft->first);
		}
		bool	two = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 2, "./test/map/erase_single");
		print_result(one && two, true);
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
	/*  INSERT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec;
		ft::map<int, int>		ft_vec;
		std::list<std::pair<int, int> >::iterator	it_std = lst_std.begin();
		std::list<ft::pair<int, int> >::iterator	it_ft = lst_ft.begin();

		++it_std;
		++it_std;
		++it_ft;
		++it_ft;
		std_vec.insert(lst_std.begin(), it_std);
		ft_vec.insert(lst_ft.begin(), it_ft);
		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/insert_range");
			
		std_vec.insert(lst_std.begin(), lst_std.end());
		ft_vec.insert(lst_ft.begin(), lst_ft.end());
		bool	two = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 2, "./test/map/insert_range");
		print_result(one && two, true);
	}
	/*  ERASE */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::map<int, int>::iterator	it_std = std_vec.begin();
		ft::map<int, int>::iterator	it_ft = ft_vec.begin();

		++it_std;
		++it_std;
		++it_ft;
		++it_ft;
		std_vec.erase(std_vec.begin(), it_std);
		ft_vec.erase(ft_vec.begin(), it_ft);
		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/erase_range");
			
		std_vec.erase(std_vec.begin(), std_vec.end());
		ft_vec.erase(ft_vec.begin(), ft_vec.end());
		bool	two = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 2, "./test/map/erase_range");
		print_result(one && two, true);
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
	std::cout << "Hint\t\t|";
	/*  INSERT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec;
		ft::map<int, int>		ft_vec;
		std::list<std::pair<int, int> >::iterator	it_std = lst_std.begin();
		std::list<ft::pair<int, int> >::iterator	it_ft = lst_ft.begin();
		std::map<int, int>::iterator	std_it = std_vec.begin();
		ft::map<int, int>::iterator	ft_it = ft_vec.begin();

		std_vec.insert(std_it, *it_std);
		ft_vec.insert(ft_it, *it_ft);
		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/insert_hint");

		for (; it_ft != lst_ft.end() && it_std != lst_std.end(); ++it_ft, ++it_std, ++ft_it, ++std_it) {
			std_vec.insert(std_it, *it_std);
			ft_vec.insert(ft_it, *it_ft);
		}
		bool	two = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 2, "./test/map/insert_hint");
		print_result(one && two, true);
	}
	/*  ERASE */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>	std_vec(lst_std.begin(), lst_std.end());
		ft::map<int, int>		ft_vec(lst_ft.begin(), lst_ft.end());
		std::map<int, int>::iterator	it_std = std_vec.begin();
		ft::map<int, int>::iterator	it_ft = ft_vec.begin();

		std_vec.erase(it_std++);
		ft_vec.erase(it_ft++);
		bool	one = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 1, "./test/map/erase_hint");

		++it_std;
		++it_std;
		++it_ft;
		++it_ft;
		std_vec.erase(it_std);
		ft_vec.erase(it_ft);
		bool	two = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 2, "./test/map/erase_hint");
		print_result(one && two, true);
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