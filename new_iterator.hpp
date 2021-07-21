#pragma once

#include <cstddef>
#include <iostream>
#include <ostream>

namespace ft {

	/*================*/
	/*ITERATOR STRUCTS*/
	/*================*/

	struct	input_iterator_tag {};

	struct	output_iterator_tag {};

	struct	forward_iterator_tag : public input_iterator_tag, public output_iterator_tag{};

	struct	bidirectional_iterator_tag : public forward_iterator_tag {};

	struct	random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct	iterator {
			typedef T	value_type;
			typedef Distance	difference_type;
			typedef Pointer	pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
		};

	template <class Iterator>
		struct	iterator_traits {
			typedef typename Iterator::difference_type	difference_type;
			typedef typename Iterator::value_type	value_type;
			typedef typename Iterator::pointer	pointer;
			typedef typename Iterator::reference	reference;
			typedef typename Iterator::iterator_category	iterator_category;
		};

	template <class T>
		struct	iterator_traits<T*> {
			typedef ptrdiff_t	difference_type;
			typedef T	value_type;
			typedef T*	pointer;
			typedef T&	reference;
			typedef random_access_iterator_tag	iterator_category;
		};

	template <class T>
		struct	iterator_traits<const T*> {
			typedef ptrdiff_t	difference_type;
			typedef T	value_type;
			typedef const T*	pointer;
			typedef const T&	reference;
			typedef random_access_iterator_tag	iterator_category;
		};
	
	/*==================*/
	/*ITERATOR FUNCTIONS*/
	/*==================*/

	template <class Iterator>
		typename iterator_traits<Iterator>::iterator_category	iterator_category(Iterator iter) {
			return typename iterator_traits<Iterator>::iterator_category();
		}

	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type	distance(Iterator first, Iterator last) {
			typename iterator_traits<Iterator>::difference_type	dist = 0;
			while (first != last) {
				first++;
				dist++;
			}
			return dist;
		}

	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type	distance(Iterator first, Iterator last, input_iterator_tag) {
			return ft::distance(first, last);
		}
	
	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type	distance(Iterator first, Iterator last, forward_iterator_tag) {
			return ft::distance(first, last);
		}
	
	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type	distance(Iterator first, Iterator last, bidirectional_iterator_tag) {
			return ft::distance(first, last);
		}

	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type	distance(Iterator first, Iterator last, random_access_iterator_tag) {
			return last - first;
		}

	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type	distance(Iterator first, Iterator last, std::input_iterator_tag) {
			return ft::distance(first, last);
		}
	
	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type	distance(Iterator first, Iterator last, std::forward_iterator_tag) {
			return ft::distance(first, last);
		}
	
	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type	distance(Iterator first, Iterator last, std::bidirectional_iterator_tag) {
			return ft::distance(first, last);
		}

	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type	distance(Iterator first, Iterator last, std::random_access_iterator_tag) {
			return last - first;
		}

	/*================*/
	/*ITERATOR CLASSES*/
	/*================*/

	template <class T>
		class	vector_iterator {
			private:
			T	_base;
			typedef iterator_traits<T>	_traits_type;
		public:
			typedef typename _traits_type::value_type	value_type;
			typedef typename _traits_type::difference_type	difference_type;
			typedef typename _traits_type::pointer	pointer;
			typedef typename _traits_type::reference	reference;
			typedef random_access_iterator_tag	iterator_category;
		public:
			/*
				Конструкторы и Деструктор
			*/
			vector_iterator() : _base(T()) {}

			explicit vector_iterator(const T& pointer) : _base(pointer) {}

			vector_iterator(const vector_iterator& iter) : _base(iter.base()) {}

			~vector_iterator() {}

			/*
				Base
			*/

			const pointer			base() const {
				return this->_base;
			}

			/*
				Операторы
			*/

			reference	operator*() const {
				return *(this->_base);
			}

			pointer	operator->() const {
				return &(*this->_base);
			}



