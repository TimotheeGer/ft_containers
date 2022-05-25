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
				std::cout << "----------------------------RedBlackTree constructor------------------------------------" << std::endl;
				std::cout << "init TNULL = " << TNULL << std::endl << std::flush;
				std::cout << "----------------------------/RedBlackTree constructor------------------------------------" << std::endl;
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

				NodePtr exist = searchTreeKey(root, val.first);

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

				// std::cout << "ERASE IT" << std::endl << std::flush;
				deleteNodeHelper(root, position->first);
				// std::cout << "ERASE IT FIN" << std::endl << std::flush;
			};
			
			// (2)	
			size_type erase (const key_type& k) {
				std::cout << "----------------------------MAP------------------------------------" << std::endl;
				std::cout << "ROOT de map = " << get_root() << std::endl;
				std::cout << "ERASE KEY = " << k << " max = " << get_max() << std::endl;
				
				NodePtr exist = searchTreeKey(root, k);

				std::cout << "----------------------------/MAP------------------------------------" << std::endl;
				if (exist != TNULL)
				{
					deleteNodeHelper(root, k);
					return 1;
				}
				return 0;
			};
			
			// (3)	
			void erase (iterator first, iterator last) {

				// std::cout << "ROOT = " << root << std::endl << std::flush;
				// std::cout << "TEST ERASE IT" << std::endl;
				std::cout << "MAX ERASE = " << get_max() << std::endl << std::flush;
				std::cout << "first = " << first->first << std::endl << std::flush;
				std::cout << "last = " << last->first << std::endl << std::flush;
				iterator	tmp;

				// tmp = ++first;
				while (first != last)
				{
					std::cout << "PRINT TREE" << std::endl;
					// printTree();
					std::cout << "FIRST = " << first->first << std::endl;
					tmp = first;
					first++;
					erase(tmp);
					std::cout << "-------------------------------------------------" << std::endl;
				}
			};

			// void swap (map& x);

			// void clear() {

			// 	erase(begin(), tmp);
			// };

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



			NodePtr get_root() const { return root; };
			// Tree get_left() const { return root->left; };
			// Tree get_right() const { return root->right; };


		/* ************************************************************************** */
		/*                           		Allocator:                                */
		/* ************************************************************************** */


			allocator_type get_allocator() const {

				return allocator_type();
			};
		
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
				
				NodePtr s;
				while (x != root && x->color == 0)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == 1)
						{
							s->color = 0;
							x->parent->color = 1;
							leftRotate(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == 0 && s->right->color == 0)
						{
							s->color = 1;
							x = x->parent;
						} 
						else
						{
							if (s->right->color == 0)
							{
								s->left->color = 0;
								s->color = 1;
								rightRotate(s);
								s = x->parent->right;
							}
							s->color = x->parent->color;
							x->parent->color = 0;
							s->right->color = 0;
							leftRotate(x->parent);
							x = root;
						}
					} 
					else 
					{
						s = x->parent->left;
						if (s->color == 1)
						{
							s->color = 0;
							x->parent->color = 1;
							rightRotate(x->parent);
							s = x->parent->left;
						}
						if (s->right->color == 0 && s->right->color == 0)
						{
							s->color = 1;
							x = x->parent;
						}
						else 
						{
							if (s->left->color == 0)
							{
								s->right->color = 0;
								s->color = 1;
								leftRotate(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = 0;
							s->left->color = 0;
							rightRotate(x->parent);
							x = root;
						}
					}
				}
				x->color = 0;
			}

			void rbTransplant(NodePtr u, NodePtr v) {
				
				if (u->parent == nullptr)
				{
					root = v;
				} 
				else if (u == u->parent->left)
				{
					u->parent->left = v;
				} 
				else
				{
					u->parent->right = v;
				}
				v->parent = u->parent;
			}

			void deleteNodeHelper(NodePtr node, key_type key) {
				
				NodePtr z = TNULL;
				NodePtr x, y;
				while (node != TNULL)
				{
					if (node->pair.first == key)
					{
						z = node;
					}
					if (node->pair.first <= key)
					{
						node = node->right;
					} 
					else
					{
						node = node->left;
					}
				}
				if (z == TNULL)
				{
					std::cout << "Key not found in the tree" << std::endl;
					return;
				}

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
					{
						x->parent = y;
					} 
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
				
				// delete z;
				deallocate_node(z);
				
				if (y_original_color == 0)
				{
					deleteFix(x);
				}
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

			int get_max() {

				return (maximum(root)->pair.first);
			}
		
		/* ************************************************************************** */
		/*                           		 search:                                  */
		/* ************************************************************************** */
  		
		  	// NodePtr searchTree(NodePtr node, const value_type& key) {
    
			// 	if (node == TNULL || key.first == node->pair.first)
      		// 		return node;
    		// 	if (key.first < node->pair.first)
    		// 		return searchTree(node->left, key);
    		// 	return searchTree(node->right, key);
  			// }

			NodePtr searchTreeKey(NodePtr node, const key_type& key) {
    
				if (node == TNULL || key == node->pair.first)
      				return node;
    			if (key < node->pair.first)
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
