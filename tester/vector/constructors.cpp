#include "../headers/test_vector.hpp"

void	constructors() {
	std::cout << "\t\t|";
	std::list<int>	lst;
	lst.push_back(87);
	lst.push_back(-12);
	lst.push_back(9765);
	lst.push_back(982);
	lst.push_back(0);
	lst.push_back(25);
	lst.push_back(-90);
	/*  DEFAULT  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;

		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/default_construct");
		print_result(one, true);
	}
	/*  FILL  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		bool	one;
		bool	two;
		bool	three;
		{
			std::vector<int>	std_vec(10, 5);
			ft::vector<int>		ft_vec(10, 5);

			one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
			print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/fill_construct");
		}
		{
			std::vector<int>	std_vec(100, 15);
			ft::vector<int>		ft_vec(100, 15);

			two = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
			print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 2, "./test/vector/fill_construct");
		}
		{
			std::vector<int>	std_vec(70, 1);
			ft::vector<int>		ft_vec(70, 1);

			three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
			print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./test/vector/fill_construct");
		}
		print_result(one && two && three, true);
	}
	/*  RANGE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec(lst.begin(), lst.end());
		ft::vector<int>		ft_vec(lst.begin(), lst.end());

		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/range_construct");
		print_result(one, true);
	}
	/*  COPY  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec_copy(lst.begin(), lst.end());
		ft::vector<int>		ft_vec_copy(lst.begin(), lst.end());
		std::vector<int>	std_vec(std_vec_copy);
		ft::vector<int>	ft_vec(ft_vec_copy);

		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/copy_construct");
		print_result(one, true);
	}
	/*  OPERATOR=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec_copy(lst.begin(), lst.end());
		ft::vector<int>		ft_vec_copy(lst.begin(), lst.end());
		std::vector<int>	std_vec;;
		ft::vector<int>	ft_vec;

		std_vec = std_vec_copy;
		ft_vec = ft_vec_copy;

		bool	one = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 1, "./test/vector/operator=");
		print_result(one, true);
	}
	std::cout << std::endl;
}