/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:50:18 by tigerber          #+#    #+#             */
/*   Updated: 2022/05/30 16:50:32 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>
#include "vector.hpp"


namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {

		public:


		/* ************************************************************************** */
		/*                          Member type Definition                            */
		/* ************************************************************************** */

			typedef T					value_type;
			typedef Container   		container_type;
			typedef std::size_t 		size_type;


		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */

			explicit stack (const container_type& ctnr = container_type()) {

				c = ctnr;
			};

			stack& operator=( const stack& other ) {
				
				c = other.c;
				return *this;
			};

			~stack() {};


		/* ************************************************************************** */
		/*                              Members functions :                           */
		/* ************************************************************************** */

			bool empty() const { return c.empty(); };

			size_type size() const { return c.size(); };

			value_type& top() { return c.back(); };

			const value_type& top() const { return c.back(); };

			void push (const value_type& val) { return c.push_back(val); };

			void pop() { return c.pop_back(); };


		template <class T1, class C1>
		friend bool operator== (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

		template <class T1, class C1>
		friend bool operator< (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

		protected:
	
			container_type c;
	
	};	
		/* ************************************************************************** */
		/*                              relational operators:                         */
		/* ************************************************************************** */


			template <class T, class Container>
			  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { 

				return (lhs.c == rhs.c);
			  };

			template <class T, class Container>
			  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { 

				return !(lhs == rhs);
			  };

			template <class T, class Container>
			  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { 

				return (lhs.c < rhs.c);
			  };

			template <class T, class Container>
			  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { 

				return (lhs < rhs || rhs == lhs);
			  };

			template <class T, class Container>
			  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { 

				  	return !(lhs <= rhs);
			  };

			template <class T, class Container>
			  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { 

				  	return !(lhs < rhs);
			  };
}

#endif
