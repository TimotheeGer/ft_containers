/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:01:05 by tigerber          #+#    #+#             */
/*   Updated: 2022/04/26 18:01:49 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t

class Integers
{
	private:	
	    
		int m_data[200];
		
	public:
		

		struct const_Iterator { 

			using iterator_category = std::forward_iterator_tag;
    		using difference_type   = std::ptrdiff_t;
    		using value_type        = int;
    		using pointer           = int*;  // or also value_type*
    		using reference         = int&;  // or also value_type&	
			
			const_Iterator(pointer ptr) : m_ptr(ptr) {};
			
			const reference operator*() const { return *m_ptr; };

			const pointer operator->() { return m_ptr; };

			const_Iterator& operator++() { 

				m_ptr++;
				return *this;
			};

			const_Iterator operator++(int) {
				
				const_Iterator tmp = *this;
				++(*this);
				return tmp;
			};

			friend bool operator==(const_Iterator& const a, const_Iterator& const b) {
				
				return a.m_ptr == b.m_ptr;
			}
			
			friend bool operator!=(const_Iterator& const a, const_Iterator& const b) {
				
				return a.m_ptr != b.m_ptr;
			}			
			
			
			private:

				pointer m_ptr;			
		};

	    const const_Iterator begin() { return const_Iterator(&m_data[0]); }
    	const const_Iterator end() { return const_Iterator(&m_data[200]); } 	
		
};

int main() {
	
	Integers integers;
	
	for (auto i : integers)
	    std::cout << i << "\n";

	*integers.begin() = 8;
	*integers.begin() = 867;

	
	return 0;
}