/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:28:38 by tigerber          #+#    #+#             */
/*   Updated: 2022/06/02 18:47:41 by tigerber         ###   ########.fr       */
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
			struct Node {

				T pair;
				Node *left;
				Node *right;
				Node *parent;
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
		
			typedef map_iterator<key, T, _const> 											Self;
    		typedef std::pair<key, T>													value_type;
			typedef ptrdiff_t																difference_type;
			typedef std::bidirectional_iterator_tag 										iterator_category;
			typedef typename check_const_map<_const, const value_type&, value_type&>::type	reference;
			typedef typename check_const_map<_const, const value_type*, value_type*>::type	pointer;
			// typedef Node<value_type>														Node;
			typedef typename check_const_map<_const, const Node<value_type>*, Node<value_type>* >::type	NodePtr;
		
		/* ************************************************************************** */
		/*                                Atribues                                    */
		/* ************************************************************************** */

			NodePtr		_pNode;
			NodePtr*	_root;
			NodePtr*	tNULL;

		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */
		
			map_iterator(void) : _pNode(NULL), _root(NULL), tNULL(NULL) {};
		
			map_iterator(NodePtr n, const NodePtr* TNULL, const NodePtr* root) :_pNode(n), _root(root), tNULL(TNULL) { };

			map_iterator(const map_iterator<key, T, false> &copy) : _pNode(copy._pNode), _root(copy._root), tNULL(copy.tNULL) {};
			map_iterator(const map_iterator<key, T, true> &copy) : _pNode(copy._pNode), _root(copy._root), tNULL(copy.tNULL) {};
		
			virtual ~map_iterator() {};
			
			Self   &operator = (const Self &rhs) {
				
				if (&rhs != this)
				{
					_pNode = rhs._pNode;
					_root = rhs._root;
					tNULL = rhs.tNULL;
				}
				return *this;
			};

		/* ************************************************************************** */
		/*                                  operator:                                 */
		/* ************************************************************************** */

			reference operator*() const { return _pNode->pair; }
			
			pointer operator->() const { return &_pNode->pair; }

			Self& operator++() {

				if (_pNode == maximum(*_root))
					_pNode = *tNULL;
				else
					_pNode = successor(_pNode);
				return *this;
			}
			
			Self operator++(int) {

				map_iterator res(*this);

				if (_pNode == maximum(*_root))
					_pNode = *tNULL;
				else
					_pNode = successor(_pNode);
				return res;
			}
			
			Self& operator--() {
				
				if (_pNode == minimum(*_root))
					_pNode = *tNULL;
				else if (_pNode == *tNULL)
					_pNode = maximum(*_root);
				else
					_pNode = predecessor(_pNode);
				return *this;
			}
			
			Self operator--(int) {

				map_iterator res(*this);
				
				if (_pNode == minimum(*_root))
					_pNode = *tNULL;
				else if (_pNode == *tNULL)
					_pNode = maximum(*_root);
				else
					_pNode = predecessor(_pNode);
				return res;
			}
			
			template <typename T1>
			bool operator==(const T1& s) {

				return _pNode == s._pNode;
			}

			
			// template <typename T1>
			bool operator!=(const Self& s) {
				
				return _pNode != s._pNode;
			}
		
		/* ************************************************************************** */
		/*                                    utils:                                  */
		/* ************************************************************************** */

			NodePtr minimum(NodePtr node) {
				
				while (node->left != *tNULL)
					node = node->left;
				return node;
			}

			NodePtr maximum(NodePtr node) {

				while (node->right != *tNULL)
					node = node->right;
				return node;
			}

			NodePtr successor(NodePtr x) {
				
				if (x->right != *tNULL)
					return minimum(x->right);

				NodePtr y = x->parent;
				while (y != *tNULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr predecessor(NodePtr x) {

				if (x->left != *tNULL)
					return maximum(x->left);

				NodePtr y = x->parent;
				while (y != *tNULL && x == y->left)
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