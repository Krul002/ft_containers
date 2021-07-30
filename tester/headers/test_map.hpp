#include "color.hpp"
#include "../../headers.hpp"
#include "../../new_iterator.hpp"
#include "../../map.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <string>
#include <sys/stat.h>
#include <map>

void	print_test(std::string name, std::string args, int num_args);
void	print_result(bool res, bool capacity);
void	iterator2();
void	const_iterator2();
void	reverse_iterator2();
void	const_reverse_iterator2();
void	constructors2();
void	capacity2();
void	access2();
void	modifiers2();
void	observers();
void	operations();

template <class T, class Iterator1, class Iterator2>
	bool	test_map(std::map<T, T> &std_map, ft::map<T, T> &ft_map) {
		bool	ret = true;
		Iterator1	std_first = std_map.begin();
		Iterator2	ft_first = ft_map.begin();
		Iterator1	std_last = std_map.end();
		Iterator2	ft_last = ft_map.end();
		if (std_map.size() != ft_map.size())
			ret = false;
		for (; ret == true && std_first != std_last && ft_first != ft_last; ++std_first, ++ft_first) {
			if (std_first->first != ft_first->first && std_first->second != ft_first->second)
				ret = false;
		}
		return ret;
	}

template <class T, class Iterator1, class Iterator2>
	bool	test_map(const std::map<T, T> &std_map, const ft::map<T, T> &ft_map) {
		bool	ret = true;
		Iterator1	std_first = std_map.begin();
		Iterator2	ft_first = ft_map.begin();
		Iterator1	std_last = std_map.end();
		Iterator2	ft_last = ft_map.end();
		if (std_map.size() != ft_map.size())
			ret = false;
		for (; ret == true && std_first != std_last && ft_first != ft_last; ++std_first, ++ft_first) {
			if (std_first->first != ft_first->first && std_first->second != ft_first->second)
				ret = false;
		}
		return ret;
	}

