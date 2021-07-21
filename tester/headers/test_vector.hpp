#include "color.hpp"
#include "../../headers.hpp"
#include "../../new_iterator.hpp"
#include "../../vector.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <string>
#include <sys/stat.h>
#include <vector>

void	print_test(std::string name, std::string args, int num_args);
void	print_result(bool res, bool capacity);
void	iterator();
void	const_iterator();
void	reverse_iterator();
void	const_reverse_iterator();
void	constructors();
void	capacity();
void	access();
void	modifiers();
void	operators();

template <class T, class Iterator1, class Iterator2>
	bool	test_vector(std::vector<T> &std_vec, ft::vector<T> &ft_vec) {
		bool	ret = true;
		Iterator1	std_first = std_vec.begin();
		Iterator2	ft_first = ft_vec.begin();
		Iterator1	std_last = std_vec.end();
		Iterator2	ft_last = ft_vec.end();
		if (std_vec.size() != ft_vec.size() || std_vec.max_size() != ft_vec.max_size())
			ret = false;
		for (; ret == true && std_first != std_last && ft_first != ft_last; ++std_first, ++ft_first) {
			if (*std_first != *ft_first)
				ret = false;
		}
		return ret;
	}

template <class T, class Iterator1, class Iterator2>
	bool	test_vector(const std::vector<T> &std_vec, const ft::vector<T> &ft_vec) {
		bool	ret = true;
		Iterator1	std_first = std_vec.begin();
		Iterator2	ft_first = ft_vec.begin();
		Iterator1	std_last = std_vec.end();
		Iterator2	ft_last = ft_vec.end();
		if (std_vec.size() != ft_vec.size() || std_vec.max_size() != ft_vec.max_size())
			ret = false;
		for (; ret == true && std_first != std_last && ft_first != ft_last; ++std_first, ++ft_first) {
			if (*std_first != *ft_first)
				ret = false;
		}
		return ret;
	}

template <class T, class Iterator1, class Iterator2>
	void	print_test_vector(std::vector<T> &std_vec, ft::vector<T> &ft_vec, std::ios_base::openmode	&mode, int test, std::string path) {
		std::fstream	fd(path, mode);
		mode = std::fstream::in | std::fstream::out | std::fstream::app;
		fd << "TEST" << test << ":" << std::endl;
		{
			fd << "\tSTD" << std::endl;
			fd << "\tSize: " << std_vec.size() << std::endl;
			fd << "\tCapacity: " << std_vec.capacity() << std::endl;
			fd << "\tMax_Size: " << std_vec.max_size() << std::endl;
			fd << "\tContent: { ";
			Iterator1	first = std_vec.begin();
			Iterator1	last = std_vec.end();
			while (first != last) {
				fd << *first;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl;
		}
		{
			fd << "\tFT" << std::endl;
			fd << "\tSize: " << ft_vec.size() << std::endl;
			fd << "\tCapacity: " << ft_vec.capacity() << std::endl;
			fd << "\tMax_Size: " << ft_vec.max_size() << std::endl;
			fd << "\tContent: { ";
			Iterator2	first = ft_vec.begin();
			Iterator2	last = ft_vec.end();
			while (first != last) {
				fd << *first;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl << std::endl;
		}
		fd.close();
	}

template <class T, class Iterator1, class Iterator2>
	void	print_test_vector(const std::vector<T> &std_vec, const ft::vector<T> &ft_vec, std::ios_base::openmode	&mode, int test, std::string path) {
		std::fstream	fd(path, mode);
		mode = std::fstream::in | std::fstream::out | std::fstream::app;
		fd << "TEST" << test << ":" << std::endl;
		{
			fd << "\tSTD" << std::endl;
			fd << "\tSize: " << std_vec.size() << std::endl;
			fd << "\tCapacity: " << std_vec.capacity() << std::endl;
			fd << "\tMax_Size: " << std_vec.max_size() << std::endl;
			fd << "\tContent: { ";
			Iterator1	first = std_vec.begin();
			Iterator1	last = std_vec.end();
			while (first != last) {
				fd << *first;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl;
		}
		{
			fd << "\tFT" << std::endl;
			fd << "\tSize: " << ft_vec.size() << std::endl;
			fd << "\tCapacity: " << ft_vec.capacity() << std::endl;
			fd << "\tMax_Size: " << ft_vec.max_size() << std::endl;
			fd << "\tContent: { ";
			Iterator2	first = ft_vec.begin();
			Iterator2	last = ft_vec.end();
			while (first != last) {
				fd << *first;
				if (++first != last)
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
	void	test_push_back(std::vector<T> &std_vec, ft::vector<T> &ft_vec, std::list<T> lst) {
		ListIterator	first = lst.begin();
		ListIterator	last = lst.end();
		for (; first != last; ++first) {
			std_vec.push_back(*first);
			ft_vec.push_back(*first);
		}
	}

template <class T>
	void	test_push_back(std::vector<T> &std_vec, ft::vector<T> &ft_vec, T val, int dist) {
		for (int i = 0; i < dist; ++i) {
			std_vec.push_back(val);
			ft_vec.push_back(val);
		}
	}

template <class T>
	void	test_pop_back(std::vector<T> &std_vec, ft::vector<T> &ft_vec, int dist) {
		for (int i = 0; i < dist; ++i) {
			std_vec.pop_back();
			ft_vec.pop_back();
		}
	}

template <class T>
	void	test_insert(std::vector<T> &std_vec, ft::vector<T> &ft_vec, std::list<T> lst, T val, int dist, int type, int pos) {
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

template <class T>
	void	test_assign(std::vector<T> &std_vec, ft::vector<T> &ft_vec, std::list<T> lst, T val, int dist, int type) {
		if (type == 1) {
			std_vec.assign(dist, val);
		}
		else {
			std_vec.insert(lst.begin(), lst.end());
		}
	}

// template <class T>
	// void	print_test_reverse_iterator(std::reverse_iterator<__gnu_cxx::__normal_iterator<T*, std::vector<T> > > std_it) {}