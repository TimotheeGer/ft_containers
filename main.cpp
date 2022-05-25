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

#define NAMESPACE ft

int main() {

	
	NAMESPACE::map< int, int> tree;
	std::map<int, int> og;

	// tree.get_test();

	// std::cout << "-----------------TEST-------------------" << std::endl;
	tree.insert(NAMESPACE::pair< int, int>(0, 42));
	tree.insert(NAMESPACE::pair< int, int>(1, 43));
	tree.insert(NAMESPACE::pair< int, int>(2, 44));
	tree.insert(NAMESPACE::pair< int, int>(3, 45));
	tree.insert(NAMESPACE::pair< int, int>(4, 46));
	tree.insert(NAMESPACE::pair< int, int>(5, 47));
	tree.insert(NAMESPACE::pair< int, int>(6, 48));
	tree.insert(NAMESPACE::pair< int, int>(7, 49));
	tree.insert(NAMESPACE::pair< int, int>(8, 50));
	tree.insert(NAMESPACE::pair< int, int>(9, 51));
	tree.insert(NAMESPACE::pair< int, int>(10, 52));
	// std::cout << "size = " << tree.size() << std::endl;
	//tree.printTree();



	NAMESPACE::map<int, int>::iterator tree_b = tree.begin();

	std::cout << "begin = " << tree_b->first << " - " << tree_b->second << std::endl;

	NAMESPACE::map<int, int>::iterator tree_e = tree.end();
	// // --tree_e;
	std::cout << "end = " << tree_e->first << " - " << tree_e->second << std::endl;


	// std::cout << std::endl
    //  << "After deleting" << std::endl;
	// std::cout << "Root main = " << tree.get_root() << std::endl;
	// std::cout << "-------------------------------------------------" << std::endl;
	
	NAMESPACE::map<int, int>::iterator tmp;
	int i = 0;
	while (i < 10)
	{
		// std::cout << tree_b->first << " - " << tree_b->second << std::endl;
		//tmp = tree_b;
		//std::cout << "adress node tmp = " << tmp.get_adrs() << " - " << tmp->first << std::endl;
		tree_b++;
		//std::cout << "adress node     = " << tree_b.get_adrs() << " - " << tree_b->first << std::endl << std::flush;
		tree.erase(i);
		i++;
	}
	
	// tree.erase(0);
	// tree.erase(1);
	// tree.erase(2);
	// tree.erase(3);
	// tree.erase(4);

	// tree.erase(tree_b, tree_e);
	// std::cout <<  "MAX MAIN = " << tree.get_max() << std::endl;
	// // tree.erase(tree_b);
	// // tree.erase(tree_e);
	// std::cout << "TEST ERASE " << std::endl;

	// tree.printTree();

	// std::cout << "TEST00" << std::endl;
	// tree_b--;
}
