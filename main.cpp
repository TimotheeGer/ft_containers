/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:01:05 by tigerber          #+#    #+#             */
/*   Updated: 2022/05/13 17:18:32 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
#include <vector>
#include <map>
#include <type_traits>
#include "containers/map.hpp"

#include <list>

int main() {

	
	ft::map< int, int> tree;
	std::map<int, int> og;

	// tree.get_test();

	std::cout << "TEST" << std::endl;
	tree.insert_node(ft::pair< int, int>(0, 42));
	tree.insert_node(ft::pair< int, int>(1, 44));
	tree.insert_node(ft::pair< int, int>(2, 47));
	tree.insert_node(ft::pair< int, int>(3, 47));
	tree.insert_node(ft::pair< int, int>(4, 47));
	tree.insert_node(ft::pair< int, int>(5, 47));
	tree.insert_node(ft::pair< int, int>(6, 47));
	tree.insert_node(ft::pair< int, int>(7, 47));
	tree.insert_node(ft::pair< int, int>(8, 47));
	tree.insert_node(ft::pair< int, int>(9, 47));
	tree.insert_node(ft::pair< int, int>(10, 47));
	std::cout << "size = " << tree.size() << std::endl;
	tree.printTree();

	ft::map<int, int>::iterator tree_b = tree.begin();
	
	tree_b++;
	// tree_b--;
	std::cout << tree_b->first << " - " << tree_b->second << std::endl;


}