			vector_iterator&	operator++() {
				++this->_base;
				return *this;
			}

			vector_iterator	operator++(int n) {
				vector_iterator<T>	tmp(*this);
				++this->_base;
				return tmp;
			}

			vector_iterator	operator+(difference_type n) const {
				return vector_iterator<T>(this->_base + n);
			}

			vector_iterator&	operator+=(difference_type n) {
				this->_base += n;
				return *this;
			}


			vector_iterator&	operator--() {
				--this->_base;
				return *this;
			}

			vector_iterator	operator--(int n) {
				vector_iterator<T>	tmp(*this);
				--this->_base;
				return tmp;
			}

			vector_iterator	operator-(difference_type n) const {
				return vector_iterator<T>(this->_base - n);
			}

			vector_iterator&	operator-=(difference_type n) {
				this->_base -= n;
				return *this;
			}

			reference				operator[](difference_type n) const {
				return *(*this + n);
			}

		};

	template <class Iterator>
		bool	operator==(const vector_iterator<Iterator>& A, const vector_iterator<Iterator>& B) {
			return A.base() == B.base();
		}
	
	template <class Iterator1, class Iterator2>
		bool	operator==(const vector_iterator<Iterator1>& A, const vector_iterator<Iterator2>& B) {
			return A.base() == B.base();
		}
	
	template <class Iterator>
		bool	operator!=(const vector_iterator<Iterator>& A, const vector_iterator<Iterator>& B) {
			return !(A == B);
		}

	template <class Iterator1, class Iterator2>
		bool	operator!=(const vector_iterator<Iterator1>& A, const vector_iterator<Iterator2>& B) {
			return !(A == B);
		}

	template <class Iterator1, class Iterator2>
		bool	operator<(const vector_iterator<Iterator1>& A, const vector_iterator<Iterator2>& B) {
			return A.base() < B.base();
		}
	
	template <class Iterator>
		bool	operator<=(const vector_iterator<Iterator>& A, const vector_iterator<Iterator>& B) {
			return A < B || A == B;
		}
	
	template <class Iterator1, class Iterator2>
		bool	operator<=(const vector_iterator<Iterator1>& A, const vector_iterator<Iterator2>& B) {
			return A < B || A == B;
		}
	
	template <class Iterator>
		bool	operator>(const vector_iterator<Iterator>& A, const vector_iterator<Iterator>& B) {
			return A.base() > B.base();
		}

	template <class Iterator1, class Iterator2>
		bool	operator>(const vector_iterator<Iterator1>& A, const vector_iterator<Iterator2>& B) {
			return A.base() > B.base();
		}
	
	template <class Iterator>
		bool	operator>=(const vector_iterator<Iterator>& A, const vector_iterator<Iterator>& B) {
			return A > B || A == B;
		}

	template <class Iterator1, class Iterator2>
		bool	operator>=(const vector_iterator<Iterator1>& A, const vector_iterator<Iterator2>& B) {
			return A > B || A == B;
		}
	
