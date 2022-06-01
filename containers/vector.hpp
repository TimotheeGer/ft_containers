/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:49:09 by tigerber          #+#    #+#             */
/*   Updated: 2022/06/01 18:59:28 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>
#include <sstream>

#include "../iterators/iterators_vector.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/utils.hpp"

//https://www.cplusplus.com/reference/vector/vector/
//https://www.geeksforgeeks.org/vector-in-cpp-stl/

//https://www.cplusplus.com/reference/memory/allocator/
//https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/

namespace ft {
	
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		
		public:

		/* ************************************************************************** */
		/*                          Member type Definition                            */
		/* ************************************************************************** */

			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef value_type&												reference;
			typedef const value_type&										const_reference;
			typedef value_type*												pointer;
			typedef const value_type*										const_pointer;

			typedef typename ft::Iterator_vector<T, false>					iterator;
			typedef typename ft::Iterator_vector<T, true>					const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			typedef ptrdiff_t												difference_type;
			typedef size_t													size_type;

		private:
			
		/* ************************************************************************** */
		/*                                Atribues                                    */
		/* ************************************************************************** */

			allocator_type										_alloc;
			pointer												_vector;
			size_type											_size;
			size_type											_capacity;

		public:

		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */

			// default (1)
			explicit vector (const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _size(0), _capacity(0) {

				_vector = NULL;
			};

			// fill (2)
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : 
			_alloc (alloc), _size(n), _capacity(n) {

				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vector[i], val);
			};

			// range (3)
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			  typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) : 
			_alloc(alloc), _size(0), _capacity(0) {

				_vector = NULL;
				insert(begin(), first, last);
			};

			// copy (4)
			vector (const vector& x) : _alloc(x._alloc), _size(0), _capacity(0) { 
				
				_vector = NULL;
				assign(x.begin(), x.end());
			};

			~vector() {
 
				clear(); 
				_alloc.deallocate(_vector, _capacity);
			};

			// operator (1)	
 			vector& operator= (const vector& x) {
				
				 if (&x == this)
				 	return *this;
				assign(x.begin(), x.end());
				return *this;
			 };

		/* ************************************************************************** */
		/*                                 Iterator:                                  */
		/* ************************************************************************** */

			iterator 				begin()			{ return iterator(&_vector[0]); };
			const_iterator 			begin() const	{ return const_iterator(&_vector[0]); };
			
			iterator 				end()			{ return iterator(&_vector[_size]); };
			const_iterator 			end() const		{ return const_iterator(&_vector[_size]); };

			reverse_iterator 		rbegin()		{ return reverse_iterator(end()); };
			const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(end()); };

			reverse_iterator		rend() 			{ return reverse_iterator(begin()); };
			const_reverse_iterator 	rend() const	{ return const_reverse_iterator(begin()); };

		/* ************************************************************************** */
		/*                                 Capacity:                                  */
		/* ************************************************************************** */

			size_type 				size() const { return _size; };	

			size_type 				max_size() const { return _alloc.max_size(); };

			void 					resize (size_type n, value_type val = value_type()) {

				while (_size > n)
					_alloc.destroy(&_vector[--_size]);

				if (n > _size) 
				{
					if (val)
						insert(end(), n - _size, val);
					else
						insert(end(), n - _size, 0);
				}
			}

			size_type 				capacity() const { return _capacity; };

			bool 					empty() const { return _size == 0; };

			void 					reserve (size_type n) {

				if (n < _capacity)
					return ;
				if (n > max_size())
					throw std::length_error("vector::reserve");
				
				pointer new_vector = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&new_vector[i], _vector[i]);	
					_alloc.destroy(&_vector[i]);
				}
				_alloc.deallocate(_vector, _capacity);
				_capacity = n;
				_vector = new_vector;
			};

		/* ************************************************************************** */
		/*                              Element access:                               */
		/* ************************************************************************** */

			reference 				operator[] (size_type n) { return _vector[n]; };
			const_reference 		operator[] (size_type n) const { return _vector[n]; };

			reference 				at (size_type n) {

				if (n >= _size) {
					std::stringstream str;
					str << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << _size << ")";
					throw std::out_of_range(str.str().c_str());
				}
				return _vector[n];
			};
			
			const_reference 		at (size_type n) const {

				if (n >= _size) {
					std::stringstream str;
					str << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << _size << ")";
					throw std::out_of_range(str.str().c_str());
				}
				return _vector[n];
			};

			reference 				front() { return _vector[0]; };
			const_reference 		front() const { return _vector[0]; };

			reference 				back()  { return _vector[_size - 1]; };
			const_reference 		back() const { return _vector[_size - 1]; };


		/* ************************************************************************** */
		/*                                Modifiers:                                  */
		/* ************************************************************************** */

			// range (1)
			template <class InputIterator>
  			void 					assign (InputIterator first, InputIterator last,
			  							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
				
				InputIterator tmp_first = first;
				size_type n = 0;
				
				while (tmp_first++ != last)
					n++;				
				
				clear();
				reserve(n);
				insert(begin(), first, last);
			};

			// fill (2)
			void 					assign (size_type n, const value_type& val) { 

				clear();
				reserve(n);
				insert(begin(), n, val);
			};

			void 					push_back (const value_type& val) { insert(end(), val); };

			void 					pop_back() { if (_size){ erase(end() - 1);} };

			// single element (1)	
			iterator 				insert (iterator position, const value_type& val) {

				size_type index = position - begin();
				if (_size + 1 > _capacity)
				{
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				_size++;
				if (index < _size)
				{
					for (size_type i = _size - 1; i > index; i--)
					{
						_alloc.construct(&_vector[i], _vector[i - 1]);
						_alloc.destroy(&_vector[i - 1]);
					}
				}
				_alloc.construct(&_vector[index], val);
				return iterator(&_vector[index]);
			};

			// fill (2)
			void					insert (iterator position, size_type n, const value_type& val) {

				difference_type index = position - begin();
				if (_size + n > _capacity)
				{
        			if (_capacity == 0)
        		  		reserve(n);
        			else 
					{
        		  		if (_size * 2 >= _size + n)
        		    		reserve(_size * 2);
        		  		else
        		    		reserve(_size + n);
        			}
				}

				for (size_type i = n + _size - 1; i > index + n - 1; i--)
				{
					_alloc.construct(&_vector[i], _vector[i - n]);
					_alloc.destroy(&_vector[i - n]);
				}
				for (size_type i = index; i < index + n; i++)
				{
					_alloc.construct(&_vector[i], val);
					_size++;
				}
			};
			// range (3)
			template <class InputIterator>
    		void					insert (iterator position, InputIterator first, InputIterator last, 
											typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {

				difference_type index = position - begin();
				InputIterator tmp_first = first;
				size_type n = 0;
				
				while (tmp_first++ != last)
					n++;

				if (_size + n > _capacity)
				{
        			if (_capacity == 0)
        		  		reserve(n);
        			else 
					{
        		  		if (_size * 2 >= _size + n)
        		    		reserve(_size * 2);
        		  		else
        		    		reserve(_size + n);
        			}
				}
				
				for (size_type i = n + _size - 1; i > index + n - 1; i--)
				{
					_alloc.construct(&_vector[i], _vector[i - n]);
					_alloc.destroy(&_vector[i - n]);
				}
				for (size_type i = index; i < index + n; i++)
				{
					_alloc.construct(&_vector[i], *first);
					_size++;
					first++;
				}
			};

			iterator 				erase (iterator position) {

				size_type index = position - begin();
				size_type i = index;
				
				_alloc.destroy(&_vector[i]);
				_size--;
				while (i < _size)
				{
					_alloc.construct(&_vector[i], _vector[i + 1]);
					_alloc.destroy(&_vector[i + 1]);
					i++;
				}
				return iterator(&_vector[index]);
			};

			iterator erase (iterator first, iterator last) {
				
				size_type start = first - begin();
				difference_type offset = last - first;

				if (first == last)
					return iterator(first);

				for (iterator it = first; it != last; it++)
					_alloc.destroy(&(*it));

				_size -= offset;
				if (start < _size)
				{
					for (size_type i = start; i < _size; i++)
					{
						_alloc.construct(&_vector[i], _vector[i + offset]);
						_alloc.destroy(&_vector[i + offset]);
					}
				}
				return iterator(&_vector[start]);
			};


			void					swap (vector& x) {

				pointer vector_tmp = x._vector;
				x._vector = _vector;
				_vector = vector_tmp;

				size_type size_tmp = x._size;
				x._size = _size;
				_size = size_tmp;

				size_type capacity_tmp = x._capacity;
				x._capacity = _capacity;
				_capacity = capacity_tmp;
			};

			void 					clear() { erase(begin(), end()); }

		/* ************************************************************************** */
		/*                                Allocator:                                  */
		/* ************************************************************************** */

			allocator_type 			get_allocator() const { return _alloc; };
	
	};

		/* ************************************************************************** */
		/*                       Non-member function overloads                        */
		/* ************************************************************************** */

			template <class T, class Alloc>
			bool				operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

				if (lhs.size() != rhs.size())
					return false;
				for (size_t i = 0; i < lhs.size(); i++)
				{
					if (lhs[i] != rhs[i])
						return false;
				}
				return true;
			};

			template <class T, class Alloc>
			bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				
				typename vector<T>::const_iterator it1 = lhs.begin();
				typename vector<T>::const_iterator it2 = rhs.begin();

				while (it1 != lhs.end() && it2 != rhs.end())
				{	
					if (*it1 < *it2)
						return true;
					else if (*it1 > *it2)
						return false;
					it1++;
					it2++;
				}
				return (it2 != rhs.end());
			};

			template <class T, class Alloc>
			bool				operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs == rhs); };

			template <class T, class Alloc>
			bool				operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (lhs < rhs || rhs == lhs); };

			template <class T, class Alloc>
			bool				operator >  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs <= rhs); };

			template <class T, class Alloc>
			bool				operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs < rhs); };

			template <class T, class Alloc>
  			void				swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); };

}

#endif
