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
		Node *tNULL;
		int color;
	};

	template<bool _const, typename type_const, typename type_normal>
	struct check_const;

	template<typename type_const, typename type_normal>
	struct check_const<true, type_const, type_normal> {

		typedef type_const type;
	};


	template<typename type_const, typename type_normal>
	struct check_const<false, type_const, type_normal> {

		typedef type_normal type;
	};

	template<class key, class T, bool _const = false>
	class map_iterator {

		public:
		
		/* ************************************************************************** */
		/*                          Member type Definition                            */
		/* ************************************************************************** */			
		
			typedef map_iterator<key, T> 												Self;
    		typedef ft::pair<key, T>													value_type;
			typedef typename check_const<_const, const value_type&, value_type&>::type	reference;
			typedef typename check_const<_const, const value_type*, value_type*>::type	pointer;
			typedef Node<value_type>													Node;
			typedef Node*																NodePtr;
		
		/* ************************************************************************** */
		/*                                Atribues                                    */
		/* ************************************************************************** */

			NodePtr	_pNode;
			NodePtr _root;
			NodePtr	tNULL;

		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */
		
			map_iterator() : _pNode(NULL), tNULL(NULL), _root(NULL) {};
		
			map_iterator(NodePtr n, NodePtr TNULL, NodePtr root) :_pNode(n) , tNULL(TNULL), _root(root) { };

			map_iterator(const map_iterator<key, T, false> &copy) : _pNode(copy._pNode), tNULL(copy.tNULL), _root(copy._root) {};
		
			virtual ~map_iterator() {};
			
			Self   &operator = (const Self &rhs) {
				
				if (&rhs != this)
				{
					_pNode = rhs._pNode;
					tNULL = rhs.tNULL;
					_root = rhs._root;
				}
				return *this;
			};

		/* ************************************************************************** */
		/*                                  operator:                                 */
		/* ************************************************************************** */

			reference operator*() const { return _pNode->pair; }
			
			pointer operator->() const { return &_pNode->pair; }

			Self& operator++() {

				if (_pNode == maximum(_root))
				{
					_pNode = tNULL;
				}
				else
				{
					_pNode = successor(_pNode);
				}
				return *this;
			}
			
			Self operator++(int) {
				std::cout << "----------------------------ITERATOR------------------------------------" << std::endl;
				std::cout << "PNODE = " << _pNode->pair.first << std::endl << std::flush;
				std::cout << "OP++ root = " << _root << std::endl << std::flush;
				std::cout << "MAXIMUM = " << maximum(_root)->pair.first << std::endl;
				std::cout << "MINIMUM = " << minimum(_root)->pair.first << std::endl;
				map_iterator res(*this);

				if (_pNode == maximum(_root))
				{
					std::cout << "OP++1" << std::endl << std::flush;
					_pNode = tNULL;
				}
				else
				{
					std::cout << "OP++2" << std::endl << std::flush;
					_pNode = successor(_pNode);
				}
				std::cout << "----------------------------/ITERATOR------------------------------------" << std::endl;
				return res;
			}
			
			Self& operator--() {

				if (_pNode == tNULL)
					_pNode = maximum(_root);
				else
					_pNode = predecessor(_pNode);
				return *this;
			}
			
			Self operator--(int) {

				map_iterator res(*this);
				if (_pNode == tNULL)
					_pNode = maximum(_root);
				else
					_pNode = predecessor(_pNode);
				return res;
			}
			
			bool operator==(const Self& s) {

				return _pNode == s._pNode;
			}
			
			bool operator!=(const Self& s) {
				
				return _pNode != s._pNode;
			}
		
		/* ************************************************************************** */
		/*                                    utils:                                  */
		/* ************************************************************************** */

			NodePtr minimum(NodePtr node) {
				
				std::cout << "NODE MIN = " << node->pair.first << std::endl;
				while (node->left != tNULL){
				std::cout << "YOOOOOOOOOO" << std::endl << std::flush;

					node = node->left;
				}
				return node;
			}

			NodePtr maximum(NodePtr node) {

				while (node->right != tNULL)
					node = node->right;
				return node;
			}

			NodePtr successor(NodePtr x) {
				
				if (x->right != tNULL)
					return minimum(x->right);

				NodePtr y = x->parent;
				while (y != tNULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr predecessor(NodePtr x) {

				if (x->left != tNULL)
					return maximum(x->left);

				NodePtr y = x->parent;
				while (y != tNULL && x == y->left)
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