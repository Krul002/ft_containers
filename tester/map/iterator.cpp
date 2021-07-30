#include "../headers/test_map.hpp"
#include <utility>

void	iterator2() {
	mkdir("./test/map/iterator", 0777);
	std::cout << "Standart:\t|";
	std::list<std::pair<int, int> >	lst;
	lst.push_back(std::pair<int, int>(10, 12));
	lst.push_back(std::pair<int, int>(99, 1300));
	lst.push_back(std::pair<int, int>(761, 987));
	lst.push_back(std::pair<int, int>(-19, 9));
	lst.insert(lst.end(), std::pair<int, int>(999, 999));
	lst.push_back(std::pair<int, int>(975, 992));
	lst.push_back(std::pair<int, int>(500, -87));

	/*  OPERATOR*  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>			std_vec;
		ft::map<int, int>				ft_vec;
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		test_push_back<int, std::pair<int, int>, std::list<std::pair<int, int> >::iterator>(std_vec, ft_vec, lst);
		std::map<int, int>::iterator	std_it = std_vec.begin();
		ft::map<int, int>::iterator	ft_it = ft_vec.begin();

		/*Test1*/
		bool	one = ((*ft_it).first == (*std_it).first && (*ft_it).second == (*std_it).second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/iterator/operator*");
		(*ft_it).second = 11;
		(*std_it).second = 11;

		/*Test2*/
		bool	two = ((*ft_it).first == (*std_it).first && (*ft_it).second == (*std_it).second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 2, "./test/map/iterator/operator*");


		bool	three = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 3, "./test/map/iterator/operator*");
		print_result(one && two && three, true);
	}
	/*  OPERATOR->  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>			std_vec;
		ft::map<int, int>				ft_vec;
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		test_push_back<int, std::pair<int, int>, std::list<std::pair<int, int> >::iterator>(std_vec, ft_vec, lst);
		std::map<int, int>::iterator	std_it = std_vec.begin();
		ft::map<int, int>::iterator	ft_it = ft_vec.begin();

		/*Test1*/
		bool	one = (ft_it->first == std_it->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/iterator/operator->");
		ft_it->second = 11;
		std_it->second = 11;

		/*Test2*/
		bool	two = (ft_it->first == std_it->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/iterator/operator->");

		print_result(one && two, true);
	}
	/*  OPERATOR++  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>			std_vec;
		ft::map<int, int>				ft_vec;
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		test_push_back<int, std::pair<int, int>, std::list<std::pair<int, int> >::iterator>(std_vec, ft_vec, lst);
		std::map<int, int>::iterator	std_it = std_vec.begin();
		ft::map<int, int>::iterator	ft_it = ft_vec.begin();

		/*Test1*/
		ft_it++;
		std_it++;
		bool	one = (ft_it->first == std_it->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/iterator/operator++");
		ft_it->second = 11;
		std_it->second = 11;

		/*Test2*/
		bool	two = (ft_it->first == std_it->first && (ft_it++)->second == (std_it++)->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(--std_it), *(--ft_it));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 2, "./test/map/iterator/operator++");

		bool	three = ((++ft_it)->first == (++std_it)->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 3, "./test/map/iterator/operator++");


		bool	four = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 4, "./test/map/iterator/operator++");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR--  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>			std_vec;
		ft::map<int, int>				ft_vec;
		std::list<std::pair<int, int> >				std_lst;
		std::list<ft::pair<int, int> >				ft_lst;
		test_push_back<int, std::pair<int, int>, std::list<std::pair<int, int> >::iterator>(std_vec, ft_vec, lst);
		std::map<int, int>::iterator	std_it = std_vec.end();
		ft::map<int, int>::iterator	ft_it = ft_vec.end();

		/*Test1*/
		ft_it--;
		std_it--;
		bool	one = (ft_it->first == std_it->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/iterator/operator--");
		ft_it->second = 11;
		std_it->second = 11;

		/*Test2*/
		bool	two = (ft_it->first == std_it->first && (ft_it--)->second == (std_it--)->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(++std_it), *(++ft_it));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 2, "./test/map/iterator/operator--");
		ft_it->second = 11;
		std_it->second = 11;

		bool	three = ((--ft_it)->first == (--std_it)->first && ft_it->second == std_it->second);
		list_push<std::pair<int, int>, ft::pair<int, int> >(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<std::pair<int, int>, ft::pair<int, int>, std::list<std::pair<int, int> >::iterator, std::list<ft::pair<int, int> >::iterator>(std_lst, ft_lst, mode, 3, "./test/map/iterator/operator--");
		ft_it->second = 11;
		std_it->second = 11;

		bool	four = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 4, "./test/map/iterator/operator--");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR==  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>			std_vec;
		ft::map<int, int>				ft_vec;
		std::list<std::pair<bool, bool> >				std_lst;
		std::list<ft::pair<bool, bool> >				ft_lst;
		test_push_back<int, std::pair<int, int>, std::list<std::pair<int, int> >::iterator>(std_vec, ft_vec, lst);
		std::map<int, int>::iterator	std_it = std_vec.begin();
		ft::map<int, int>::iterator	ft_it = ft_vec.begin();
		ft::pair<bool, bool>	ft_bool;
		std::pair<bool, bool>	std_bool;

		/*Test1*/
		ft_bool.first = ft_it == ft_vec.begin();
		ft_bool.second = ft_bool.first;
		std_bool.first = std_it == std_vec.begin();
		std_bool.second = std_bool.first;
		bool	one = (ft_bool.first == std_bool.first);
		list_push<std::pair<bool, bool>, ft::pair<bool, bool> >(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<std::pair<bool, bool>, ft::pair<bool, bool>, std::list<std::pair<bool, bool> >::iterator, std::list<ft::pair<bool, bool> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/iterator/operator==");

		/*Test2*/
		ft_it++;
		std_it++;
		ft_bool.first = ft_it == ft_vec.begin();
		ft_bool.second = ft_bool.first;
		std_bool.first = std_it == std_vec.begin();
		std_bool.second = std_bool.first;
		bool	two = (ft_bool.first == std_bool.first);
		list_push<std::pair<bool, bool>, ft::pair<bool, bool> >(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<std::pair<bool, bool>, ft::pair<bool, bool>, std::list<std::pair<bool, bool> >::iterator, std::list<ft::pair<bool, bool> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/iterator/operator==");

		bool	three = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 3, "./test/map/iterator/operator==");
		print_result(one && two && three, true);
	}
	/*  OPERATOR!=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::map<int, int>			std_vec;
		ft::map<int, int>				ft_vec;
		std::list<std::pair<bool, bool> >				std_lst;
		std::list<ft::pair<bool, bool> >				ft_lst;
		test_push_back<int, std::pair<int, int>, std::list<std::pair<int, int> >::iterator>(std_vec, ft_vec, lst);
		std::map<int, int>::iterator	std_it = std_vec.begin();
		ft::map<int, int>::iterator	ft_it = ft_vec.begin();
		ft::pair<bool, bool>	ft_bool;
		std::pair<bool, bool>	std_bool;

		/*Test1*/
		ft_bool.first = ft_it != ft_vec.begin();
		ft_bool.second = ft_bool.first;
		std_bool.first = std_it != std_vec.begin();
		std_bool.second = std_bool.first;
		bool	one = (ft_bool.first == std_bool.first);
		list_push<std::pair<bool, bool>, ft::pair<bool, bool> >(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<std::pair<bool, bool>, ft::pair<bool, bool>, std::list<std::pair<bool, bool> >::iterator, std::list<ft::pair<bool, bool> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/iterator/operator!=");

		/*Test2*/
		ft_it++;
		std_it++;
		ft_bool.first = ft_it != ft_vec.begin();
		ft_bool.second = ft_bool.first;
		std_bool.first = std_it != std_vec.begin();
		std_bool.second = std_bool.first;
		bool	two = (ft_bool.first == std_bool.first);
		list_push<std::pair<bool, bool>, ft::pair<bool, bool> >(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<std::pair<bool, bool>, ft::pair<bool, bool>, std::list<std::pair<bool, bool> >::iterator, std::list<ft::pair<bool, bool> >::iterator>(std_lst, ft_lst, mode, 1, "./test/map/iterator/operator!=");

		bool	three = test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec);
		print_test_map<int, std::map<int, int>::iterator, ft::map<int, int>::iterator>(std_vec, ft_vec, mode, 3, "./test/map/iterator/operator!=");
		print_result(one && two && three, true);
	}
	std::cout << std::endl;
}