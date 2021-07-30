#include "../headers/test_map.hpp"

void	const_reverse_iterator2() {
	mkdir("./test/map/const_reverse_iterator", 0777);
	std::cout << "Const_Reverse:\t|";
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

	/*  OPERATOR*  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::map<int, int>			std_vec(lst_std.begin(), lst_std.end());
		const ft::map<int, int>				ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		std::map<int, int>::const_reverse_iterator	std_it = std_vec.rbegin();
		ft::map<int, int>::const_reverse_iterator	ft_it = ft_vec.rbegin();

		/*Test1*/
		bool	one = ((*ft_it).first == (*std_it).first && (*ft_it).second == (*std_it).second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 1, "./test/map/const_reverse_iterator/operator*");

		/*Test2*/
		bool	two = ((*ft_it).first == (*std_it).first && (*ft_it).second == (*std_it).second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 2, "./test/map/const_reverse_iterator/operator*");


		bool	three = test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/map/const_reverse_iterator/operator*");
		print_result(one && two && three, true);
	}
	/*  OPERATOR->  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::map<int, int>			std_vec(lst_std.begin(), lst_std.end());
		const ft::map<int, int>				ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		std::map<int, int>::const_reverse_iterator	std_it = std_vec.rbegin();
		ft::map<int, int>::const_reverse_iterator	ft_it = ft_vec.rbegin();

		/*Test1*/
		bool	one = (ft_it->first == std_it->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 1, "./test/map/const_reverse_iterator/operator->");

		/*Test2*/
		bool	two = (ft_it->first == std_it->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 1, "./test/map/const_reverse_iterator/operator->");

		print_result(one && two, true);
	}
	/*  OPERATOR++  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::map<int, int>			std_vec(lst_std.begin(), lst_std.end());
		const ft::map<int, int>				ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		std::map<int, int>::const_reverse_iterator	std_it = std_vec.rbegin();
		ft::map<int, int>::const_reverse_iterator	ft_it = ft_vec.rbegin();

		/*Test1*/
		ft_it++;
		std_it++;
		bool	one = (ft_it->first == std_it->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 1, "./test/map/const_reverse_iterator/operator++");

		/*Test2*/
		bool	two = (ft_it->first == std_it->first && (ft_it++)->second == (std_it++)->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(--std_it), *(--ft_it));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 2, "./test/map/const_reverse_iterator/operator++");

		bool	three = ((++ft_it)->first == (++std_it)->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 3, "./test/map/const_reverse_iterator/operator++");


		bool	four = test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec, mode, 4, "./test/map/const_reverse_iterator/operator++");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR--  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::map<int, int>			std_vec(lst_std.begin(), lst_std.end());
		const ft::map<int, int>				ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		std::map<int, int>::const_reverse_iterator	std_it = std_vec.rend();
		ft::map<int, int>::const_reverse_iterator	ft_it = ft_vec.rend();

		/*Test1*/
		ft_it--;
		std_it--;
		bool	one = (ft_it->first == std_it->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 1, "./test/map/const_reverse_iterator/operator--");

		/*Test2*/
		bool	two = (ft_it->first == std_it->first && (ft_it--)->second == (std_it--)->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(++std_it), *(++ft_it));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 2, "./test/map/const_reverse_iterator/operator--");

		bool	three = ((--ft_it)->first == (--std_it)->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::const_iterator, std::list<ft::pair<int, int> >::const_iterator>(std_lst, ft_lst, mode, 3, "./test/map/const_reverse_iterator/operator--");

		bool	four = test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec, mode, 4, "./test/map/const_reverse_iterator/operator--");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR==  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::map<int, int>			std_vec(lst_std.begin(), lst_std.end());
		const ft::map<int, int>				ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<bool, bool> >				std_lst;
		std::list<ft::pair<bool, bool> >				ft_lst;
		std::map<int, int>::const_reverse_iterator	std_it = std_vec.rbegin();
		ft::map<int, int>::const_reverse_iterator	ft_it = ft_vec.rbegin();
		ft::pair<bool, bool>	ft_bool;
		std::pair<bool, bool>	std_bool;

		/*Test1*/
		ft_bool.first = ft_it == ft_vec.rbegin();
		ft_bool.second = ft_bool.first;
		std_bool.first = std_it == std_vec.rbegin();
		std_bool.second = std_bool.first;
		bool	one = (ft_bool.first == std_bool.first);
		list_push<std::pair<bool, bool>, ft::pair<bool, bool> >(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<std::pair<bool, bool>, ft::pair<bool, bool>, std::list<std::pair<bool, bool> >::const_iterator, std::list<ft::pair<bool, bool> >::const_iterator>(std_lst, ft_lst, mode, 1, "./test/map/const_reverse_iterator/operator==");

		/*Test2*/
		ft_it++;
		std_it++;
		ft_bool.first = ft_it == ft_vec.rbegin();
		ft_bool.second = ft_bool.first;
		std_bool.first = std_it == std_vec.rbegin();
		std_bool.second = std_bool.first;
		bool	two = (ft_bool.first == std_bool.first);
		list_push<std::pair<bool, bool>, ft::pair<bool, bool> >(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<std::pair<bool, bool>, ft::pair<bool, bool>, std::list<std::pair<bool, bool> >::const_iterator, std::list<ft::pair<bool, bool> >::const_iterator>(std_lst, ft_lst, mode, 1, "./test/map/const_reverse_iterator/operator==");

		bool	three = test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/map/const_reverse_iterator/operator==");
		print_result(one && two && three, true);
	}
	/*  OPERATOR!=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::map<int, int>			std_vec(lst_std.begin(), lst_std.end());
		const ft::map<int, int>				ft_vec(lst_ft.begin(), lst_ft.end());
		std::list<std::pair<bool, bool> >				std_lst;
		std::list<ft::pair<bool, bool> >				ft_lst;
		std::map<int, int>::const_reverse_iterator	std_it = std_vec.rbegin();
		ft::map<int, int>::const_reverse_iterator	ft_it = ft_vec.rbegin();
		ft::pair<bool, bool>	ft_bool;
		std::pair<bool, bool>	std_bool;

		/*Test1*/
		ft_bool.first = ft_it != ft_vec.rbegin();
		ft_bool.second = ft_bool.first;
		std_bool.first = std_it != std_vec.rbegin();
		std_bool.second = std_bool.first;
		bool	one = (ft_bool.first == std_bool.first);
		list_push<std::pair<bool, bool>, ft::pair<bool, bool> >(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<std::pair<bool, bool>, ft::pair<bool, bool>, std::list<std::pair<bool, bool> >::const_iterator, std::list<ft::pair<bool, bool> >::const_iterator>(std_lst, ft_lst, mode, 1, "./test/map/const_reverse_iterator/operator!=");

		/*Test2*/
		ft_it++;
		std_it++;
		ft_bool.first = ft_it != ft_vec.rbegin();
		ft_bool.second = ft_bool.first;
		std_bool.first = std_it != std_vec.rbegin();
		std_bool.second = std_bool.first;
		bool	two = (ft_bool.first == std_bool.first);
		list_push<std::pair<bool, bool>, ft::pair<bool, bool> >(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<std::pair<bool, bool>, ft::pair<bool, bool>, std::list<std::pair<bool, bool> >::const_iterator, std::list<ft::pair<bool, bool> >::const_iterator>(std_lst, ft_lst, mode, 1, "./test/map/const_reverse_iterator/operator!=");

		bool	three = test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::const_iterator, ft::map<int, int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/map/const_reverse_iterator/operator!=");
		print_result(one && two && three, true);
	}
	std::cout << std::endl;
}