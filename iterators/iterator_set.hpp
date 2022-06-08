/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_set.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:28:38 by tigerber          #+#    #+#             */
/*   Updated: 2022/06/08 20:01:41 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_SET_HPP
#define ITERATOR_SET_HPP

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
			struct NodeStruct2 {

				T pair;
				NodeStruct2 *left;
				NodeStruct2 *right;
				NodeStruct2 *parent;
				NodeStruct2 **root;
				NodeStruct2 **tNULL;
				
				int color;
			};

		/* ************************************************************************** */
		/*                          	Structur Check                                */
		/* ************************************************************************** */

			template<bool _const, typename type_const, typename type_normal>
			struct check_const_set;

			template<typename type_const, typename type_normal>
			struct check_const_set<true, type_const, type_normal> {

				typedef type_const type;
			};

			template<typename type_const, typename type_normal>
			struct check_const_set<false, type_const, type_normal> {

				typedef type_normal type;
			};
	
		/* ************************************************************************** */
		/*                         Iterator / Const Iterator: :                       */
		/* ************************************************************************** */
	
	template<class key, bool _const = false>
	class set_iterator {

		/* ************************************************************************** */
		/*                          Member type Definition                            */
		/* ************************************************************************** */			
		
		public:
		
			typedef set_iterator<key, _const> 																			Self;
    		typedef key																									value_type;
			typedef ptrdiff_t																							difference_type;
			typedef std::bidirectional_iterator_tag 																	iterator_category;
			typedef typename check_const_set<_const, const value_type&, value_type&>::type								reference;
			typedef typename check_const_set<_const, const value_type*, value_type*>::type								pointer;
			typedef typename check_const_set<_const, const NodeStruct2<value_type>*, NodeStruct2<value_type>* >::type		NodePtr;

		
		/* ************************************************************************** */
		/*                                Atribues                                    */
		/* ************************************************************************** */

			NodePtr		_pNode;

		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */
		
			set_iterator(void) : _pNode(NULL){};
		
			set_iterator(NodePtr n) :_pNode(n) {};

			set_iterator(const set_iterator<key, false> &copy) : _pNode(copy._pNode) {};
			set_iterator(const set_iterator<key, true> &copy) : _pNode(copy._pNode) {};
		
			virtual ~set_iterator() {};
			
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

				set_iterator res(*this);

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

				set_iterator res(*this);
				
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

		private:

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