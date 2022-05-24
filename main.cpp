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

	std::cout << "-----------------TEST-------------------" << std::endl;
	tree.insert_node(ft::pair< int, int>(0, 42));
	tree.insert_node(ft::pair< int, int>(1, 43));
	tree.insert_node(ft::pair< int, int>(2, 44));
	tree.insert_node(ft::pair< int, int>(3, 45));
	tree.insert_node(ft::pair< int, int>(4, 46));
	tree.insert_node(ft::pair< int, int>(5, 47));
	tree.insert_node(ft::pair< int, int>(6, 48));
	tree.insert_node(ft::pair< int, int>(7, 49));
	tree.insert_node(ft::pair< int, int>(8, 50));
	tree.insert_node(ft::pair< int, int>(9, 51));
	tree.insert_node(ft::pair< int, int>(10, 52));
	std::cout << "size = " << tree.size() << std::endl;
	tree.printTree();

	ft::map<int, int>::iterator tree_b = tree.begin();
	tree_b++;
	tree_b++;
	tree_b++;
	std::cout << "begin = " << tree_b->first << " - " << tree_b->second << std::endl;

	ft::map<int, int>::iterator tree_e = tree.end();
	// tree_e--;
	// // tree_e--;
	// std::cout << "end = " << tree_e->first << " - " << tree_e->second << std::endl;

	// while (tree_b != tree_e)
	// {
	// 	std::cout << tree_b->first << " - " << tree_b->second << std::endl;
	// 	tree_b++;
	// }
		// std::cout << tree_b->first << " - " << tree_b->second << std::endl;
		// tree_b++;

	tree.erase(tree_b);
	std::cout << "TEST ERASE " << std::endl;

	tree.printTree();

	std::cout << "TEST00" << std::endl;
	// tree_b--;


}
