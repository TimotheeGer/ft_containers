#ifndef ITERATORS_VECTOR_HPP
#define ITERATORS_VECTOR_HPP

#include <iostream>
#include <string>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
#include "./utils.hpp"

//https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp

namespace ft {

	template<bool _const, typename type_const, typename type_normal>
	struct check_const;

	template<typename type_const, typename type_normal>
	struct check_const<true, type_const, type_normal> {

		typedef type_const type;
	};


	template<typename type_const, typename type_normal>
	struct check_const<false, type_const, type_normal> {

		typedef type_normal type;
	};


	/* ************************************************************************** */
	/*                         Iterator / Const Iterator: :                       */
	/* ************************************************************************** */

	template<class T, bool _const = false>
	class Iterator_vector { 

		public:
			
			typedef T													value_type;
			typedef ptrdiff_t											difference_type;
			typedef typename check_const<_const, const T&, T&>::type	reference;
			typedef typename check_const<_const, const T*, T*>::type	pointer;
			typedef size_t												size_type;
    		typedef std::bidirectional_iterator_tag 					iterator_category;


			Iterator_vector<T, _const>() : m_ptr(NULL) {};
			Iterator_vector<T, _const>(value_type *ptr) : m_ptr(ptr) {};
			Iterator_vector<T, _const>(const Iterator_vector<T, false>& cpy) { m_ptr = cpy.m_ptr; };

			virtual ~Iterator_vector<T, _const>() {};

			Iterator_vector<T, _const> &operator=( const Iterator_vector<T, _const> &rhs) { m_ptr = rhs.m_ptr; return *this; };

			Iterator_vector<T, _const>& operator++() { m_ptr++; return *this; };
			Iterator_vector<T, _const> operator++(int) { Iterator_vector<T, _const> tmp = *this; ++(*this); return tmp; };
			
			Iterator_vector<T, _const>& operator--() { m_ptr--; return *this; };
			Iterator_vector<T, _const> operator--(int) { Iterator_vector<T, _const> tmp = *this; --(*this); return tmp; };
			
			Iterator_vector<T, _const> operator+=(int nb) { m_ptr += nb; return *this; };
			Iterator_vector<T, _const> operator-=(int nb) { m_ptr -= nb; return *this; };
			
			Iterator_vector<T, _const> operator+(int nb) { Iterator_vector<T, _const> tmp(*this); return tmp += nb; };
			Iterator_vector<T, _const> operator-(int nb) { Iterator_vector<T, _const> tmp(*this); return tmp -= nb; };

			difference_type operator-(Iterator_vector<T, true> it) const { return (this->m_ptr - it.m_ptr); };

			reference operator[] (size_t n) const { return (m_ptr[n]); };

			bool operator<(const Iterator_vector<T, true>& rhs) const { return m_ptr < rhs.m_ptr; };			
			bool operator>(const Iterator_vector<T, true>& rhs) const { return m_ptr > rhs.m_ptr; };			
			bool operator<=(const Iterator_vector<T, true>& rhs) const { return m_ptr <= rhs.m_ptr; };			
			bool operator>=(const Iterator_vector<T, true>& rhs) const { return m_ptr >= rhs.m_ptr; };			
			bool operator==(const Iterator_vector<T, true>& rhs) const { return m_ptr == rhs.m_ptr; };
			bool operator!=(const Iterator_vector<T, true>& rhs) const { return m_ptr != rhs.m_ptr; };			
		
			reference operator*() const { return *m_ptr; };
			pointer operator->() const { return m_ptr; };

			friend Iterator_vector<T, _const> operator+(int nb, Iterator_vector<T, _const> it) { return (it += nb); }

			friend Iterator_vector<T, _const> operator-(int nb, Iterator_vector<T, _const> it) { return (it -= nb); }
			
			pointer m_ptr;
	
	};
}

#endif