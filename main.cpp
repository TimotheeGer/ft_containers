/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:01:05 by tigerber          #+#    #+#             */
/*   Updated: 2022/06/01 15:19:28 by tigerber         ###   ########.fr       */
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
#include "containers/vector.hpp"

#include <list>

#define NAMESPACE std

int main() {

	NAMESPACE::map< int, int> tree;
	NAMESPACE::vector< int > vec;
	std::map<int, int> og;

	// tree.get_test();

	std::cout << "-----------------TEST-------------------" << std::endl;
	
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	
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
	tree.insert(NAMESPACE::pair< int, int>(98, 52));
	// std::cout << "size = " << tree.size() << std::endl;
	// tree.printTree();


	std::cout << "------------------------------------------" << std::endl;

	NAMESPACE::map<int, int>::iterator tree_b = tree.begin();
	NAMESPACE::map<int, int>::iterator tree_e = tree.end();
	NAMESPACE::map<int, int>::const_iterator const_tree_b = tree.begin();
	NAMESPACE::map<int, int>::const_iterator const_tree_e = tree.end();
	NAMESPACE::map<int, int>::reverse_iterator tree_rb = tree.rbegin();
	NAMESPACE::map<int, int>::reverse_iterator tree_re = tree.rend();
	NAMESPACE::map<int, int>::const_iterator tree_bc = tree.begin();
	NAMESPACE::map<int, int>::iterator ite = tree.end();
	NAMESPACE::map<int, int>::const_iterator it[2];
	
	it[0] = tree.lower_bound(-1);
	std::cout << "IT = "<< it[0]->first << std::endl;
	it[1] = tree_e;
	
	if (it[0] == ite)
		std::cout << "OK" << std::endl;
	
	// NAMESPACE::vector<int>::iterator vec_b = vec.begin();
	// NAMESPACE::vector<int>::iterator vec_e = vec.end();
	// NAMESPACE::vector<int>::reverse_iterator vec_rb = vec.rbegin();
	// NAMESPACE::vector<int>::reverse_iterator vec_re = vec.rend();
	// NAMESPACE::vector<int>::const_iterator vec_bc = vec.begin();

	// tree_b->first = 53;
	// --tree_e;
	// --tree_re;
	// ++tree_re;
	// --vec_re;
	// --vec_re;
	// tree_rb++;

	std::cout << "begin = " << tree_b->first << " - " << tree_b->second << std::endl;
	std::cout << "end = " << tree_e->first << " - " << tree_e->second << std::endl;
	std::cout << "rbegin = " << tree_rb->first << " - " << tree_rb->second << std::endl;
	std::cout << "rend = " << tree_re->first << " - " << tree_re->second << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	// std::cout << "VEC = begin = " << *vec_b <<  std::endl;
	// std::cout << "VEC = end = " << *vec_e << std::endl;
	// std::cout << "VEC = rbegin = " << *vec_rb << std::endl;
	// std::cout << "VEC = rend = " << *vec_re << std::endl;
	
	// std::cout << "rend = " << tree_re->first  << std::endl;
	// std::cout << "begin const = " << tree_bc->first << " - " << tree_bc->second << std::endl;

	// --tree_e;
	// std::cout << "end = " << tree_e->first << " - " << tree_e->second << std::endl;
	// tree.erase(tree_b, tree_e);
	// tree.clear();


	// tree.insert(NAMESPACE::pair< int, int>(0, 42));
	// tree.insert(NAMESPACE::pair< int, int>(1, 43));
	// tree.insert(NAMESPACE::pair< int, int>(2, 44));
	// tree.insert(NAMESPACE::pair< int, int>(3, 45));
	// tree.insert(NAMESPACE::pair< int, int>(4, 46));
	// tree.insert(NAMESPACE::pair< int, int>(5, 47));
	// tree.insert(NAMESPACE::pair< int, int>(6, 48));
	// tree.insert(NAMESPACE::pair< int, int>(7, 49));
	// tree.insert(NAMESPACE::pair< int, int>(8, 50));
	// tree.insert(NAMESPACE::pair< int, int>(9, 51));
	// tree.insert(NAMESPACE::pair< int, int>(10, 52));

	std::cout << "------------------------------------------" << std::endl;
	// std::cout << std::endl
    //  << "After deleting" << std::endl;
	// std::cout << "Root main = " << tree.get_root()->pair.first << std::endl;
	

	
	// tree.erase(0);
	// tree.erase(1);
	// tree.erase(2);
	// tree.erase(3);
	// tree.erase(4);
	// tree.erase(5);
	// tree.erase(6);
	// tree.erase(7);
	// tree.erase(8);
	// tree.erase(9);
	// tree.erase(10);
	std::cout << "size = " << tree.size() << std::endl;

	// std::cout <<  "MAX MAIN = " << tree.get_max() << std::endl;
	// // tree.erase(tree_b);
	// // tree.erase(tree_e);
	// std::cout << "TEST ERASE " << std::endl;

	// tree.printTree();

	// std::cout << "TEST00" << std::endl;
	// tree_b--;
}
