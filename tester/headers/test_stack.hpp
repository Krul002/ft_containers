#include "color.hpp"
#include "../../headers.hpp"
#include "../../new_iterator.hpp"
#include "../../stack.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <string>
#include <sys/stat.h>
#include <stack>

void	print_test(std::string name, std::string args, int num_args);
void	print_result(bool res, bool capacity);
void	methods();
void	operators2();

template <class T>
	bool	test_stack(std::stack<T> std_vec, ft::stack<T> ft_vec) {
		bool	ret = true;
		if (std_vec.size() != ft_vec.size())
			ret = false;
		for (;!std_vec.empty() && !ft_vec.empty() && ret;) {
			if (std_vec.top() != ft_vec.top())
				ret = false;
			std_vec.pop();
			ft_vec.pop();
		}
		return ret;
	}

template <class T>
	void	print_test_stack(std::stack<T> std_vec, ft::stack<T> ft_vec, std::ios_base::openmode	&mode, int test, std::string path) {
		std::fstream	fd(path, mode);
		mode = std::fstream::in | std::fstream::out | std::fstream::app;
		fd << "TEST" << test << ":" << std::endl;
		{
			fd << "\tSTD" << std::endl;
			fd << "\tSize: " << std_vec.size() << std::endl;
			fd << "\tContent: { ";
			while (!std_vec.empty()) {
				fd << std_vec.top();
				std_vec.pop();
				if (!std_vec.empty())
					fd << ", ";
			}
			fd << " }" << std::endl;
		}
		{
			fd << "\tFT" << std::endl;
			fd << "\tSize: " << ft_vec.size() << std::endl;
			fd << "\tContent: { ";
			while (!ft_vec.empty()) {
				fd << ft_vec.top();
				ft_vec.pop();
				if (!ft_vec.empty())
					fd << ", ";
			}
			fd << " }" << std::endl << std::endl;
		}
		fd.close();
	}

template <class T, class ListIterator>
	void	print_test_iterator(std::list<T> &std_it, std::list<T> &ft_it, std::ios_base::openmode	&mode, int test, std::string path) {
		std::fstream	fd(path, mode);
		mode = std::fstream::in | std::fstream::out | std::fstream::app;
		fd << "TEST" << test << ":" << std::endl;
		{
			fd << "\tSTD: { ";
			ListIterator	first = std_it.begin();
			ListIterator	last = std_it.end();
			while (first != last) {
				fd << std::boolalpha << *first;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl;
		}
		{
			fd << "\tFT: { ";
			ListIterator	first = ft_it.begin();
			ListIterator	last = ft_it.end();
			while (first != last) {
				fd << std::boolalpha << *first;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl << std::endl;
		}
		fd.close();
	}


template <class T>
	void	list_push(std::list<T> &std_lst, std::list<T> &ft_lst, const T &std, const T &ft) {
		std_lst.push_back(std);
		ft_lst.push_back(ft);
	}

template <class T>
	void	list_push(std::list<T> &std_lst, std::list<T> &ft_lst, T &std, T &ft) {
		std_lst.push_back(std);
		ft_lst.push_back(ft);
	}

template <class T, class ListIterator>
	void	test_push_back(std::stack<T> &std_vec, ft::stack<T> &ft_vec, std::list<T> lst) {
		ListIterator	first = lst.begin();
		ListIterator	last = lst.end();
		for (; first != last; ++first) {
			std_vec.push(*first);
			ft_vec.push(*first);
		}
	}

template <class T>
	void	test_push_back(std::stack<T> &std_vec, ft::stack<T> &ft_vec, T val, int dist) {
		for (int i = 0; i < dist; ++i) {
			std_vec.push(val);
			ft_vec.push(val);
		}
	}

template <class T>
	void	test_pop_back(std::stack<T> &std_vec, ft::stack<T> &ft_vec, int dist) {
		for (int i = 0; i < dist; ++i) {
			std_vec.pop();
			ft_vec.pop();
		}
	}

template <class T>
	void	test_insert(std::stack<T> &std_vec, ft::stack<T> &ft_vec, std::list<T> lst, T val, int dist, int type, int pos) {
		if (type == 1) {
			std_vec.insert(std_vec.begin() + pos, val);
		}
		else if (type == 2) {
			std_vec.insert(std_vec.begin() + pos, dist, val);
		}
		else {
			std_vec.insert(std_vec.begin() + pos, lst.begin(), lst.end());
		}
	}