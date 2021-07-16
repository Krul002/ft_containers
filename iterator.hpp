#pragma once

#include <cstddef>
#include <iostream>
#include <iterator>

namespace ft {

	/*
		Необходимые структуры и функции для итераторов
	*/
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

	template <class Bidirectional_Iterator, class Distance>
	void	advance(Bidirectional_Iterator& it, Distance n, bidirectional_iterator_tag) {
		if (n > 0) {
			for (;n;--n)
				++it;
		}
		else {
			for (;n;++n)
				--it;
		}

	}

	template <class Random_Access_Iterator, class Distance>
	void	advance(Random_Access_Iterator& it, Distance n, random_access_iterator_tag) {
		it += n;
	}

	template <class InputIterator, class Distance>
	void	advance(InputIterator& it, Distance n) {
		typename iterator_traits<InputIterator>::difference_type	dif = n;
		advance(it, dif, iterator_traits<InputIterator>::iterator_category);
	}

	template<class Bidirectional_Iterator>
	typename iterator_traits<Bidirectional_Iterator>::difference_type	distance(Bidirectional_Iterator first, Bidirectional_Iterator last, bidirectional_iterator_tag) {
		typename iterator_traits<Bidirectional_Iterator>::difference_type	dif = 0;
		for (Bidirectional_Iterator	iter = first; iter != last; ++iter)
			++dif;
		return dif;
	}

