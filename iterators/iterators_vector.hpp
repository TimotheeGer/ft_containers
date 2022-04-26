#ifndef ITERATORS_VECTOR_HPP
#define ITERATORS_VECTOR_HPP

#include <iostream>
#include <string>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t

namespace ft {

	template<typename T>
	class Iterator { 
		
		public:

			typedef long int	difference_type;
			typedef T			value_type;
			typedef size_t		size_type;
			typedef T*			elemPtr;
			typedef T&			reference;
			typedef T*			pointer;

			Iterator(pointer ptr) : m_ptr(ptr) {};

			Iterator(const Iterator<T>& src) { m_ptr = src.m_ptr; };

			~Iterator() {};


			Iterator& operator++() { 
				m_ptr++;
				return *this;
			};

			Iterator operator++(int) {

				Iterator tmp = *this;
				++(*this);
				return tmp;
			};

			friend bool operator==(Iterator& const a, Iterator& const b) {

				return a.m_ptr == b.m_ptr;
			}

			friend bool operator!=(Iterator& const a, Iterator& const b) {

				return a.m_ptr != b.m_ptr;
			}			
		
			reference operator*() const { return *m_ptr; };
			pointer operator->() const { return m_ptr; };
		
		private:
			
			pointer m_ptr;			
	};	

}

#endif