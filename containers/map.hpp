#ifndef MAP_HPP
#define MAP_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>
#include "../iterators/utils.hpp"
#include "../iterators/iterator_map.hpp"
// #include "../iterators/rbt_iterator.hpp"
#define BLACK 0 
#define RED 1


namespace ft {


	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key,T>> >
	class map {


		public:

		/* ************************************************************************** */
		/*                          Member type Definition                            */
		/* ************************************************************************** */
			typedef Key 											key_type;
			typedef T												mapped_type;
			typedef ft::pair<key_type, mapped_type> 				value_type;
			typedef Compare 										key_compare;
			typedef Alloc											allocator_type;

			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;

			typedef ptrdiff_t										difference_type;
    		typedef size_t											size_type;
			typedef Node<value_type>								Node;
			typedef Node*											NodePtr;
    		
			typedef ft::map_iterator<key_type, mapped_type, false>	iterator;
    		// typedef ft::map_iterator<key_type, mapped_type, true>	const_iterator;
    		// typedef ft::reverse_iterator<iterator>                	reverse_iterator;
    		// typedef ft::reverse_iterator<const_iterator>          	const_reverse_iterator;


		private:

		/* ************************************************************************** */
		/*                                Atribues                                    */
		/* ************************************************************************** */
		
			typename allocator_type::template rebind<Node>::other alloc_node;

			NodePtr 											root;
			NodePtr 											TNULL;

			allocator_type										_alloc;
			size_type											_size;
			key_compare											_comp;

		public:

		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */

			// empty (1)	
			explicit map (const key_compare& comp = key_compare(),
			              const allocator_type& alloc = allocator_type()) {

				_alloc = alloc;
				_comp = comp;
				_size = 0;

				TNULL = alloc_node.allocate(1);
				TNULL->color = BLACK;
				TNULL->left = nullptr;
				TNULL->right = nullptr;
				TNULL->parent = TNULL;
				root = TNULL;

				_alloc.construct(&root->pair, value_type());
			
			}

			void get_test() {

				std::cout << "first = "<< root->pair.first << std::endl;
				std::cout << "second = " << root->pair.second << std::endl;
				std::cout << "Color = " << root->color << std::endl;
				std::cout << "left = " << root->left << std::endl;
				std::cout << "right = " << root->right << std::endl;
				std::cout << "parent = " << root->parent << std::endl;

			}


			// range (2)	
			// template <class InputIterator>
			//   map (InputIterator first, InputIterator last,
			//        const key_compare& comp = key_compare(),
			//        const allocator_type& alloc = allocator_type());
			// copy (3)	
			// map (const map& x);

			// copy (1)	
			//  map& operator= (const map& x);

			// Destructor(1)
			// ~map();

		/* ************************************************************************** */
		/*                                 Iterator:                                  */
		/* ************************************************************************** */

			iterator begin()				{ return iterator(minimum(root), TNULL, root); };
			// const_iterator begin() const	{ return iterator(minimum(root), TNULL); };
			
			iterator end() 					{ return iterator(TNULL, TNULL, root); };
			// const_iterator end() const;
			
			//reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			
			// reverse_iterator rend();
			// const_reverse_iterator rend() const; 


		/* ************************************************************************** */
		/*                                 Capacity:                                  */
		/* ************************************************************************** */


			bool 		empty() const { return (size() == 0); };

			size_type	size() const { return _size; };

			size_type max_size() const { return _alloc.max_size(); };

		/* ************************************************************************** */
		/*                            	 Element Access:                              */
		/* ************************************************************************** */

			//mapped_type& operator[] (const key_type& k);

		/* ************************************************************************** */
		/*                            		 Modifiers:                               */
		/* ************************************************************************** */


			// single element (1)	
			pair<iterator,bool> insert (const value_type& val) {

				NodePtr exist = searchTree(root, val);

				if (exist == TNULL)
				{
					return ft::make_pair<iterator, bool>(iterator(insert_node(val), TNULL, root), true);
				}
				return ft::make_pair<iterator, bool>(iterator(exist, TNULL, root), false);

			};

			// with hint (2)	
			iterator insert (iterator position, const value_type& val) {

				(void)position;
				return (insert(val).first);
			};

			// range (3)	
			template <class InputIterator>
			  void insert (InputIterator first, InputIterator last) {

				  while (first != last)
				  {
					  insert(*first);
					  ++first;
				  }
			  };


			// (1)	
			void erase (iterator position) {

				delete_n(*position);
			};
			// (2)	
			// 		size_type erase (const key_type& k);
			// (3)	
			//      void erase (iterator first, iterator last);

			// void swap (map& x);

			// void clear();

		/* ************************************************************************** */
		/*                             		Observers:                                */
		/* ************************************************************************** */


			// key_compare key_comp() const;


			// value_compare value_comp() const;


		/* ************************************************************************** */
		/*                            		Operations:                               */
		/* ************************************************************************** */


