#ifndef ITERATOR_MAP_HPP
#define ITERATOR_MAP_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>
#define BLACK 0 
#define RED 1

namespace ft {


	template <typename T>
	struct Node {

		T pair;
		Node *left;
		Node *right;
		Node *parent;
		int color;
	};

	template<class key, class T>
	class map_iterator {

		public:
		
		/* ************************************************************************** */
		/*                          Member type Definition                            */
		/* ************************************************************************** */			
		
			typedef map_iterator<key, T> 	Self;
    		typedef ft::pair<key, T>		value_type;
			typedef value_type&				reference;
			typedef value_type*				pointer;
			typedef Node<value_type>		Node;
			typedef Node*					NodePtr;
		
		/* ************************************************************************** */
		/*                                Atribues                                    */
		/* ************************************************************************** */

			NodePtr _pNode;

		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */
		
			map_iterator() : _pNode(NULL) {};
		
			map_iterator(Node* n) :_pNode(n) { };

			map_iterator(const map_iterator<key, T> &copy) : _pNode(copy._pNode) {};
		
			virtual ~map_iterator() {};
			
			Self   &operator = (const Self &rhs) {
				
				if (&rhs != this)
					_pNode = rhs._pNode;
				return *this;
			};

		/* ************************************************************************** */
		/*                                  operator:                                 */
		/* ************************************************************************** */

			reference operator*() const { return _pNode->pair; }
			
			pointer operator->() const { return &_pNode->pair; }

			Self& operator++() {

				_pNode = successor(_pNode);
				return *this;
			}
			
			Self operator++(int) {

				map_iterator res(*this);
				++(*this);
				return res;
			}
			
			Self& operator--() {

				_pNode = predecessor(_pNode);
				return *this;
			}
			
			Self operator--(int) {

				map_iterator res(*this);
				--(*this);
				return res;
			}
			
			bool operator==(const Self& s) {

				return _pNode == s._pNode;
			}
			
			bool operator!=(const Self& s) {
				
				return _pNode != s._pNode;
			}
		
		/* ************************************************************************** */
		/*                                  operator:                                 */
		/* ************************************************************************** */

			NodePtr minimum(NodePtr node) {
				
				while (node->left != NULL)
					node = node->left;
				return node;
			}

			NodePtr maximum(NodePtr node) {
				
				while (node->right != NULL)
					node = node->right;
				return node;
			}

			NodePtr successor(NodePtr x) {
				
				if (x->right != NULL)
					return minimum(x->right);

				NodePtr y = x->parent;
				while (y != NULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr predecessor(NodePtr x) {
				
				if (x->left != NULL)
					return maximum(x->left);

				NodePtr y = x->parent;
				while (y != NULL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}
	};
};

#endif