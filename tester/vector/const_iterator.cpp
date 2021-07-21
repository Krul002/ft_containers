#include "../headers/test_vector.hpp"

void	const_iterator() {
	mkdir("./test/vector/const_iterator", 0777);
	std::cout << "Const:\t\t|";
	std::list<int>	lst;
	lst.push_back(10);
	lst.push_back(99);
	lst.push_back(761);
	lst.push_back(-19);
	lst.insert(lst.end(), 15, 999);
	lst.push_back(975);
	lst.push_back(500);

	/*  OPERATOR*  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();

		/*Test1*/
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator*");

		/*Test2*/
		bool	two = (*ft_it == *std_it);
		list_push(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator*");


		bool	three = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/vector/const_iterator/operator*");
		print_result(one && two && three, true);
	}
	/*  OPERATOR->  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<std::list<int> >			std_vec(1, lst);
		const ft::vector<std::list<int> >			ft_vec(1, lst);
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		std::vector<std::list<int> >::const_iterator	std_it = std_vec.begin();
		ft::vector<std::list<int> >::const_iterator	ft_it = ft_vec.begin();

		/*Test1*/
		bool	one = (*(ft_it->begin()) == *(std_it->begin()));
		list_push<int>(std_lst, ft_lst, *std_it->begin(), *ft_it->begin());
		print_test_iterator<int , std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator->");

		/*Test2*/
		bool	two = (*ft_it->begin() == *std_it->begin());
		list_push<int>(std_lst, ft_lst, *std_it->begin(), *ft_it->begin());
		print_test_iterator<int , std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator->");

		print_result(one && two, true);
	}
	/*  OPERATOR++  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();

		/*Test1*/
		ft_it++;
		std_it++;
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator++");

		/*Test2*/
		bool	two = (*ft_it++ == *std_it++);
		list_push(std_lst, ft_lst, *(--std_it), *(--ft_it));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator++");

		bool	three = (*(++ft_it) == *(++std_it));
		list_push(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 3, "./test/vector/const_iterator/operator++");


		bool	four = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 4, "./test/vector/const_iterator/operator++");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR--  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.end();
		ft::vector<int>::const_iterator	ft_it = ft_vec.end();

		/*Test1*/
		ft_it--;
		std_it--;
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator--");

		/*Test2*/
		bool	two = (*ft_it-- == *std_it--);
		list_push(std_lst, ft_lst, *(++std_it), *(++ft_it));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator--");

		bool	three = (*(--ft_it) == *(--std_it));
		list_push(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 3, "./test/vector/const_iterator/operator--");

		bool	four = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 4, "./test/vector/const_iterator/operator--");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR+=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();

		/*Test1*/
		ft_it += 2;
		std_it += 2;
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator+=");

		/*Test2*/
		ft_it += 5;
		std_it += 5;
		bool	two = (*ft_it == *std_it);
		list_push(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator+=");


		bool	three = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/vector/const_iterator/operator+=");
		print_result(one && two && three, true);
	}
	/*  OPERATOR-=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.end();
		ft::vector<int>::const_iterator	ft_it = ft_vec.end();

		/*Test1*/
		ft_it -= 2;
		std_it -= 2;
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator-=");

		/*Test2*/
		ft_it -= 5;
		std_it -= 5;
		bool	two = (*ft_it == *std_it);
		list_push(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator-=");


		bool	three = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/vector/const_iterator/operator-=");
		print_result(one && two && three, true);
	}
	/*  OPERATOR[]  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();

		/*Test1*/
		bool	one = (ft_it[0] == std_it[0] && ft_it[6] == std_it[6]);
		list_push<int>(std_lst, ft_lst, std_it[0], ft_it[0]);
		list_push<int>(std_lst, ft_lst, std_it[6], ft_it[6]);
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator[]");

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		bool	two = (ft_it[0] == std_it[0] && ft_it[6] == std_it[6]);
		list_push<int>(std_lst, ft_lst, std_it[0], ft_it[0]);
		list_push<int>(std_lst, ft_lst, std_it[6], ft_it[6]);
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator[]");

		bool	three = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/vector/const_iterator/operator[]");
		print_result(one && two && three, true);
	}
	/*  OPERATOR==  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it == ft_vec.begin();
		std_bool = std_it == std_vec.begin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator==");

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it == ft_vec.begin();
		std_bool = std_it == std_vec.begin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator==");

		bool	three = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/vector/const_iterator/operator==");
		print_result(one && two && three, true);
	}
	/*  OPERATOR!=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it != ft_vec.begin();
		std_bool = std_it != std_vec.begin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator!=");

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it != ft_vec.begin();
		std_bool = std_it != std_vec.begin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator!=");

		bool	three = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/vector/const_iterator/operator!=");
		print_result(one && two && three, true);
	}
	/*  OPERATOR<  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it < ft_vec.begin();
		std_bool = std_it < std_vec.begin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator<");

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it < ft_vec.end();
		std_bool = std_it < std_vec.end();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator<");

		bool	three = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/vector/const_iterator/operator<");
		print_result(one && two && three, true);
	}
	/*  OPERATOR<=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it <= ft_vec.begin();
		std_bool = std_it <= std_vec.begin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator<=");

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it <= ft_vec.begin();
		std_bool = std_it <= std_vec.begin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator<=");

		/*Test3*/
		ft_it += 2;
		std_it += 2;
		ft_bool = ft_it <= ft_vec.end();
		std_bool = std_it <= std_vec.end();
		bool	three = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 3, "./test/vector/const_iterator/operator<=");

		bool	four = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 4, "./test/vector/const_iterator/operator<=");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR>  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it > ft_vec.begin();
		std_bool = std_it > std_vec.begin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator>");

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it > ft_vec.begin();
		std_bool = std_it > std_vec.begin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator>");

		bool	three = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 3, "./test/vector/const_iterator/operator>");
		print_result(one && two && three, true);
	}
	/*  OPERATOR>=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it >= ft_vec.begin();
		std_bool = std_it >= std_vec.begin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator>=");

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it >= ft_vec.begin();
		std_bool = std_it >= std_vec.begin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator>=");

		/*Test3*/
		ft_it += 2;
		std_it += 2;
		ft_bool = ft_it >= ft_vec.end();
		std_bool = std_it >= std_vec.end();
		bool	three = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::const_iterator>(std_lst, ft_lst, mode, 3, "./test/vector/const_iterator/operator>=");

		bool	four = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 4, "./test/vector/const_iterator/operator>=");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR+  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.begin();
		ft::vector<int>::const_iterator	ft_it = ft_vec.begin();

		/*Test1*/
		bool	one = (*(ft_it + 5) == *(std_it + 5));
		list_push<int>(std_lst, ft_lst, *(std_it + 5), *(ft_it + 5));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator+");

		/*Test2*/
		bool	two = (*(ft_it + 5) == *(std_it + 5));
		list_push(std_lst, ft_lst, *(std_it + 5), *(ft_it + 5));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator+");

		/*Test3*/
		bool	three = (*(ft_it + 18) == *(std_it + 18));
		list_push(std_lst, ft_lst, *(std_it + 18), *(ft_it + 18));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 3, "./test/vector/const_iterator/operator+");

		/*Test4*/
		bool	four = (*(ft_it + 11) == *(std_it + 11));
		list_push(std_lst, ft_lst, *(std_it + 11), *(ft_it + 11));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 4, "./test/vector/const_iterator/operator+");

		bool	five = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 5, "./test/vector/const_iterator/operator+");
		print_result(one && two && three && four && five, true);
	}
	/*  OPERATOR-  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>			std_vec(lst.begin(), lst.end());
		const ft::vector<int>				ft_vec(lst.begin(), lst.end());
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		std::vector<int>::const_iterator	std_it = std_vec.end();
		ft::vector<int>::const_iterator	ft_it = ft_vec.end();

		/*Test1*/
		bool	one = (*(ft_it - 5) == *(std_it - 5));
		list_push<int>(std_lst, ft_lst, *(std_it - 5), *(ft_it - 5));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 1, "./test/vector/const_iterator/operator-");

		/*Test2*/
		bool	two = (*(ft_it - 5) == *(std_it - 5));
		list_push(std_lst, ft_lst, *(std_it - 5), *(ft_it - 5));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 2, "./test/vector/const_iterator/operator-");

		/*Test3*/
		bool	three = (*(ft_it - 18) == *(std_it - 18));
		list_push(std_lst, ft_lst, *(std_it - 18), *(ft_it - 18));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 3, "./test/vector/const_iterator/operator-");

		/*Test4*/
		bool	four = (*(ft_it - 11) == *(std_it - 11));
		list_push(std_lst, ft_lst, *(std_it - 11), *(ft_it - 11));
		print_test_iterator<int, std::list<int>::const_iterator>(std_lst, ft_lst, mode, 4, "./test/vector/const_iterator/operator-");

		bool	five = test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::const_iterator, ft::vector<int>::const_iterator>(std_vec, ft_vec, mode, 5, "./test/vector/const_iterator/operator-");
		print_result(one && two && three && four && five, true);
	}
	std::cout << std::endl;
}