	template<class Random_Access_Iterator>
	typename iterator_traits<Random_Access_Iterator>::difference_type	distance(Random_Access_Iterator first, Random_Access_Iterator last, random_access_iterator_tag) {
		return last - first;
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type	distance(InputIterator first, InputIterator last) {
		return distance(first, last, typename iterator_traits<InputIterator>::iterator_category());
	}

	template<class InputIterator, typename difference_type>
	bool	enable_if() {
		return sizeof(typename InputIterator::difference_type) == sizeof(difference_type);
	}

	/*
		Random Access Iterator (Vector)
	*/

	template <class Iterator, class Container>
	class	random_access_iterator {
	private:
		Iterator	_base;
		typedef iterator_traits<Iterator>	traits_type;
	public:
		typedef typename traits_type::value_type	value_type;
		typedef typename traits_type::difference_type	difference_type;
		typedef typename traits_type::pointer	pointer;
		typedef typename traits_type::reference	reference;
		typedef typename traits_type::iterator_category	iterator_category;
	public:
		/*
			Конструкторы и Деструктор
		*/
		random_access_iterator() : _base(Iterator()) {}

		random_access_iterator(const Iterator& iter) : _base(iter) {}
		
		random_access_iterator(const random_access_iterator& iter) : _base(iter.base()) {}
		
		~random_access_iterator() {}

		/*
			Base
		*/

		const Iterator&			base() const {
			return this->_base;
		}
		
		/*
			Операторы
		*/

		random_access_iterator&	operator=(const random_access_iterator& copy) {
			*(this->_base) = *copy;
			return *this;
		}
		
		reference				operator*() const {
			return *(this->_base);
		}
		
		random_access_iterator	operator+(difference_type n) const {
			return random_access_iterator<Iterator, Container>(this->_base + n);
		}
		
		random_access_iterator&	operator++() {
			++this->_base;
			return *this;
		}
		
		random_access_iterator	operator++(int n) {
			random_access_iterator<Iterator, Container>	tmp(*this);
			++this->_base;
			return tmp;
		}
		
		random_access_iterator&	operator+=(difference_type n) {
			this->_base += n;
			return *this;
		}
		
		random_access_iterator	operator-(difference_type n) const {
			return random_access_iterator<Iterator, Container>(this->_base - n);
		}
		
		random_access_iterator&	operator--() {
			--this->_base;
			return *this;
		}
		
		random_access_iterator	operator--(int n) {
			random_access_iterator<Iterator, Container>	tmp(*this);
			--this->_base;
			return tmp;
		}

		random_access_iterator&	operator-=(difference_type n) {
			this->_base -= n;
			return *this;
		}

		pointer					operator->() const {
			return &(this->operator*());
		}

		reference				operator[](difference_type n) const {
			return *(*this + n);
		}
	};

	template <class Iterator, class Container>
	bool	operator==(const random_access_iterator<Iterator, Container>& A, const random_access_iterator<Iterator, Container>& B) {
		return A.base() == B.base();
	}
	
	template <class Iterator1, class Iterator2, class Container>
	bool	operator==(const random_access_iterator<Iterator1, Container>& A, const random_access_iterator<Iterator2, Container>& B) {
		return A.base() == B.base();
	}
	
	template <class Iterator, class Container>
	bool	operator!=(const random_access_iterator<Iterator, Container>& A, const random_access_iterator<Iterator, Container>& B) {
		return !(A == B);
	}

	template <class Iterator1, class Iterator2, class Container>
	bool	operator!=(const random_access_iterator<Iterator1, Container>& A, const random_access_iterator<Iterator2, Container>& B) {
		return !(A == B);
	}

	template <class Iterator, class Container>
	bool	operator<(const random_access_iterator<Iterator, Container>& A, const random_access_iterator<Iterator, Container>& B) {
		return A.base() < B.base();
	}

	template <class Iterator1, class Iterator2, class Container>
	bool	operator<(const random_access_iterator<Iterator1, Container>& A, const random_access_iterator<Iterator2, Container>& B) {
		return A.base() < B.base();
	}
	
	template <class Iterator, class Container>
	bool	operator<=(const random_access_iterator<Iterator, Container>& A, const random_access_iterator<Iterator, Container>& B) {
		return A < B || A == B;
	}
	template <class Iterator1, class Iterator2, class Container>
	bool	operator<=(const random_access_iterator<Iterator1, Container>& A, const random_access_iterator<Iterator2, Container>& B) {
		return A < B || A == B;
	}
	
	template <class Iterator, class Container>
	bool	operator>(const random_access_iterator<Iterator, Container>& A, const random_access_iterator<Iterator, Container>& B) {
		return A.base() > B.base();
	}

	template <class Iterator1, class Iterator2, class Container>
	bool	operator>(const random_access_iterator<Iterator1, Container>& A, const random_access_iterator<Iterator2, Container>& B) {
		return A.base() > B.base();
	}
	
	template <class Iterator, class Container>
	bool	operator>=(const random_access_iterator<Iterator, Container>& A, const random_access_iterator<Iterator, Container>& B) {
		return A > B || A == B;
	}

	template <class Iterator1, class Iterator2, class Container>
	bool	operator>=(const random_access_iterator<Iterator1, Container>& A, const random_access_iterator<Iterator2, Container>& B) {
		return A > B || A == B;
	}

	template <class Iterator, class Container>
	random_access_iterator<Iterator, Container>	operator+(typename random_access_iterator<Iterator, Container>::difference_type n, const random_access_iterator<Iterator, Container>& it) {
		return random_access_iterator<Iterator, Container>(it + n);
	}

	template <class Iterator, class Container>
	typename random_access_iterator<Iterator, Container>::difference_type	operator-(const random_access_iterator<Iterator, Container>& first, const random_access_iterator<Iterator, Container>& second) {
		return first.base() - second.base();
	}

	/*
		Reverce Iterator
	*/

	template <class Iterator>
	class	reverse_iterator {
	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename iterator_traits<Iterator>::value_type	value_type;
		typedef typename iterator_traits<Iterator>::pointer	pointer;
		typedef typename iterator_traits<Iterator>::reference	reference;
	private:
		Iterator	_base;
	public:
		/*
			Конструкторы и Деструктор
		*/
		reverse_iterator() {}
		
		explicit reverse_iterator(iterator_type iter) : _base(iter) {}
		
		reverse_iterator(const reverse_iterator& iter) : _base(iter._base) {}
		
		~reverse_iterator() {}

		/*
			Base
		*/

		iterator_type		base() const {
			return this->_base;
		}

		/*
			Операторы
		*/

		reverse_iterator&	operator=(const reverse_iterator& copy) {
			this->_base = copy._base;
			return *this;
		}
		
		reference			operator*() const {
			return *(--this->_base);
		}
		
		reverse_iterator	operator+(difference_type n) const {
			return reverse_iterator<Iterator>(this->_base - n);
		}
		
		reverse_iterator&	operator++() {
			--this->_base;
			return *this;
		}
		
		reverse_iterator	operator++(int) {
			reverse_iterator<Iterator>	tmp(*this);
			--this->_base;
			return tmp;
		}

		reverse_iterator&	operator+=(difference_type n) {
			this->_base -= n;
			return *this;
		}
		
		reverse_iterator	operator-(difference_type n) const {
			return reverse_iterator<Iterator>(this->_base + n);
		}
		
		reverse_iterator&	operator--() {
			++this->_base;
			return *this;
		}
		
		reverse_iterator	operator--(int) {
			reverse_iterator<Iterator>	tmp(*this);
			return tmp;
		}

		reverse_iterator&	operator-=(difference_type n) {
			this->_base += n;
			return *this;
		}
		
		pointer				operator->() const {
			return &(this->operator*());
		}
		
		reference			operator[](difference_type n) const {
			return *(*this + n);
		}
	};

	template <class Iterator>
	bool	operator==(const reverse_iterator<Iterator>& A, const reverse_iterator<Iterator>& B) {
		return A.base() == B.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator==(const reverse_iterator<Iterator1>& A, const reverse_iterator<Iterator2>& B) {
		return A.base() == B.base();
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
		return A.base() > B.base();
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
		return A.base() < B.base();
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