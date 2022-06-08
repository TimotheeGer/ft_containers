/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:28:45 by tigerber          #+#    #+#             */
/*   Updated: 2022/06/08 20:07:59 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>
#include "./color.hpp"
#include "../iterators/utils.hpp"
#include "../iterators/iterator_map.hpp"
#include "../iterators/reverse_iterator.hpp"

#define BLACK 0 
#define RED 1


namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {

		/* ************************************************************************** */
		/*                          Member type Definition                            */
		/* ************************************************************************** */
		
		public:
			
			typedef Key 											key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type> 			value_type;
			typedef Compare 										key_compare;
			typedef Alloc											allocator_type;

			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;

			typedef ptrdiff_t										difference_type;
    		typedef size_t											size_type;
			typedef NodeStruct<value_type>							Node;
			typedef NodeStruct<value_type>*							NodePtr;
    		
			typedef ft::map_iterator<key_type, mapped_type, false>	iterator;
    		typedef ft::map_iterator<key_type, mapped_type, true>	const_iterator;
    		typedef ft::reverse_iterator<iterator>                	reverse_iterator;
    		typedef ft::reverse_iterator<const_iterator>          	const_reverse_iterator;

		/* ************************************************************************** */
		/*                               Atribues Class                               */
		/* ************************************************************************** */

		private:
			
			class value_compare
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;

				protected:

					Compare comp;
					value_compare (Compare c) : comp(c) {};
				
				public:

					bool operator()(const value_type & x, const value_type & y) const {

						return (comp(x.first, y.first));
					};
			};

		/* ************************************************************************** */
		/*                                Atribues                                    */
		/* ************************************************************************** */

		private:
		
			typename allocator_type::template rebind<Node>::other alloc_node;

			NodePtr 											root;
			NodePtr 											TNULL;

			allocator_type										_alloc;
			size_type											_size;
			key_compare											_comp;

		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */

		public:

			// empty (1)	
			explicit map (const key_compare& comp = key_compare(),
			              const allocator_type& alloc = allocator_type()) {

				_alloc = alloc;
				_comp = comp;
				_size = 0;

				TNULL = alloc_node.allocate(1);
				TNULL->color = BLACK;
				TNULL->left = NULL;
				TNULL->right = NULL;
				TNULL->parent = TNULL;
				TNULL->root = &root;
				TNULL->tNULL = &TNULL;
				// _alloc.construct(&TNULL->pair, ft::pair<key_type, mapped_type>(_size, 0));
				root = TNULL;
				_alloc.construct(&root->pair, value_type());
			
			}

			// range (2)	
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) {
				
				_alloc = alloc;
				_comp = comp;
				_size = 0;

				TNULL = alloc_node.allocate(1);
				TNULL->color = BLACK;
				TNULL->left = NULL;
				TNULL->right = NULL;
				TNULL->parent = TNULL;
				TNULL->root = &root;
				TNULL->tNULL = &TNULL;
				root = TNULL;
				_alloc.construct(&root->pair, value_type());

				insert(first, last);				
			};
			
			// copy (3)	
			map (const map& x) {
				
				_alloc = x._alloc;
				_comp = x._comp;
				_size = 0;
				
				TNULL = alloc_node.allocate(1);
				TNULL->color = BLACK;
				TNULL->left = NULL;
				TNULL->right = NULL;
				TNULL->parent = TNULL;
				TNULL->root = &root;
				TNULL->tNULL = &TNULL;
				root = TNULL;
				_alloc.construct(&root->pair, value_type());
				
				insert(x.begin(), x.end());
			};

			// copy (1)	
			map& operator = (const map& x) {

		
				clear();
				insert(x.begin(), x.end());
				return (*this);
			};

			// Destructor(1)
			~map() {

				if (root == TNULL)
				{
					_size = 0;
					deallocate_node(TNULL);
					return ;
				}
				
				if (_size > 0)
					clear();
				_size = 0;
				deallocate_node(TNULL);
			};

		/* ************************************************************************** */
		/*                                 Iterator:                                  */
		/* ************************************************************************** */

			iterator begin()						{ return iterator(minimum(root)); };
			const_iterator begin() const			{ return iterator(minimum(root)); };
			
			iterator end() 							{ return iterator(TNULL); };
			const_iterator end() const				{ return iterator(TNULL); };
			
			reverse_iterator rbegin() 				{ return reverse_iterator(end()); };
			const_reverse_iterator rbegin() const 	{ return const_reverse_iterator(end()); };
			
			reverse_iterator rend() 				{ return reverse_iterator(begin()); };
			const_reverse_iterator rend() const 	{ return const_reverse_iterator(begin()); }; 


		/* ************************************************************************** */
		/*                                 Capacity:                                  */
		/* ************************************************************************** */

			bool 		empty() const { return (size() == 0); };

			size_type	size() const { return _size; };

			size_type max_size() const { return _alloc.max_size(); };

		/* ************************************************************************** */
		/*                            	 Element Access:                              */
		/* ************************************************************************** */

			mapped_type& operator[] (const key_type& k){

				NodePtr tmp = searchTreeKey(root, k);

				if (tmp == TNULL)
				{
					insert(ft::make_pair(k, mapped_type()));
					tmp = searchTreeKey(root, k);
				}
				return (tmp->pair.second);
			};

		/* ************************************************************************** */
		/*                            		 Modifiers:                               */
		/* ************************************************************************** */


			// single element (1)	
			pair<iterator,bool> insert (const value_type& val) {
								
				NodePtr exist = searchTreeKey(root, val.first);

				if (exist == TNULL)
				{
					iterator tmp = iterator(insert_node(val));
					return ft::make_pair<iterator, bool>(tmp, true);
				}
				return ft::make_pair<iterator, bool>(iterator(exist), false);
			};

			// with hint (2)	
			iterator insert (iterator position, const value_type& val) {

				(void)position;
				return (insert(val).first);
			};

			// range (3)	
			template <class InputIterator>
			  void insert (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {

				  while (first != last)
				  {
					  insert(*first);
					  ++first;
				  }
			  };

			// (1)	
			void erase (iterator position) {

				deleteNodeHelper(root, position->first);
			};
			
			// (2)	
			size_type erase (const key_type& k) {
				
				NodePtr exist = searchTreeKey(root, k);

				if (exist != TNULL)
				{
					deleteNodeHelper(root, k);
					return 1;
				}
				return 0;
			};
			
			// (3)	
			void erase (iterator first, iterator last) {

				iterator	tmp;

				while (first != last)
				{
					tmp = first++;
					erase(tmp);
				}
			};

			void swap (map& x) {

				NodePtr tmp_root;
				NodePtr tmp_tnull;
				size_type tmp_size;
				
				tmp_size = _size;
				_size = x._size;
				x._size = tmp_size;

				tmp_root = root;
				root = x.root;
				x.root = tmp_root;

				tmp_tnull = TNULL;
				TNULL = x.TNULL;
				x.TNULL = tmp_tnull;
				
				x.update_root_tnull(x.root);
				update_root_tnull(root);
			};




			void clear() {

				delete_tree(root);
				root = TNULL;
				_size = 0;
			};



		/* ************************************************************************** */
		/*                             		Observers:                                */
		/* ************************************************************************** */


			key_compare key_comp() const {

				return (key_compare());
			};


			value_compare value_comp() const {

				return (value_compare(key_compare()));
			};


		/* ************************************************************************** */
		/*                            		Operations:                               */
		/* ************************************************************************** */


			iterator find (const key_type& k) {

				NodePtr tmp = searchTreeKey(root, k);
				
				if (tmp != TNULL)
					return (iterator(tmp));
				else
					return (end()); 
			};

			const_iterator find (const key_type& k) const {
				
				NodePtr tmp = searchTreeKey(root, k);
				
				if (tmp != TNULL)
					return (iterator(tmp));
				else
					return (end());
			};

			size_type count (const key_type& k) const {

				return (searchTreeKey(root, k) != TNULL);
			};


			iterator lower_bound (const key_type& k) {

				iterator itb = begin();
				iterator ite = end();

				while (itb != ite)
				{
					if (_comp((*itb).first, k) == false)
						break;
					itb++;
				}
				return (itb);
			};

			const_iterator lower_bound (const key_type& k) const {

				const_iterator itb = begin();
				const_iterator ite = end();

				while (itb != ite)
				{
					if (_comp((*itb).first, k) == false)
						break;
					itb++;
				}
				return (itb);				
			};

			iterator upper_bound (const key_type& k) {

				iterator itb = begin();
				iterator ite = end();

				while (itb != ite)
				{
					if (_comp(k, (*itb).first))
						break;
					itb++;
				}
				return (itb);
			};
			const_iterator upper_bound (const key_type& k) const {

				const_iterator itb = begin();
				const_iterator ite = end();

				while (itb != ite)
				{
					if (_comp(k, (*itb).first))
						break;
					itb++;
				}
				return (itb);
			};

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {

				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};

			pair<iterator,iterator>             equal_range (const key_type& k) {

				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};

		/* ************************************************************************** */
		/*                           		Allocator:                                */
		/* ************************************************************************** */


			allocator_type get_allocator() const {

				return allocator_type();
			};

		
		/* ************************************************************************** */
		/*                           		  Utils:                                  */
		/* ************************************************************************** */
		
		private:
		
		/* ************************************************************************** */
		/*                           		 get/set:                                 */
		/* ************************************************************************** */
		
			NodePtr		get_root() const { return root; };
			NodePtr		get_tnull() const { return TNULL; };
			size_type	get_size() const { return size(); };

			void		set_root(NodePtr p_root) { root = p_root; };
			void		set_size(size_type size) { _size = size; };

			void update_root_tnull(NodePtr n)
			{
				if(n->left)
					update_root_tnull(n->left);
				if(n->right)
					update_root_tnull(n->right);
				n->root = &root;
				n->tNULL = &TNULL;
			}

		/* ************************************************************************** */
		/*                           		 insert:                                  */
		/* ************************************************************************** */

			void leftRotate(NodePtr x) {
			
				NodePtr y = x->right;
				x->right = y->left;
				if (y->left != TNULL)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL)
					this->root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			};

			void rightRotate(NodePtr x) {
				
				NodePtr y = x->left;
				x->left = y->right;
				if (y->right != TNULL)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL)
					this->root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			};

			void insertFix(NodePtr k) {
			
				NodePtr u;
				while (k->parent->color == RED)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						} 
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								rightRotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							leftRotate(k->parent->parent);
						}
					} 
					else 
					{
						u = k->parent->parent->right;
						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						} 
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								leftRotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							rightRotate(k->parent->parent);
						}
					}
					if (k == root)
						break;
				}
				root->color = BLACK;
			};

			NodePtr insert_node(const value_type& val) {
				
				NodePtr node = alloc_node.allocate(1);
				node->color = RED;
				node->parent = NULL;
				node->left = TNULL;
				node->right = TNULL;
				node->tNULL = &TNULL;
				_alloc.construct(&node->pair, val);
				// _alloc.destroy(&TNULL->pair);
				// _alloc.construct(&TNULL->pair, ft::pair<key_type, mapped_type>(_size + 1, 0));

				_size++;

				NodePtr y = NULL;
				NodePtr x = this->root;

				while (x != TNULL)
				{
					y = x;
					if (_comp(node->pair.first, x->pair.first))
						x = x->left;
					else 
						x = x->right;
				}

				node->parent = y;

				if (y == NULL)
					root = node;
				else if (_comp(node->pair.first, y->pair.first))
					y->left = node;
				else 
					y->right = node; 

				if (node->parent == NULL) { node->root = &root; node->color = 0; return node; }

				if (node->parent->parent == NULL) { node->root = &root; return node; }
    			
				insertFix(node);
				node->root = &root;
				return node;
			};

		/* ************************************************************************** */
		/*                           		 delete:                                  */
		/* ************************************************************************** */
 
			void deleteFix(NodePtr x) {
				
				NodePtr s;
				while (x != root && x->color == BLACK)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							leftRotate(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						} 
						else
						{
							if (s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								rightRotate(s);
								s = x->parent->right;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							leftRotate(x->parent);
							x = root;
						}
					} 
					else 
					{
						s = x->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							rightRotate(x->parent);
							s = x->parent->left;
						}
						if (s->right->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else 
						{
							if (s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = RED;
								leftRotate(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							rightRotate(x->parent);
							x = root;
						}
					}
				}
				x->color = BLACK;
			}

			void rbTransplant(NodePtr u, NodePtr v) {
				
				if (u->parent == NULL)
					root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			void deleteNodeHelper(NodePtr node, key_type key) {
				
				NodePtr z = TNULL;
				NodePtr x, y;
				while (node != TNULL)
				{
					if (node->pair.first == key)
						z = node;
					if (node->pair.first <= key)
						node = node->right;
					else
						node = node->left;
				}
				if (z == TNULL)
					return;

				y = z;
				int y_original_color = y->color;
				if (z->left == TNULL)
				{
					x = z->right;
					rbTransplant(z, z->right);
				} 
				else if (z->right == TNULL)
				{
					x = z->left;
					rbTransplant(z, z->left);
				} 
				else
				{
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z)
						x->parent = y;
					else 
					{
						rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				
				deallocate_node(z);
				_size--;
				
				if (y_original_color == BLACK)
					deleteFix(x);
			}

			void deleteNode(value_type data) {
				
				deleteNodeHelper(root, data);
				_size--;
			}

			void	deallocate_node(NodePtr node)
			{
				_alloc.destroy(&node->pair);
				alloc_node.deallocate(node, 1);
			}

			void	delete_tree( NodePtr p )
			{
				if (p != TNULL)
				{
					delete_tree(p->left);
					delete_tree(p->right);
					deallocate_node(p);
					_size--;
				}
			}

		/* ************************************************************************** */
		/*                           		 Min/Max:                                 */
		/* ************************************************************************** */
		
			NodePtr minimum(NodePtr node) const {
    			
				if (node == TNULL)
					return node;
				while (node->left != TNULL)
    				node = node->left;
    			return node;
  			}

			NodePtr maximum(NodePtr node) {
				
   				if (node == TNULL)
					return node;
				while (node->right != TNULL)
      				node = node->right;
    			return node;
  			}

			int get_max() {

				return (maximum(root)->pair.first);
			}
		
		/* ************************************************************************** */
		/*                           		 search:                                  */
		/* ************************************************************************** */

			NodePtr searchTreeKey(NodePtr node, const key_type& key) const {
    
				
				if (node == TNULL || key == node->pair.first)
      				return node;
    			if (_comp(key, node->pair.first))
    				return searchTreeKey(node->left, key);
    			return searchTreeKey(node->right, key);
  			}

		/* ************************************************************************** */
		/*                              Print Helper:                                 */
		/* ************************************************************************** */

			void printHelper(NodePtr root, std::string indent, bool last) {
				
				if (root != TNULL)
				{
					std::cout << indent;
					if (last) 
					{
						std::cout << "R----";
						indent += "   ";
					} 
					else 
					{
						std::cout << "L----";
						indent += "|  ";
					}

					std::string sColor = root->color ? "\033[31mRED\033[0m" : "\033[30mBLACK\033[0m";
					std::cout << "[" << C_YELLOW <<root->pair.first << C_RESET << "/" 
								     << C_GREEN << root->pair.second << C_RESET << "](" << sColor << ")" << std::endl;
					printHelper(root->left, indent, false);
					printHelper(root->right, indent, true);
				}
  			}
		
		// public:

		// 	void printTree() {
    			
		// 		if (root) { printHelper(this->root, "", true); }
  		// 	}		
	};

		/* ************************************************************************** */
		/*                       Non-member function overloads                        */
		/* ************************************************************************** */
		
		template< class Key, class T, class Compare, class Alloc >
		bool operator == ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
			
			typename ft::map<Key,T,Compare,Alloc>::const_iterator first = rhs.begin();
			typename ft::map<Key,T,Compare,Alloc>::const_iterator last = rhs.end();
			typename ft::map<Key,T,Compare,Alloc>::const_iterator cursor = lhs.begin();

			if (lhs.size() != rhs.size())
				return (false);
			return (ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }

		template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
			
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (!(rhs < lhs)); }

		template< class Key, class T, class Compare, class Alloc >
		bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (rhs < lhs); }
	
		template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (!(rhs > lhs)); }

		template< class Key, class T, class Compare, class Alloc >
		void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ) { lhs.swap(rhs); }

};

#endif
