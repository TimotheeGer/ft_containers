/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:28:38 by tigerber          #+#    #+#             */
/*   Updated: 2022/06/03 18:52:16 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
#define ITERATOR_MAP_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>
#include "./utils.hpp"

#define BLACK 0 
#define RED 1

namespace ft {
		
		/* ************************************************************************** */
		/*                          	Structur Node                            	  */
		/* ************************************************************************** */
			
			template <typename T>
			struct NodeStruct {

				T pair;
				NodeStruct *left;
				NodeStruct *right;
				NodeStruct *parent;
				NodeStruct **root;
				NodeStruct **tNULL;
				
				int color;
			};
			
		/* ************************************************************************** */
		/*                          	Structur Check                                */
		/* ************************************************************************** */

			template<bool _const, typename type_const, typename type_normal>
			struct check_const_map;

			template<typename type_const, typename type_normal>
			struct check_const_map<true, type_const, type_normal> {

				typedef type_const type;
			};

			template<typename type_const, typename type_normal>
			struct check_const_map<false, type_const, type_normal> {

				typedef type_normal type;
			};
	
		/* ************************************************************************** */
		/*                         Iterator / Const Iterator: :                       */
		/* ************************************************************************** */
	
	template<class key, class T, bool _const = false>
	class map_iterator {

		/* ************************************************************************** */
		/*                          Member type Definition                            */
		/* ************************************************************************** */			
		
		public:
		
			typedef map_iterator<key, T, _const> 																		Self;
    		typedef ft::pair<const key, T>																				value_type;
			typedef ptrdiff_t																							difference_type;
			typedef std::bidirectional_iterator_tag 																	iterator_category;
			typedef typename check_const_map<_const, const value_type&, value_type&>::type								reference;
			typedef typename check_const_map<_const, const value_type*, value_type*>::type								pointer;
			typedef typename check_const_map<_const, const NodeStruct<value_type>*, NodeStruct<value_type>* >::type		NodePtr;

		
		/* ************************************************************************** */
		/*                                Atribues                                    */
		/* ************************************************************************** */

			NodePtr		_pNode;

		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */
		
			map_iterator(void) : _pNode(NULL){};
		
			map_iterator(NodePtr n) :_pNode(n) {};

			map_iterator(const map_iterator<key, T, false> &copy) : _pNode(copy._pNode) {};
			map_iterator(const map_iterator<key, T, true> &copy) : _pNode(copy._pNode) {};
		
			virtual ~map_iterator() {};
			
			Self   &operator = (const Self &rhs) {
				
				if (&rhs != this)
				{
					_pNode = rhs._pNode;
				}
				return *this;
			};

		/* ************************************************************************** */
		/*                                  operator:                                 */
		/* ************************************************************************** */

			reference operator*() const { return _pNode->pair; }
			
			pointer operator->() const { return &_pNode->pair; }

			Self& operator++() {

				if (_pNode == maximum(*_pNode->root))
					_pNode = *_pNode->tNULL;
				else
					_pNode = successor(_pNode);
				return *this;
			}
			
			Self operator++(int) {

				map_iterator res(*this);

				if (_pNode == maximum(*_pNode->root))
					_pNode = *_pNode->tNULL;
				else
					_pNode = successor(_pNode);
				return res;
			}
			
			Self& operator--() {
				
				if (_pNode == minimum(*_pNode->root))
					_pNode = *_pNode->tNULL;
				else if (_pNode == *_pNode->tNULL)
					_pNode = maximum(*_pNode->root);
				else
					_pNode = predecessor(_pNode);
				return *this;
			}
			
			Self operator--(int) {

				map_iterator res(*this);
				
				if (_pNode == minimum(*_pNode->root))
					_pNode = *_pNode->tNULL;
				else if (_pNode == *_pNode->tNULL)
					_pNode = maximum(*_pNode->root);
				else
					_pNode = predecessor(_pNode);
				return res;
			}
			
			template <typename T1>
			bool operator==(const T1& s) const {

				return _pNode == s._pNode;
			}

			
			template <typename T1>
			bool operator!=(const T1& s) const {
				
				return _pNode != s._pNode;
			}
		
		/* ************************************************************************** */
		/*                                    utils:                                  */
		/* ************************************************************************** */

			NodePtr minimum(NodePtr node) {
								
				while (node->left != *_pNode->tNULL)
					node = node->left;
				return node;
			}

			NodePtr maximum(NodePtr node) {

				while (node->right != *_pNode->tNULL)
					node = node->right;
				return node;
			}

			NodePtr successor(NodePtr x) {
								
				if (x->right != *_pNode->tNULL)
					return minimum(x->right);

				NodePtr y = x->parent;
				while (y != *_pNode->tNULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr predecessor(NodePtr x) {
								
				if (x->left != *_pNode->tNULL)
					return maximum(x->left);

				NodePtr y = x->parent;
				while (y != *_pNode->tNULL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr get_adrs() {

				return (_pNode);
			}
	};
};

#endif