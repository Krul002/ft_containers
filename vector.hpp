#pragma once

#include "iterator.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <stdexcept>

namespace ft {

	template <class T, class Alloc = std::allocator<T> >
	class	vector {
	public:
		typedef T	value_type;
		typedef Alloc	allocator_type;
		typedef typename allocator_type::reference	reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer	pointer;
		typedef typename allocator_type::const_pointer	const_pointer;
		typedef ft::random_access_iterator<pointer, vector>	iterator;
		typedef ft::random_access_iterator<const_pointer, vector>	const_iterator;
		typedef ft::reverse_iterator<iterator>	reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t	size_type;
	private:
		allocator_type	_alloc;
		pointer	_point;
		size_type	_size;
		size_type	_capacity;
	public:
		/*
			Конструкторы и Деструктор
		*/
		explicit	vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _point(NULL), _size(0), _capacity(0) {}
		explicit	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(n) {
			this->_point = this->_alloc.allocate(this->_capacity);
			this->insert(this->begin(), this->_capacity, val);
		}
		template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), bool enable = enable_if<InputIterator, difference_type>()) : _alloc(alloc), _size(0) {
				this->_capacity = static_cast<size_type>(ft::distance(first, last));
				this->_point = this->_alloc.allocate(this->_capacity);
				this->insert(this->begin(), first, last);
			}
		vector(const vector& copy) {
			*this = copy;
		}
		~vector() {
			this->clear();
			this->_alloc.deallocate(this->_point, this->_capacity);
		}
		/*
			Операторы
		*/
		vector&						operator=(const vector& copy) {
			this->_alloc = copy._alloc;
			this->_capacity = copy._capacity;
			this->_size = copy._size;
			this->_point = this->_alloc.allocate(this->_capacity);
			for (size_type	i = 0; i < this->_size; ++i)
				this->_alloc.construct(&this->_point[i], copy._point[i]);
			return *this;
		}
		/*
			Итераторы
		*/
		iterator					begin() {
			return iterator(this->_point);
		}
		const_iterator				begin() const {
			return const_iterator(this->_point);
		};
		iterator					end() {
			return iterator(this->_point + this->_size);
		}
		const_iterator				end() const {
			return const_iterator(this->_point + this->_size);
		}
		reverse_iterator			rbegin() {
			return reverse_iterator(this->_point + this->_size - 1);
		}
		const_reverse_iterator		rbegin() const {
			return const_reverse_iterator(this->_point + this->_size - 1);
		}
		reverse_iterator			rend() {
			return reverse_iterator(this->_point - 1);
		}
		const_reverse_iterator		rend() const {
			return const_reverse_iterator(this->_point - 1);
		}
		/*
			Емкость контейнера
		*/
		size_type					size() const {
			return this->_size;
		}
		size_type					max_size() const {
			return this->_alloc.max_size();
		}
		void						resize(size_type n, value_type val = value_type()) {
			if (n < this->_size) {
				for (--this->_size; n < this->_size; --this->_size)
					this->_alloc.destroy(this->_point + this->_size);
			}
			else if (n > this->_size)
				this->insert(this->end, n - this->size(), val);
		}
		size_type					capacity() const {
			return this->_capacity;
		}
		bool						empty() const {
			return this->_size == 0;
		}
		void						reserve(size_type n) {
			if (this->max_size() < n)
				throw std::length_error("The requested vector expansion size exceeds the maximum possible.");
			if (n > this->_capacity) {
				pointer	ptr = this->_point;
				this->_point = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_size; ++i) {
					this->_alloc.construct(&this->_point[i], ptr[i]);
					this->_alloc.destroy(&ptr[i]);
				}
				this->_alloc.deallocate(ptr, this->_capacity);
				this->_capacity = n;
			}
		}
		/*
			Доступ к элементу
		*/
		reference					operator[](size_type n) {
			return this->_point[n];
		}
		const_reference				operator[](size_type n) const {
			return this->_point[n];
		}
		reference					at(size_type n) {
			if (n >= this->_size)
				throw std::out_of_range("N > SIZE.");
			return this->_point[n];
		}
		const_reference				at(size_type n) const {
			if (n >= this->_size)
				throw std::out_of_range("N > SIZE.");
			return this->_point[n];
		}
		reference					front() {
			return this->_point[0];
		}
		const_reference				front() const {
			return this->_point[0];
		}
		reference					back() {
			return this->_point[this->_size - 1];
		}
		const_reference				back() const {
			return this->_point[this->_size - 1];
		}
		/*
			Модификаторы
		*/
		template <class InputIterator>
			void					assign(InputIterator first, InputIterator last, bool enable = enable_if<InputIterator, difference_type>()) {
				this->clear();
				this->insert(this->begin(), first, last);
			}
		void						assign(size_type n, const value_type& val) {
			this->clear();
			this->insert(this->begin(), n, val);
		}
		void						push_back(const value_type& val) {
			this->insert(this->end(), val);
		}
		void						pop_back() {
			if (this->_size != 0)
				this->erase(this->end() - 1);
		}
		iterator					insert(iterator position, const value_type& val) {
			size_type dis = 0;
			if (this->_capacity != 0)
				dis = static_cast<size_type>(ft::distance(this->begin(), position));
			reserve(this->_size + 1);
			value_type	val1 = val;
			for (size_type i = dis; i < this->_size + 1; ++i) {
				value_type	ref = this->_point[i];
				this->_alloc.destroy(&this->_point[i]);
				this->_alloc.construct(&this->_point[i], val1);
				val1 = ref;
			}
			++this->_size;
			return this->begin() + dis;
		}
		void						insert(iterator position, size_type n, const value_type& val) {
			size_type dis = 0;
			if (this->_capacity != 0)
				dis = static_cast<size_type>(ft::distance(this->begin(), position));
			reserve(this->_size + n);
			value_type	val1 = val;
			for (size_type i = dis; i < this->_size + n; ++i) {
				value_type	ref = this->_point[i];
				this->_alloc.destroy(&this->_point[i]);
				this->_alloc.construct(&this->_point[i], val1);
				if (i - dis >= n)
					val1 = ref;
			}
			this->_size += n;
		}
		template <class InputIterator>
			void					insert(iterator position, InputIterator first, InputIterator last, bool enable = enable_if<InputIterator, difference_type>()) {
				size_type	n = static_cast<size_type>(ft::distance(first, last));
				size_type	dis = 0;
				if (this->_capacity != 0)
					dis = static_cast<size_type>(ft::distance(this->begin(), position));
				reserve(this->_size + n);
				InputIterator	iter = first;
				value_type	val = *iter++;
				for (size_type i = dis; i < this->_size + n; ++i) {
					value_type	ref = this->_point[i];
					this->_alloc.destroy(&this->_point[i]);
					this->_alloc.construct(&this->_point[i], val);
					if (iter == last)
						val = ref;
					else
						val = *iter++;
				}
				this->_size += n;
			}
		iterator					erase(iterator position) {
			if (this->_size != 0) {
				size_type	dis = static_cast<size_type>(ft::distance(this->begin(), position));
				for (size_type i = dis; i < this->_size; ++i) {
					this->_alloc.destroy(&this->_point[i]);
					if (i + 1 < this->_size) {
						value_type	val = this->_point[i + 1];
						this->_alloc.construct(&this->_point[i], val);
					}
				}
				--this->_size;
				return this->begin() + dis;
			}
			return this->end();
		}
		iterator					erase(iterator first, iterator last) {
			if (this->_size != 0) {
				size_type	dis = static_cast<size_type>(ft::distance(this->begin(), first));
				size_type	len = static_cast<size_type>(ft::distance(first, last));
				for (size_type i = dis; i < this->_size; ++i) {
					this->_alloc.destroy(&this->_point[i]);
					if (i + len < this->_size) {
						value_type	val = this->_point[i + len];
						this->_alloc.construct(&this->_point[i], val);
					}
				}
				this->_size -= len;
				return this->begin() + dis + len;
			}
			return this->end();
		}
		void						swap(vector& x) {
			allocator_type	alloc = this->_alloc;
			pointer	point = this->_point;
			size_type	size = this->_size;
			size_type	capacity = this->_capacity;

			this->_alloc = x._alloc;
			this->_point = x._point;
			this->_size = x._size;
			this->_capacity = x._capacity;

			x._alloc = alloc;
			x._point = point;
			x._size = size;
			x._capacity = capacity;
		}
		void						clear() {
			for (size_type i = 0; i < this->_size; ++i)
				this->_alloc.destroy(&this->_point[i]);
			this->_size = 0;
		}
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		for (size_t	i = 0; i < lhs.size(); ++i)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}
	
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		for (size_t	i = 0; i < lhs.size() && i < rhs.size(); ++i)
			if (lhs[i] >= rhs[i])
				return false;
		if (lhs.size() < rhs.size())
			return true;
		return false;
	}
	
	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		for (size_t	i = 0; i < lhs.size() && i < rhs.size(); ++i)
			if (lhs[i] > rhs[i])
				return false;
		if (lhs.size() <= rhs.size())
			return true;
		return false;
	}
	
	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		for (size_t	i = 0; i < lhs.size() && i < rhs.size(); ++i)
			if (lhs[i] <= rhs[i])
				return false;
		if (lhs.size() > rhs.size())
			return true;
		return false;
	}
	
	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		for (size_t	i = 0; i < lhs.size() && i < rhs.size(); ++i)
			if (lhs[i] < rhs[i])
				return false;
		if (lhs.size() >= rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}

	
}