template <class T, class Iterator1, class Iterator2>
	void	print_test_map(std::map<T, T> &std_map, ft::map<T, T> &ft_map, std::ios_base::openmode	&mode, int test, std::string path) {
		std::fstream	fd(path, mode);
		mode = std::fstream::in | std::fstream::out | std::fstream::app;
		fd << "TEST" << test << ":" << std::endl;
		{
			fd << "\tSTD" << std::endl;
			fd << "\tSize: " << std_map.size() << std::endl;
			fd << "\tMax_Size: " << std_map.max_size() << std::endl;
			fd << "\tContent: { ";
			Iterator1	first = std_map.begin();
			Iterator1	last = std_map.end();
			while (first != last) {
				fd << first->first << ":" << first->second;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl;
		}
		{
			fd << "\tFT" << std::endl;
			fd << "\tSize: " << ft_map.size() << std::endl;
			fd << "\tMax_Size: " << ft_map.max_size() << std::endl;
			fd << "\tContent: { ";
			Iterator2	first = ft_map.begin();
			Iterator2	last = ft_map.end();
			while (first != last) {
				fd << first->first << ":" << first->second;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl << std::endl;
		}
		fd.close();
	}

template <class T, class Iterator1, class Iterator2>
	void	print_test_map(const std::map<T, T> &std_map, const ft::map<T, T> &ft_map, std::ios_base::openmode	&mode, int test, std::string path) {
		std::fstream	fd(path, mode);
		mode = std::fstream::in | std::fstream::out | std::fstream::app;
		fd << "TEST" << test << ":" << std::endl;
		{
			fd << "\tSTD" << std::endl;
			fd << "\tSize: " << std_map.size() << std::endl;
			fd << "\tMax_Size: " << std_map.max_size() << std::endl;
			fd << "\tContent: { ";
			Iterator1	first = std_map.begin();
			Iterator1	last = std_map.end();
			while (first != last) {
				fd << first->first << ":" << first->second;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl;
		}
		{
			fd << "\tFT" << std::endl;
			fd << "\tSize: " << ft_map.size() << std::endl;
			fd << "\tMax_Size: " << ft_map.max_size() << std::endl;
			fd << "\tContent: { ";
			Iterator2	first = ft_map.begin();
			Iterator2	last = ft_map.end();
			while (first != last) {
				fd << first->first << ":" << first->second;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl << std::endl;
		}
		fd.close();
	}

template <class T1, class T2, class ListIterator1, class ListIterator2>
	void	print_test_iterator(std::list<T1> &std_it, std::list<T2> &ft_it, std::ios_base::openmode	&mode, int test, std::string path) {
		std::fstream	fd(path, mode);
		mode = std::fstream::in | std::fstream::out | std::fstream::app;
		fd << "TEST" << test << ":" << std::endl;
		{
			fd << "\tSTD: { ";
			ListIterator1	first = std_it.begin();
			ListIterator1	last = std_it.end();
			while (first != last) {
				fd << std::boolalpha << (*first).first << ":" << (*first).second;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl;
		}
		{
			fd << "\tFT: { ";
			ListIterator2	first = ft_it.begin();
			ListIterator2	last = ft_it.end();
			while (first != last) {
				fd << std::boolalpha << (*first).first << ":" << (*first).second;
				if (++first != last)
					fd << ", ";
			}
			fd << " }" << std::endl << std::endl;
		}
		fd.close();
	}


template <class T1, class T2>
	void	list_push(std::list<T1> &std_lst, std::list<T2> &ft_lst, const T1 &std, const T2 &ft) {
		std_lst.push_back(std);
		ft_lst.push_back(ft);
	}

template <class T1, class T2>
	void	list_push(std::list<T1> &std_lst, std::list<T2> &ft_lst, T1 &std, T2 &ft) {
		std_lst.push_back(std);
		ft_lst.push_back(ft);
	}

template <class T, class TT, class ListIterator>
	void	test_push_back(std::map<T, T> &std_map, ft::map<T, T> &ft_map, std::list<TT> lst) {
		ListIterator	first = lst.begin();
		ListIterator	last = lst.end();
		for (; first != last; ++first) {
			std_map.insert(*first);
			ft_map.insert(ft::pair<T, T>((*first).first, (*first).second));
		}
	}

template <class T, class TT, class ListIterator>
	void	test_push_back(const std::map<T, T> &std_map, const ft::map<T, T> &ft_map, std::list<TT> lst) {
		ListIterator	first = lst.begin();
		ListIterator	last = lst.end();
		for (; first != last; ++first) {
			std_map.insert(*first);
			ft_map.insert(ft::pair<T, T>((*first).first, (*first).second));
		}
	}

template <class T, class TT>
	void	test_push_back(std::map<T, T> &std_map, ft::map<T, T> &ft_map, TT val, int dist) {
		for (int i = 0; i < dist; ++i) {
			std_map.insert(val);
			ft_map.insert(val.first, val.second);
		}
	}

template <class T>
	void	test_pop_back(std::map<T, T> &std_map, ft::map<T, T> &ft_map, int dist) {
		typename std::map<T, T>::iterator	std_it = std_map.end();
		typename ft::map<T, T>::iterator	ft_it = ft_map.end();
		for (int i = 0; i < dist; ++i) {
			std_map.erase(--std_it);
			ft_map.erase(--ft_it);
		}
	}

template <class T, class TT>
	void	test_insert(std::map<T, T> &std_map, ft::map<T, T> &ft_map, std::list<TT> lst, TT val, int dist, int type, int pos) {
		if (type == 1) {
			std_map.insert(std_map.begin() + pos, val);
		}
		else if (type == 2) {
			std_map.insert(std_map.begin() + pos, dist, val);
		}
		else {
			std_map.insert(std_map.begin() + pos, lst.begin(), lst.end());
		}
	}

// template <class T>
// 	void	test_assign(std::map<T, T> &std_map, ft::map<T, T> &ft_map, std::list<T> lst, T val, int dist, int type) {
// 		if (type == 1) {
// 			std_map.assign(dist, val);
// 		}
// 		else {
// 			std_map.insert(lst.begin(), lst.end());
// 		}
// 	}

// template <class T>
	// void	print_test_reverse_iterator(std::reverse_iterator<__gnu_cxx::__normal_iterator<T*, std::map<T, T> > > std_it) {}