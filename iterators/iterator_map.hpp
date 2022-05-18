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


	// template <typename T>
	// struct Node {

	// 	T pair;
	// 	Node *left;
	// 	Node *right;
	// 	Node *parent;
	// 	int color;
	// };

	template<class key, class T>
	class map_iterator {

		public:
			
			typedef map_iterator<key, T> 	Self;
    		typedef ft::pair<key, T>		value_type;
			typedef value_type&				reference;
			typedef value_type*				pointer;
			typedef Node<value_type>		Node;


			map_iterator() : _pNode(NULL) {};
		
			map_iterator(Node* n=nullptr) :_pNode(n) { };

			map_iterator(const map_iterator<key, T> &copy) : _pNode(copy._pNode) {};
		
			 Self   &operator = (const Self &rhs) {
				if (&rhs != this)
					_pNode = rhs._pNode;
				return *this;
				};

			virtual ~map_iterator() {};

			reference operator*() const { return _pNode->_pair; }
			
			pointer operator->() const { return &_pNode->_pair; }

			Self& operator++() {

				if (_pNode->right)
				{
					Node* temp = _pNode->right;
					while (temp->left) {
						temp = temp->left;
					}
					_pNode = temp;
				}
				else
				{
					Node* tmp = _pNode->parent;
					if (tmp->right==_pNode) {
						while (_pNode==tmp->right)
						{
							_pNode = tmp;
							tmp = tmp->parent;
						}
					}
					if (_pNode->right != tmp)
						_pNode = tmp;
				}
				return *this;
			}
			
			Self operator++(int) {

				Self tmp = *this;
				if (_pNode->right)
				{
					Node* temp = _pNode->right;
					while (temp->left) {
						temp = temp->left;
					}
					_pNode = temp;
				}
				else
				{
					Node* tmp = _pNode->parent;
					if (tmp->right==_pNode) {
						while (_pNode==tmp->right)
						{
							_pNode = tmp;
							tmp = tmp->parent;
						}
					}
					if (_pNode->right != tmp)
						_pNode = tmp;
				}
				return tmp;
			}
			
			Self& operator--() {

				Decrement();
				return *this;
			}
			
			Self operator--(int) {

				Self tmp = *this;
				Decrement();
				return tmp;
			}
			
			bool operator==(const Self& s) {

				return _pNode == s._pNode;
			}
			
			bool operator!=(const Self& s) {
				
				return _pNode != s._pNode;
			}

		
			// void Increment() {
				
			// 	if (_pNode->right)
			// 	{
			// 		Node* temp = _pNode->right;
			// 		while (temp->left) {
			// 			temp = temp->left;
			// 		}
			// 		_pNode = temp;
			// 	}
			// 	else
			// 	{
			// 		Node* tmp = _pNode->parent;
			// 		if (tmp->right==_pNode) {
			// 			while (_pNode==tmp->right)
			// 			{
			// 				_pNode = tmp;
			// 				tmp = tmp->parent;
			// 			}
			// 		}
			// 		if (_pNode->right != tmp)
			// 			_pNode = tmp;
			// 	}
			// }
			
			void Decrement() {
				
				if (_pNode->parent->parent == _pNode && _pNode->color== RED )
					_pNode = _pNode->left;

				else if (_pNode->left) 
				{
					while (_pNode->right)
					{
						_pNode = _pNode->right;
					}
				}
				else 
				{
					Node* parent = _pNode->parent;
					while (parent->left == _pNode)
					{
						_pNode = parent;
						parent = parent->parent;
					}
					_pNode = parent;
				}
			}


			Node* _pNode;


	};
		template <class key, class T>
		std::ostream &operator<<( std::ostream &o, map_iterator<key, T> const &rhs ) {

			o << rhs._pNode;
			return o;
		};
};

#endif