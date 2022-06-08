#ifndef UTILS_HPP
#define UTILS_HPP

#include <utility>

namespace ft {

	/* ************************************************************************** */
	/*                                    Pair                                    */
	/* ************************************************************************** */

	template< class T1, class T2 >
	struct pair {
		
		public:

		/* ************************************************************************** */
		/*                          Member type Definition                            */
		/* ************************************************************************** */
			
			typedef T1					first_type;
			typedef T2					second_type;

			first_type 					first;
			second_type 				second;
		
		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */
		
			pair() : first(T1()), second(T2()) { };

			template<class U, class V> 
			pair (const pair<U,V> & pr) : first(pr.first), second(pr.second) { };

			pair (const first_type& a, const second_type& b) : first(a), second(b) { };

			pair& operator= (const pair& pr) { 

				if (this != &pr)
				{
					first = pr.first;
					second = pr.second;
				}
				return (*this);
			};

			~pair() {};

		/* ************************************************************************** */
		/*                       Non-member function overloads                        */
		/* ************************************************************************** */

			friend  bool operator == (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first == rhs.first && lhs.second == rhs.second; };

			
			friend  bool operator != (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); };

			
			friend  bool operator < (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); };

			
			friend  bool operator <= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); };

			
			friend  bool operator > (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs < lhs; };
		
			
			friend bool operator >= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); };

	};

	

	/* ************************************************************************** */
	/*                                 Make Pair                                  */
	/* ************************************************************************** */

	template <class T1, class T2>
 	pair<T1,T2> make_pair (T1 x, T2 y) {
		
		return (pair<T1, T2>(x, y));
	};

	/* ************************************************************************** */
	/*                                  Enable if                                 */
	/* ************************************************************************** */

	template<bool Cond, class T = void>
	struct enable_if {};
	
	template<class T> 
	struct enable_if<true, T> { typedef T type; };

	/* ************************************************************************** */
	/*                                Is integral                                 */
	/* ************************************************************************** */

	template <typename T>
	struct is_integral
	{ 
		static const bool value = false; 
	};

	template <>
	struct is_integral<bool> { static const bool value = true; };

	template <>
	struct is_integral<char> { static const bool value = true; };

	template <>
	struct is_integral<short> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<long> { static const bool value = true; };

	template <>
	struct is_integral<long long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };

	template <>
	struct is_integral<unsigned short> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long> { static const bool value = true; };

	/* ************************************************************************** */
	/*                          lexicographical_compare                           */
	/* ************************************************************************** */

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) 
				return false;
			else if (*first1<*first2) 
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}
	
	/* ************************************************************************** */
	/*                                    equal                                   */
	/* ************************************************************************** */

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
  		while (first1!=last1)
		{
			if (!(*first1 == *first2))
    			return false;
    		++first1; ++first2;
  		}
  		return true;
	}

	/* ************************************************************************** */
	/*                               Iterator traits                              */
	/* ************************************************************************** */

	template <class Iterator>
  	struct iterator_traits {
    	
    	typedef typename Iterator::difference_type		difference_type;
    	typedef typename Iterator::value_type			value_type;
    	typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::iterator_category	iterator_category;
    	typedef typename Iterator::reference			reference;
  	};

	template <class T>
	struct iterator_traits <T*> {
	  
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	template <class T>
	struct iterator_traits <const T*> {
	  
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

};

#endif