	template <class Iterator>
		vector_iterator<Iterator>	operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator>& it) {
			return vector_iterator<Iterator>(it + n);
		}

	template <class Iterator>
		typename vector_iterator<Iterator>::difference_type	operator-(const vector_iterator<Iterator>& first, const vector_iterator<Iterator>& second) {
			return first.base() - second.base();
		}
	
	/*========================*/
	/*REVERSE ITERATOR CLASSES*/
	/*========================*/

	template <class Iterator>
		class	reverse_iterator {
			private:
			Iterator	_base;
			typedef iterator_traits<Iterator>	_traits_type;
		public:
			typedef Iterator iterator_type;
			typedef typename _traits_type::value_type	value_type;
			typedef typename _traits_type::difference_type	difference_type;
			typedef typename _traits_type::pointer	pointer;
			typedef typename _traits_type::reference	reference;
			typedef typename _traits_type::iterator_category	iterator_category;
		public:
			/*
				Конструкторы и Деструктор
			*/
			reverse_iterator() : _base(Iterator()) {}

			explicit reverse_iterator(const Iterator& iter) : _base(iter) {}

			reverse_iterator(const reverse_iterator& iter) : _base(iter.base()) {}

			~reverse_iterator() {}

			/*
				Base
			*/

			iterator_type	base() const {
				return this->_base;
			}

			/*
				Операторы
			*/

			reference	operator*() const {
				return *(this->_base);
			}

			pointer	operator->() const {
				return &(*this->_base);
			}



			reverse_iterator&	operator++() {
				--this->_base;
				return *this;
			}

			reverse_iterator	operator++(int n) {
				reverse_iterator<Iterator>	tmp(*this);
				--this->_base;
				return tmp;
			}

			reverse_iterator	operator+(difference_type n) const {
				return reverse_iterator<Iterator>(this->_base - n);
			}

			reverse_iterator&	operator+=(difference_type n) {
				this->_base -= n;
				return *this;
			}


			reverse_iterator&	operator--() {
				++this->_base;
				return *this;
			}

			reverse_iterator	operator--(int n) {
				reverse_iterator<Iterator>	tmp(*this);
				++this->_base;
				return tmp;
			}

			reverse_iterator	operator-(difference_type n) const {
				return reverse_iterator<Iterator>(this->_base + n);
			}

			reverse_iterator&	operator-=(difference_type n) {
				this->_base += n;
				return *this;
			}

			reference				operator[](difference_type n) const {
				return *(*this + n);
			}

		};
	
	template <class Iterator>
		bool	operator==(const reverse_iterator<Iterator>& A, const reverse_iterator<Iterator>& B) {
			return A.base() == B.base();
		}
	
	template <class Iterator1, class Iterator2>
		bool	operator==(const reverse_iterator<Iterator1>& A, const reverse_iterator<Iterator2>& B) {
			return *(A.base()) == *(B.base());
		}
	
	template <class Iterator>
		bool	operator!=(const reverse_iterator<Iterator>& A, const reverse_iterator<Iterator>& B) {
			return !(A == B);
		}

	template <class Iterator1, class Iterator2>
		bool	operator!=(const reverse_iterator<Iterator1>& A, const reverse_iterator<Iterator2>& B) {
			return !(A == B);
		}

	template <class Iterator>
		bool	operator<(const reverse_iterator<Iterator>& A, const reverse_iterator<Iterator>& B) {
			return A.base() > B.base();
		}

	template <class Iterator1, class Iterator2>
		bool	operator<(const reverse_iterator<Iterator1>& A, const reverse_iterator<Iterator2>& B) {
			return *(A.base()) > *(B.base());
		}
	
	template <class Iterator>
		bool	operator<=(const reverse_iterator<Iterator>& A, const reverse_iterator<Iterator>& B) {
			return A < B || A == B;
		}

	template <class Iterator1, class Iterator2>
		bool	operator<=(const reverse_iterator<Iterator1>& A, const reverse_iterator<Iterator2>& B) {
			return A < B || A == B;
		}
	
	template <class Iterator>
		bool	operator>(const reverse_iterator<Iterator>& A, const reverse_iterator<Iterator>& B) {
			return A.base() < B.base();
		}

	template <class Iterator1, class Iterator2>
		bool	operator>(const reverse_iterator<Iterator1>& A, const reverse_iterator<Iterator2>& B) {
			return *(A.base()) < *(B.base());
		}
	
	template <class Iterator>
		bool	operator>=(const reverse_iterator<Iterator>& A, const reverse_iterator<Iterator>& B) {
			return A > B || A == B;
		}

	template <class Iterator1, class Iterator2>
		bool	operator>=(const reverse_iterator<Iterator1>& A, const reverse_iterator<Iterator2>& B) {
			return A > B || A == B;
		}

	template <class Iterator>
		reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it) {
			return reverse_iterator<Iterator>(it - n);
		}

	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& first, const reverse_iterator<Iterator>& second) {
			return first.base() - second.base();
		}

}