			//    iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;

			// size_type count (const key_type& k) const;


			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;

			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;

			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// pair<iterator,iterator>             equal_range (const key_type& k);



			NodePtr get_root() const { return root->parent; };
			// Tree get_left() const { return root->left; };
			// Tree get_right() const { return root->right; };


		/* ************************************************************************** */
		/*                           		Allocator:                                */
		/* ************************************************************************** */


			// allocator_type get_allocator() const;
		
		/* ************************************************************************** */
		/*                           		  Utils:                                  */
		/* ************************************************************************** */
		
		/* ************************************************************************** */
		/*                           		 insert:                                  */
		/* ************************************************************************** */

			void leftRotate(NodePtr x) {
			
				NodePtr y = x->right;
				x->right = y->left;
				if (y->left != TNULL)
				{
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == nullptr)
				{
					this->root = y;
				} 
				else if (x == x->parent->left)
				{
					x->parent->left = y;
				}
				else
				{
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			};

			void rightRotate(NodePtr x) {
				
				NodePtr y = x->left;
				x->left = y->right;
				if (y->right != TNULL)
				{
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == nullptr)
				{
					this->root = y;
				}
				else if (x == x->parent->right)
				{
					x->parent->right = y;
				} 
				else
				{
					x->parent->left = y;
				}
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
					{
						break;
					}
				}
				root->color = BLACK;
			};

			NodePtr insert_node(const value_type& val) {
				
				NodePtr node = alloc_node.allocate(1);
				node->color = RED;
				node->parent = nullptr;
				node->left = TNULL;
				node->right = TNULL;
				_alloc.construct(&node->pair, val);

				_size++;

				NodePtr y = nullptr;
				NodePtr x = this->root;

				while (x != TNULL)
				{
					y = x;
					if (node->pair.first < x->pair.first)
						x = x->left;
					else 
						x = x->right;
				}

				node->parent = y;

				if (y == nullptr)
					root = node;
				else if (node->pair.first < y->pair.first)
					y->left = node;
				else 
					y->right = node; 

				if (node->parent == nullptr) { node->color = 0; return node; }

				if (node->parent->parent == nullptr) { return node; }
    			
				insertFix(node);
				
				return node;
			};
		/* ************************************************************************** */
		/*                           		 delete:                                  */
		/* ************************************************************************** */
 
		void deleteFix(NodePtr x) {
			
			NodePtr s = TNULL;
			while (x != root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == BLACK)
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
					if (s->color == BLACK)
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

			if (u->parent == TNULL)
				root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		void deleteNode(NodePtr node) {
			
			
			NodePtr y = node;
			NodePtr x = TNULL;
			int y_original_color = y->color;
			if (node->left == TNULL)
			{
				x = node->right;
				rbTransplant(node, node->right);
			}
			else if (node->right == TNULL)
			{
				x = node->left;
				rbTransplant(node, node->left);
			}
			else
			{
				y = minimum(node->right);
				y_original_color = y->color;
				// x = y->right;
				if (y->parent == node)
					x->parent = y;
				else
				{
					rbTransplant(y, y->right);
					y->right = node->right;
					y->right->parent = y;
				}
				rbTransplant(node, y);
				y->left = node->left;
				y->left->parent = y;
				y->color = node->color;
			}
			// delete z;
			
			
			if (y_original_color == BLACK)
				deleteFix(x);
		}

		void	deallocate_node(NodePtr node)
		{
			_alloc.destroy(&node->pair);
			alloc_node.deallocate(node, 1);
		}

		void	delete_n(value_type k)
		{
			NodePtr n = searchTree(root,k);
			if (n != TNULL)
			{
				deleteNode(n);
				deallocate_node(n);
				_size--;
			}
		}

		/* ************************************************************************** */
		/*                           		 Min/Max:                                 */
		/* ************************************************************************** */
		
			NodePtr minimum(NodePtr node) {
    			
				while (node->left != TNULL)
				{
    			  node = node->left;
    			}
    			return node;
  			}

			NodePtr maximum(NodePtr node) {
   				
				while (node->right != TNULL)
				{
      				node = node->right;
    			}
    			return node;
  			}
		
		/* ************************************************************************** */
		/*                           		 search:                                  */
		/* ************************************************************************** */
  		
		  	NodePtr searchTree(NodePtr node, const value_type& key) {
    
				if (node == TNULL || key.first == node->pair.first)
      				return node;
    			if (key.first < node->pair.first)
    				return searchTree(node->left, key);
    			return searchTree(node->right, key);
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

					std::string sColor = root->color ? "RED" : "BLACK";
					std::cout << root->pair.first << "(" << sColor << ")" << std::endl;
					printHelper(root->left, indent, false);
					printHelper(root->right, indent, true);
				}
  			}

			void printTree() {
    			
				if (root) { printHelper(this->root, "", true); }
  			}	
		
	};

};

#endif
