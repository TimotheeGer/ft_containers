#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

namespace ft {

	template <typename T>
	struct Node {

		T pair;
		Node *left;
		Node *right;
		Node *parent;
		int color;
	};

template < class T, class node_type >
class	rbt_iterator
{
	
	public:

		typedef T 											value_type;
		typedef value_type * 								pointer;
		typedef value_type & 								reference;
		typedef const value_type *							const_pointer;
		typedef const value_type &							const_reference;
		typedef std::bidirectional_iterator_tag 			iterator_category;
		typedef std::ptrdiff_t								difference_type;
		typedef	node_type*									node_pointer;

		rbt_iterator( void ) :_t_null(NULL), _root(NULL), _ptr(NULL) {}
		rbt_iterator( node_pointer nd, const node_pointer& t_null, const node_pointer& root ) : _t_null(t_null), _root(root), _ptr(nd) {}
		rbt_iterator( const rbt_iterator &to_cpy ) : _t_null(to_cpy._t_null), _root(to_cpy._root),_ptr(to_cpy._ptr) {}
		rbt_iterator & operator=( const rbt_iterator& assign )
		{
			if (&assign != this)
			{
				_t_null = assign._t_null;
				_root = assign._root;
				_ptr = assign._ptr;
			}
			return *this;
		}

		operator	rbt_iterator<value_type const, node_type>(void) const {
			return (rbt_iterator<value_type const, node_type>(_ptr, _t_null, _root));
		}

		~rbt_iterator( void ) {}

		bool	operator==(const rbt_iterator & rhs) const
		{
			return ((_ptr == rhs._ptr));
		}

		bool	operator!=(const rbt_iterator & rhs) const 
		{
			return ((_ptr != rhs._ptr));
		}

		pointer	operator->( void )
		{
			return (_ptr->operator->());
		}

		const_pointer	operator->( void ) const
		{
			return (_ptr->operator->());
		}

		reference	operator*( void )
		{
			return (_ptr->operator*());
		}

		const_reference	operator*( void ) const
		{
			return (_ptr->operator*());
		}

		rbt_iterator &	operator++(void)
		{
			_ptr = _ptr->successor();
			return (*this);
		}

		rbt_iterator	operator++(int)
		{
			rbt_iterator tmp(*this);
			_ptr = _ptr->successor();
			return (tmp);
		}

		rbt_iterator &	operator--(void)
		{
			if (_ptr == _t_null)
				_ptr = _root->maximum();
			else
				_ptr = _ptr->predecessor();
			return (*this);
		}

		rbt_iterator	operator--(int)
		{
			rbt_iterator tmp(*this);
			if (_ptr == _t_null)
				_ptr = _root->maximum();
			else
				_ptr = _ptr->predecessor();
			return (tmp);
		}

	private:
		node_pointer _t_null;
		node_pointer _root;
		node_pointer _ptr;
};

};
#endif
