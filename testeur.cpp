/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:21:48 by tigerber          #+#    #+#             */
/*   Updated: 2022/06/08 20:44:24 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <cstddef>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <type_traits>
#include "containers/color.hpp"
#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include "containers/map.hpp"
#include "containers/set.hpp"
// #include "iterators/utils.hpp"

		/* ************************************************************************** */
		/*                                                                            */
        /*                              Test Vector :                                 */
		/*                                                                            */
		/* ************************************************************************** */

		/* ************************************************************************** */
		/*                                 Iterator:                                  */
		/* ************************************************************************** */

        template <class T1, class T2>
        void    ft_printf_vec(T1& std_vec, T2& ft_vec, std::string std_str, std::string ft_str) {
            
            std::cout << C_BOLDRED << "------ print vec ------" << C_RESET << std::endl;
           
            std::vector<int>::iterator std_itb = std_vec.begin();
            std::vector<int>::iterator std_ite = std_vec.end();
            
            ft::vector<int>::iterator ft_itb = ft_vec.begin();
            ft::vector<int>::iterator ft_ite = ft_vec.end();
            
            while (std_itb != std_ite)
                std::cout << std_str << std::setw(5) << *std_itb++ << " | " << ft_str << C_GREEN << *ft_itb++ << C_RESET << std::endl;            
            std::cout << std::endl;
            
            std::cout << " std size = " << C_GREEN << std_vec.size() << C_RESET << std::endl;
            std::cout << " ft size = " << C_GREEN << ft_vec.size() << C_RESET << std::endl; 
            
            std::cout << std::endl;
        }

        template <class T1, class T2>
        void    ft_printf_map(T1& std_vec, T2& ft_vec, std::string std_str, std::string ft_str) {
            
            std::cout << C_BOLDRED << "------ print map ------" << C_RESET << std::endl;
           
            std::map<int, int>::iterator std_itb = std_vec.begin();
            std::map<int, int>::iterator std_ite = std_vec.end();
            
            ft::map<int, int>::iterator ft_itb = ft_vec.begin();
            ft::map<int, int>::iterator ft_ite = ft_vec.end();
            
            while (std_itb != std_ite)
            {
                std::cout << std_str << std_itb->first << " - " << std_itb->second << " | " 
                            << ft_str << C_GREEN << ft_itb->first  << C_RESET << " - " << C_GREEN << ft_itb->second << C_RESET << std::endl;            
                std_itb++;
                ft_itb++;
            }
            std::cout << std::endl;
            
            std::cout << " std size = " << C_GREEN << std_vec.size() << C_RESET << std::endl;
            std::cout << " ft size = " << C_GREEN << ft_vec.size() << C_RESET << std::endl; 
            
            std::cout << std::endl;
        }  

        template <class T1, class T2>
        void    ft_printf_set(T1& std_vec, T2& ft_vec, std::string std_str, std::string ft_str) {
            
            std::cout << C_BOLDRED << "------ print set ------" << C_RESET << std::endl;
           
            std::set<int>::iterator std_itb = std_vec.begin();
            std::set<int>::iterator std_ite = std_vec.end();
            
            ft::set<int>::iterator ft_itb = ft_vec.begin();
            ft::set<int>::iterator ft_ite = ft_vec.end();
            
            while (std_itb != std_ite)
            {
                std::cout << std_str << *std_itb << " | " 
                            << ft_str << C_GREEN << *ft_itb  << C_RESET << std::endl;            
                std_itb++;
                ft_itb++;
            }
            std::cout << std::endl;
            
            std::cout << " std size = " << C_GREEN << std_vec.size() << C_RESET << std::endl;
            std::cout << " ft size = " << C_GREEN << ft_vec.size() << C_RESET << std::endl; 
            
            std::cout << std::endl;

        }  

        template <class T1, class T2>
        void    ft_vec_iterator(T1& std_vec, T2& ft_vec) {

            std::cout << C_YELLOW << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;
            std::cout << C_YELLOW << "*                                 Iterator:                                  *" << C_RESET << std::endl << std::endl;
            std::cout << C_YELLOW << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;
            
            std::vector<int>::iterator std_itb = std_vec.begin();
            std::vector<int>::iterator std_ite = std_vec.end();
            
            std::vector<int>::reverse_iterator std_ritb = std_vec.rbegin();
            std::vector<int>::reverse_iterator std_rite = std_vec.rend();
            
            ft::vector<int>::iterator ft_itb = ft_vec.begin();
            ft::vector<int>::iterator ft_ite = ft_vec.end();
            
            ft::vector<int>::reverse_iterator ft_ritb = ft_vec.rbegin();
            ft::vector<int>::reverse_iterator ft_rite = ft_vec.rend();

            std::cout << C_YELLOW << "-------------------------std---------------------------" << C_RESET << std::endl;
            
            std::cout << "std_itb = " << C_GREEN << *std_itb << C_RESET << std::endl;
            std_itb++;
            std::cout << "std_itb++ = " << C_GREEN << *std_itb << C_RESET << std::endl;
            ++std_itb;
            std::cout << "++std_itb = " << C_GREEN << *std_itb << C_RESET << std::endl;
            std_itb--;
            std::cout << "std_itb-- = " << C_GREEN << *std_itb << C_RESET << std::endl;
            --std_itb;
            std::cout << "--std_itb = " << C_GREEN << *std_itb << C_RESET << std::endl << std::endl;

            std::cout << "std_ritb = " << C_GREEN << *std_ritb << C_RESET << std::endl;
            std_ritb++;
            std::cout << "std_ritb++ = " << C_GREEN << *std_ritb << C_RESET << std::endl;
            ++std_ritb;
            std::cout << "++std_ritb = " << C_GREEN << *std_ritb << C_RESET << std::endl;
            std_ritb--;
            std::cout << "std_ritb-- = " << C_GREEN << *std_ritb << C_RESET << std::endl;
            --std_ritb;
            std::cout << "--std_ritb = " << C_GREEN << *std_ritb << C_RESET << std::endl << std::endl;
            
            while (std_itb != std_ite)
                std::cout << "std_itb = " << C_GREEN << *std_itb++ << C_RESET << std::endl;

            std::cout << std::endl;

            while (std_ritb != std_rite)
                std::cout << "std_ritb = " << C_GREEN << *std_ritb++ << C_RESET << std::endl;

            std::cout << std::endl << C_YELLOW << "-------------------------ft----------------------------" << C_RESET << std::endl;
            
            std::cout << "ft_itb = " << C_GREEN << *ft_itb << C_RESET << std::endl;
            ft_itb++;
            std::cout << "ft_itb++ = " << C_GREEN << *ft_itb << C_RESET << std::endl;
            ++ft_itb;
            std::cout << "++ft_itb = " << C_GREEN << *ft_itb << C_RESET << std::endl;
            ft_itb--;
            std::cout << "ft_itb-- = " << C_GREEN << *ft_itb << C_RESET << std::endl;
            --ft_itb;
            std::cout << "--ft_itb = " << C_GREEN << *ft_itb << C_RESET << std::endl << std::endl;

            std::cout << "ft_ritb = " << C_GREEN << *ft_ritb << C_RESET << std::endl;
            ft_ritb++;
            std::cout << "ft_ritb++ = " << C_GREEN << *ft_ritb << C_RESET << std::endl;
            ++ft_ritb;
            std::cout << "++ft_ritb = " << C_GREEN << *ft_ritb << C_RESET << std::endl;
            ft_ritb--;
            std::cout << "ft_ritb-- = " << C_GREEN << *ft_ritb << C_RESET << std::endl;
            --ft_ritb;
            std::cout << "--ft_ritb = " << C_GREEN << *ft_ritb << C_RESET << std::endl << std::endl;
            
            while (ft_itb != ft_ite)
                std::cout << "ft_itb = " << C_GREEN << *ft_itb++ << C_RESET << std::endl;

            std::cout << std::endl;

            while (ft_ritb != ft_rite)
                std::cout << "ft_ritb = " << C_GREEN << *ft_ritb++ << C_RESET << std::endl;
            
            std::cout << std::endl;
        }
		
        /* ************************************************************************** */
		/*                                 Capacity:                                  */
		/* ************************************************************************** */      
        
        template <class T1, class T2>
        void    ft_vec_capacity(T1& std_vec, T2& ft_vec) {

            std::cout << C_YELLOW << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;
            std::cout << C_YELLOW << "*                                 Capacity:                                  *" << C_RESET << std::endl << std::endl;
            std::cout << C_YELLOW << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;

            std::cout << "size std = " << C_GREEN << std_vec.size() << C_RESET << std::endl;
            std::cout << "size ft  = " << C_GREEN << ft_vec.size() << C_RESET << std::endl << std::endl;

            std::cout << "max_size std = " << C_GREEN << std_vec.max_size() << C_RESET << std::endl;
            std::cout << "max_size ft  = " << C_GREEN << ft_vec.max_size() << C_RESET << std::endl << std::endl;

            std_vec.resize(5);
            ft_vec.resize(5);

            std::cout << "resize std = " << C_GREEN << std_vec.size() << C_RESET << std::endl;
            std::cout << "resize ft  = " << C_GREEN << ft_vec.size() << C_RESET << std::endl << std::endl;

            std::cout << "capacity std = " << C_GREEN << std_vec.capacity() << C_RESET << std::endl;
            std::cout << "capacity ft  = " << C_GREEN << ft_vec.capacity() << C_RESET << std::endl << std::endl;
            
            std::cout << "empty std = " << C_GREEN << std_vec.empty() << C_RESET << std::endl;
            std::cout << "empty ft  = " << C_GREEN << ft_vec.empty() << C_RESET << std::endl << std::endl;
            
            std_vec.reserve(25);
            ft_vec.reserve(25);

            std::cout << "reserve std = " << C_GREEN << std_vec.capacity() << C_RESET << std::endl;
            std::cout << "reserve ft  = " << C_GREEN << ft_vec.capacity() << C_RESET << std::endl << std::endl;                   
        }

		/* ************************************************************************** */
		/*                              Element access:                               */
		/* ************************************************************************** */
        
        template <class T1, class T2>
        void    ft_vec_element_access(T1& std_vec, T2& ft_vec) {

            std::cout << C_YELLOW << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;
            std::cout << C_YELLOW << "*                              Element access:                               *" << C_RESET << std::endl << std::endl;
            std::cout << C_YELLOW << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;


            std::cout << "[] std = " << C_GREEN << std_vec[3] << C_RESET << std::endl;
            std::cout << "[] ft = " << C_GREEN << ft_vec[3] << C_RESET << std::endl << std::endl;

            std::cout << "at std = " << C_GREEN << std_vec.at(4) << C_RESET << std::endl;
            std::cout << "at ft  = " << C_GREEN << ft_vec.at(4) << C_RESET << std::endl << std::endl;           

            std::cout << "front std = " << C_GREEN << std_vec.front() << C_RESET << std::endl;
            std::cout << "front ft  = " << C_GREEN << ft_vec.front() << C_RESET << std::endl << std::endl;                      

            std::cout << "back std = " << C_GREEN << std_vec.back() << C_RESET << std::endl;
            std::cout << "back ft  = " << C_GREEN << ft_vec.back() << C_RESET << std::endl << std::endl;         
        }
		
        /* ************************************************************************** */
		/*                                Modifiers:                                  */
		/* ************************************************************************** */      
        
        template <class T1, class T2>
        void    ft_vec_modifier(T1& std_vec, T2& ft_vec) {

            std::cout << C_YELLOW << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;
            std::cout << C_YELLOW << "*                                Modifiers:                                  *" << C_RESET << std::endl << std::endl;
            std::cout << C_YELLOW << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;

            std::vector<int> std_vec_tmp;
            ft::vector<int>  ft_vec_tmp;

            for (int i = 10; i < 20; i++)
            {
                std_vec_tmp.push_back(i);
                ft_vec_tmp.push_back(i);
            }
            
            std::vector<int>::iterator std_itb_tmp = std_vec_tmp.begin();
            std::vector<int>::iterator std_ite_tmp = std_vec_tmp.end();
                            
            
            std::cout << C_YELLOW << "----------------------------assign---------------------" << C_RESET << std::endl << std::endl;
            
            std_vec.assign(std_itb_tmp, std_ite_tmp);
            ft_vec.assign(std_itb_tmp, std_ite_tmp);

            ft_printf_vec(std_vec, ft_vec, "std assign = ", "ft assign = ");
            
            std::cout << C_YELLOW << "----------------------------assign 2-------------------" << C_RESET << std::endl << std::endl;
            
            std_vec.assign(7, 100);
            ft_vec.assign(7, 100);

            ft_printf_vec(std_vec, ft_vec, "std assign 2 = ", "ft assign 2 = ");

            std::cout << C_YELLOW << "----------------------------push_back-------------------" << C_RESET << std::endl << std::endl;
            
            std_vec.push_back(1);
            std_vec.push_back(2);
            std_vec.push_back(3);
            std_vec.push_back(4);
            std_vec.push_back(5);
            ft_vec.push_back(1);
            ft_vec.push_back(2);
            ft_vec.push_back(3);
            ft_vec.push_back(4);
            ft_vec.push_back(5);

            ft_printf_vec(std_vec, ft_vec, "std push_back = ", "ft push_back = ");

            std::cout << C_YELLOW << "----------------------------pop_back-------------------" << C_RESET << std::endl << std::endl;
            
            std_vec.pop_back();
            std_vec.pop_back();
            std_vec.pop_back();
            ft_vec.pop_back();
            ft_vec.pop_back();
            ft_vec.pop_back();

            ft_printf_vec(std_vec, ft_vec, "std pop_back = ", "ft pop_back = ");

            std::cout << C_YELLOW << "----------------------------insert single-------------------" << C_RESET << std::endl << std::endl;

            std::vector<int>::iterator std_itb3 = std_vec.begin();
            std::vector<int>::iterator std_ite3 = std_vec.end();
            
            ft::vector<int>::iterator ft_itb3 = ft_vec.begin();
            ft::vector<int>::iterator ft_ite3 = ft_vec.end();        
            
            std_vec.insert(std_itb3, 1);
            std_vec.insert(std_itb3, 2);
            std_vec.insert(std_itb3, 3);
            
            ft_vec.insert(ft_itb3, 1);
            ft_vec.insert(ft_itb3, 2);
            ft_vec.insert(ft_itb3, 3);

            ft_printf_vec(std_vec, ft_vec, "std insert single = ", "ft insert single = ");

            std::cout << C_YELLOW << "----------------------------insert fill-------------------" << C_RESET << std::endl << std::endl;


            std_vec.insert(std_itb3 + 3, 2, 5);
            ft_vec.insert(ft_itb3 + 3, 2, 5);

            ft_printf_vec(std_vec, ft_vec, "std insert fill = ", "ft insert fill = ");


            std::cout << C_YELLOW << "----------------------------insert range-------------------" << C_RESET << std::endl << std::endl;


            std_vec.insert(std_itb3 + 3, std_itb_tmp, std_ite_tmp - 5);
            ft_vec.insert(ft_itb3 + 3, std_itb_tmp, std_ite_tmp - 5);
            
            ft_printf_vec(std_vec, ft_vec, "std insert range = ", "ft insert range = ");


            std::cout << C_YELLOW << "----------------------------erase-------------------" << C_RESET << std::endl << std::endl;
            
            std_vec.erase(std_itb3 + 10);       
            std_vec.erase(std_itb3 + 10);       
            std_vec.erase(std_itb3 + 10);       
            ft_vec.erase(ft_itb3 + 10);
            ft_vec.erase(ft_itb3 + 10);
            ft_vec.erase(ft_itb3 + 10);
            
            ft_printf_vec(std_vec, ft_vec, "std erase = ", "ft erase = ");
  
            std::cout << C_YELLOW << "----------------------------erase iterator-------------------" << C_RESET << std::endl << std::endl;

            std_vec.erase(std_itb3 + 5, std_ite3);             
            std_vec.erase(std_itb3 + 5, std_ite3);             
            ft_vec.erase(ft_itb3 + 5, ft_ite3);
            ft_vec.erase(ft_itb3 + 5, ft_ite3);

            ft_printf_vec(std_vec, ft_vec, "std erase iterator = ", "ft erase iterator = ");
            
            std::cout << C_YELLOW << "----------------------------swap-------------------" << C_RESET << std::endl << std::endl;

            std::vector<int> std_vec2;
            ft::vector<int>  ft_vec2;

            for (int i = 200; i < 210; i++)
            {
                std_vec2.push_back(i);
                ft_vec2.push_back(i);
            }

            ft_printf_vec(std_vec2, ft_vec2, "std_vec2 = ", "ft_vec2 = ");
            ft_printf_vec(std_vec, ft_vec, "std_vec = ", "ft_vec = ");
            
            std_vec.swap(std_vec2);
            ft_vec.swap(ft_vec2);
            
            std::cout << C_YELLOW << "---------------------------after swap-------------------" << C_RESET << std::endl << std::endl;
            
            ft_printf_vec(std_vec2, ft_vec2, "std_vec2 = ", "ft_vec2 = ");
            ft_printf_vec(std_vec, ft_vec, "std_vec = ", "ft_vec = ");
            std::cout << std::endl;
                     
        }

		/* ************************************************************************** */
		/*                                                                            */
        /*                              Test Stack :                                  */
		/*                                                                            */
		/* ************************************************************************** */

		/* ************************************************************************** */
		/*                              Members functions :                           */
		/* ************************************************************************** */

        template <class T1, class T2>
        void    ft_stack_members_fonction(T1& std_stack, T2& ft_stack) {
            
            std::cout << C_YELLOW << "---------------------------Members functions-------------------" << C_RESET << std::endl << std::endl;
            
            std::cout << "std_stack empty = " << C_GREEN << std_stack.empty() << C_RESET << std::endl;
            std::cout << "ft_stack empty = " << C_GREEN << ft_stack.empty() << C_RESET << std::endl << std::endl;

            std::cout << "std_stack size = " << C_GREEN << std_stack.size() << C_RESET << std::endl;
            std::cout << "ft_stack size = " << C_GREEN << ft_stack.size() << C_RESET << std::endl << std::endl;         

            std::cout << "std_stack top = " << C_GREEN << std_stack.top() << C_RESET << std::endl;
            std::cout << "ft_stack top = " << C_GREEN << ft_stack.top() << C_RESET << std::endl << std::endl;

            std_stack.push(10);
            std_stack.push(11);
            ft_stack.push(10);
            ft_stack.push(11);

            std::cout << "std_stack push = " << C_GREEN << std_stack.top() << C_RESET << std::endl;
            std::cout << "ft_stack push = " << C_GREEN << ft_stack.top() << C_RESET << std::endl << std::endl;

            std_stack.pop();
            std_stack.pop();
            ft_stack.pop();
            ft_stack.pop();

            std::cout << "std_stack pop = " << C_GREEN << std_stack.top() << C_RESET << std::endl;
            std::cout << "ft_stack pop = " << C_GREEN << ft_stack.top() << C_RESET << std::endl << std::endl;
        }

		/* ************************************************************************** */
		/*                                                                            */
        /*                              Test MAP :                                    */
		/*                                                                            */
		/* ************************************************************************** */

		/* ************************************************************************** */
		/*                                 Iterator:                                  */
		/* ************************************************************************** */
        
        template <class T1, class T2>
        void    ft_map_iterator(T1& std_map, T2& ft_map) {

            std::cout << C_YELLOW << "---------------------------Iterator-------------------" << C_RESET << std::endl << std::endl;
            
            std::map<int, int>::iterator std_itb = std_map.begin();
            ft::map<int, int>::iterator ft_itb = ft_map.begin();
            
            std::cout << "std iterator begin first second = " << std::setw(10) << std_itb->first << " - " << std_itb->second << " | " 
                      << "ft iterator begin first second  = " << C_GREEN << ft_itb->first << " - " << ft_itb->second << C_RESET << std::endl;  
            
            std::map<int, int>::iterator std_ite = std_map.end();
            ft::map<int, int>::iterator ft_ite = ft_map.end();
            
            std_ite--;
            ft_ite--;
           
            std::cout << "std iterator end first second   = " << std::setw(10) << std_ite->first << " - " << std_ite->second << " | " 
                      << "ft iterator end first second    = " << C_GREEN << ft_ite->first << " - " << ft_ite->second << C_RESET << std::endl; 
        
            std::map<int, int>::reverse_iterator std_ritb = std_map.rbegin();
            ft::map<int, int>::reverse_iterator ft_ritb = ft_map.rbegin();
            
            std::cout << "std reverse_iterator begin first second = " << std::setw(10) << std_ritb->first << " - " << std_ritb->second << " | " 
                      << "ft reverse_iterator begin first second  = " << C_GREEN << ft_ritb->first << " - " << ft_ritb->second << C_RESET << std::endl;  
            
            std::map<int, int>::reverse_iterator std_rite = std_map.rend();
            ft::map<int, int>::reverse_iterator ft_rite = ft_map.rend();

            std_rite--;
            ft_rite--;

            std::cout << "std reverse_iterator end first second   = " << std::setw(10) << std_rite->first << " - " << std_rite->second << " | " 
                      << "ft reverse_iterator end first second    = " << C_GREEN << ft_rite->first << " - " << ft_rite->second << C_RESET << std::endl << std::endl;

            std_itb++;       
            ++std_itb;
            ft_itb++;       
            ++ft_itb;

            std_ritb++;       
            ++std_ritb;
            ft_ritb++;       
            ++ft_ritb;
            
            std::cout << "after++ std iterator begin first second = " << std::setw(10) << std_itb->first << " - " << std_itb->second << " | " 
                      << "after++ ft iterator begin first second  = " << C_GREEN << ft_itb->first << " - " << ft_itb->second << C_RESET << std::endl;  
            
            std::cout << "after++ std iterator end first second   = " << std::setw(10) << std_ite->first << " - " << std_ite->second << " | " 
                      << "after++ ft iterator end first second    = " << C_GREEN << ft_ite->first << " - " << ft_ite->second << C_RESET << std::endl; 
            
            std::cout << "after++ std reverse_iterator begin first second = " << std::setw(10) << std_ritb->first << " - " << std_ritb->second << " | " 
                      << "after++ ft reverse_iterator begin first second  = " << C_GREEN << ft_ritb->first << " - " << ft_ritb->second << C_RESET << std::endl;
            
            std::cout << "after++ std reverse_iterator end first second   = " << std::setw(10) << std_rite->first << " - " << std_rite->second << " | " 
                      << "after++ ft reverse_iterator end first second    = " << C_GREEN << ft_rite->first << " - " << ft_rite->second << C_RESET << std::endl << std::endl;           
                  
        }
		
        /* ************************************************************************** */
		/*                                 Capacity:                                  */
		/* ************************************************************************** */
        
        template <class T1, class T2>
        void    ft_map_capacity(T1& std_map, T2& ft_map) {
            
            std::cout << C_YELLOW << "---------------------------Capacity-------------------" << C_RESET << std::endl << std::endl;
            
            std::cout << "std empty = " << std_map.empty()  << " | " 
                      << "ft empty = " << C_GREEN << ft_map.empty() << C_RESET << std::endl << std::endl;
                      
            std::cout << "std size = " << std_map.size()  << " | " 
                      << "ft size = " << C_GREEN << ft_map.size() << C_RESET << std::endl << std::endl;

            std::cout << "std max_size = " << std_map.max_size()  << " | " 
                      << "ft max_size = " << C_GREEN << ft_map.max_size() << C_RESET << std::endl << std::endl;
        }

        /* ************************************************************************** */
		/*                            	 Element Access:                              */
		/* ************************************************************************** */
        
        template <class T1, class T2>
        void    ft_map_element_access(T1& std_map, T2& ft_map) {

            std::cout << C_YELLOW << "---------------------------Element Access-------------------" << C_RESET << std::endl << std::endl;
            
            std::cout << "std Element Access [3] = " << std_map[3]  << " | " 
                      << "ft Element Access [3]= " << C_GREEN << ft_map[3] << C_RESET << std::endl << std::endl; 

            std::cout << "std Element Access [6] = " << std_map[6]  << " | " 
                      << "ft Element Access [6]= " << C_GREEN << ft_map[6] << C_RESET << std::endl << std::endl;

            std::cout << "std Element Access [9] = " << std_map[9]  << " | " 
                      << "ft Element Access [9]= " << C_GREEN << ft_map[9] << C_RESET << std::endl << std::endl;           
        }   

		/* ************************************************************************** */
		/*                            		 Modifiers:                               */
		/* ************************************************************************** */

        template <class T1, class T2>
        void    ft_map_modifiers(T1& std_map, T2& ft_map) {

            std::cout << C_YELLOW << "---------------------------Modifiers-------------------" << C_RESET << std::endl << std::endl;
            
            ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");
            
            std::cout << "std insert single (3) = " << std_map.insert(std::pair< int, int>(3, 43)).second  << " | " 
                      << "ft insert single (3) = " << C_GREEN << ft_map.insert(ft::pair< int, int>(3, 43)).second << C_RESET << std::endl << std::endl; 

            std::cout << "std insert single (15) = " << std_map.insert(std::pair< int, int>(15, 55)).second  << " | " 
                      << "ft insert single (15) = " << C_GREEN << ft_map.insert(ft::pair< int, int>(15, 55)).second << C_RESET << std::endl << std::endl;

            std::cout << "std insert single (15) = " << std_map.insert(std::pair< int, int>(15, 55)).second  << " | " 
                      << "ft insert single (15) = " << C_GREEN << ft_map.insert(ft::pair< int, int>(15, 55)).second << C_RESET << std::endl << std::endl;            
            
            ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");

            std::cout << "std insert hint (16) = " << std_map.insert(std_map.begin(), std::pair< int, int>(16, 56))->first  << " | " 
                      << "ft insert hint (16) = " << C_GREEN << ft_map.insert(ft_map.begin(), ft::pair< int, int>(16, 56))->first << C_RESET << std::endl << std::endl; 

            std::cout << "std insert hint (17) = " << std_map.insert(std_map.begin(), std::pair< int, int>(17, 57))->first  << " | " 
                      << "ft insert hint (17) = " << C_GREEN << ft_map.insert(ft_map.begin(), ft::pair< int, int>(17, 57))->first << C_RESET << std::endl << std::endl;

            std::cout << "std insert hint (18) = " << std_map.insert(std_map.begin(), std::pair< int, int>(18, 58))->first  << " | " 
                      << "ft insert hint (18) = " << C_GREEN << ft_map.insert(ft_map.begin(), ft::pair< int, int>(18, 58))->first << C_RESET << std::endl << std::endl;             

            ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");

            std::map<int, int> std_map2;
            ft::map<int, int>  ft_map2;
            
            for (int i = 30; i < 40; i++)
            {
                std_map2.insert(std::pair< int, int>(i, i + 40));
                ft_map2.insert(ft::pair< int, int>(i, i + 40));
            }

            std::cout << C_BOLDMAGENTA << "insert range InputIterator" << C_RESET << std::endl << std::endl;
            
            std_map.insert(std_map2.begin(), std_map2.end());
            ft_map.insert(ft_map2.begin(), ft_map2.end());

            ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");
            
            std::cout << C_BOLDMAGENTA << "erase Iterator" << C_RESET << std::endl << std::endl;

            std_map.erase(std_map.begin());
            std_map.erase(std_map.begin());
            ft_map.erase(ft_map.begin());           
            ft_map.erase(ft_map.begin());

            ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");

            std::cout << "std erase key_type = " << std_map.erase(2)  << " | " 
                      << "ft erase key_type = " << C_GREEN << ft_map.erase(2) << C_RESET << std::endl << std::endl; 

            std::cout << "std erase key_type = " << std_map.erase(2)  << " | " 
                      << "ft erase key_type = " << C_GREEN << ft_map.erase(2) << C_RESET << std::endl << std::endl;

            std::cout << "std erase key_type = " << std_map.erase(3)  << " | " 
                      << "ft erase key_type = " << C_GREEN << ft_map.erase(3) << C_RESET << std::endl << std::endl;
             
            ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");
        
            std::cout << C_BOLDMAGENTA << "erase range Iterator" << C_RESET << std::endl << std::endl;
            
            std::map<int, int>::iterator std_it = std_map.begin();
            ft::map<int, int>::iterator ft_it = ft_map.begin();

            for(int i = 0; i < 6; i++)
            {
                std_it++;
                ft_it++;
            }
            
            std_map.erase(std_map.begin(), std_it);
            ft_map.erase(ft_map.begin(), ft_it);           
            
            ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");

            std::cout << C_BOLDMAGENTA << "swap" << C_RESET << std::endl << std::endl;
            
            std::cout << "***befor***" << std::endl;
            
            std::map<int, int> std_map3;
            ft::map<int, int>  ft_map3;
            
            for (int i = 0; i < 10; i++)
            {
                std_map3.insert(std::pair< int, int>(i, i + 100));
                ft_map3.insert(ft::pair< int, int>(i, i + 100));
            }

            ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");
            ft_printf_map(std_map3, ft_map3, " std_map3 ", " ft_map3 ");

            std::cout << "***after***" << std::endl;

            std_map.swap(std_map3);
            ft_map.swap(ft_map3);

            ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");
            ft_printf_map(std_map3, ft_map3, " std_map3 ", " ft_map3 ");
            
            std::cout << C_BOLDMAGENTA << "clear" << C_RESET << std::endl << std::endl;

            std::cout << "***befor***" << std::endl;

            ft_printf_map(std_map2, ft_map2, " std_map2 ", " ft_map2 ");            
            ft_printf_map(std_map3, ft_map3, " std_map3 ", " ft_map3 ");            

            std::cout << "***after***" << std::endl;

            std_map2.clear();
            std_map3.clear();
            ft_map2.clear();
            ft_map3.clear();            
            
            ft_printf_map(std_map2, ft_map2, " std_map2 ", " ft_map2 ");            
            ft_printf_map(std_map3, ft_map3, " std_map3 ", " ft_map3 ");

            std::cout << "..." << std::endl << std::endl;         
            
        }

		/* ************************************************************************** */
		/*                            		Operations:                               */
		/* ************************************************************************** */

        template <class T1, class T2>
        void    ft_map_operation(T1& std_map, T2& ft_map) {

            std::cout << C_YELLOW << "---------------------------Operations-------------------" << C_RESET << std::endl << std::endl;

            std::cout << "std find = " << std_map.find(2)->first  << " | " 
                      << "ft find = " << C_GREEN << ft_map.find(2)->first << C_RESET << std::endl << std::endl; 

            std::cout << "std find = " << std_map.find(3)->first  << " | " 
                      << "ft find = " << C_GREEN << ft_map.find(3)->first << C_RESET << std::endl << std::endl; 
            
            std::cout << "std count = " << std_map.count(4)  << " | " 
                      << "ft count = " << C_GREEN << ft_map.count(4) << C_RESET << std::endl << std::endl;

            std::cout << "std count = " << std_map.count(22)  << " | " 
                      << "ft count = " << C_GREEN << ft_map.count(22) << C_RESET << std::endl << std::endl;
            
            std::cout << "std lower_bound = " << std_map.lower_bound(3)->first  << " | " 
                      << "ft lower_bound = " << C_GREEN << ft_map.lower_bound(3)->first << C_RESET << std::endl << std::endl;             

            std::cout << "std upper_bound = " << std_map.upper_bound(7)->first  << " | " 
                      << "ft upper_bound = " << C_GREEN << ft_map.upper_bound(7)->first << C_RESET << std::endl << std::endl;

            std::cout << "std equal_range = " << std_map.equal_range(7).first->first  << " | " 
                      << "ft equal_range = " << C_GREEN << ft_map.equal_range(7).first->first << C_RESET << std::endl << std::endl; 
        }

		/* ************************************************************************** */
		/*                                                                            */
        /*                              Test SET :                                    */
		/*                                                                            */
		/* ************************************************************************** */

		/* ************************************************************************** */
		/*                                 Iterator:                                  */
		/* ************************************************************************** */
        
        template <class T1, class T2>
        void    ft_set_iterator(T1& std_set, T2& ft_set) {

            std::cout << C_YELLOW << "---------------------------Iterator-------------------" << C_RESET << std::endl << std::endl;
            
            std::set<int>::iterator std_itb = std_set.begin();
            ft::set<int>::iterator ft_itb = ft_set.begin();
            
            std::cout << "std iterator begin first second = " << std::setw(10) << *std_itb << " | " 
                      << "ft iterator begin first second  = " << C_GREEN << *ft_itb << C_RESET << std::endl;  
            
            std::set<int>::iterator std_ite = std_set.end();
            ft::set<int>::iterator ft_ite = ft_set.end();
            
            std_ite--;
            ft_ite--;
           
            std::cout << "std iterator end first second   = " << std::setw(10) << *std_ite  << " | " 
                      << "ft iterator end first second    = " << C_GREEN << *ft_ite << C_RESET << std::endl; 
        
            std::set<int>::reverse_iterator std_ritb = std_set.rbegin();
            ft::set<int>::reverse_iterator ft_ritb = ft_set.rbegin();
            
            std::cout << "std reverse_iterator begin first second = " << std::setw(10) << *std_ritb << " | " 
                      << "ft reverse_iterator begin first second  = " << C_GREEN << *ft_ritb << C_RESET << std::endl;  
            
            std::set<int>::reverse_iterator std_rite = std_set.rend();
            ft::set<int>::reverse_iterator ft_rite = ft_set.rend();

            std_rite--;
            ft_rite--;

            std::cout << "std reverse_iterator end first second   = " << std::setw(10) << *std_rite << " | " 
                      << "ft reverse_iterator end first second    = " << C_GREEN << *ft_rite << C_RESET << std::endl << std::endl;

            std_itb++;       
            ++std_itb;
            ft_itb++;       
            ++ft_itb;

            std_ritb++;       
            ++std_ritb;
            ft_ritb++;       
            ++ft_ritb;
            
            std::cout << "after++ std iterator begin first second = " << std::setw(10) << *std_itb << " | " 
                      << "after++ ft iterator begin first second  = " << C_GREEN << *ft_itb << C_RESET << std::endl;  
            
            std::cout << "after++ std iterator end first second   = " << std::setw(10) << *std_ite << " | " 
                      << "after++ ft iterator end first second    = " << C_GREEN << *ft_ite << C_RESET << std::endl; 
            
            std::cout << "after++ std reverse_iterator begin first second = " << std::setw(10) << *std_ritb << " | " 
                      << "after++ ft reverse_iterator begin first second  = " << C_GREEN << *ft_ritb << C_RESET << std::endl;
            
            std::cout << "after++ std reverse_iterator end first second   = " << std::setw(10) << *std_rite << " | " 
                      << "after++ ft reverse_iterator end first second    = " << C_GREEN << *ft_rite << C_RESET << std::endl << std::endl;           
                  
        }
		
        /* ************************************************************************** */
		/*                                 Capacity:                                  */
		/* ************************************************************************** */
        
        template <class T1, class T2>
        void    ft_set_capacity(T1& std_set, T2& ft_set) {
            
            std::cout << C_YELLOW << "---------------------------Capacity-------------------" << C_RESET << std::endl << std::endl;
            
            std::cout << "std empty = " << std_set.empty()  << " | " 
                      << "ft empty = " << C_GREEN << ft_set.empty() << C_RESET << std::endl << std::endl;
                      
            std::cout << "std size = " << std_set.size()  << " | " 
                      << "ft size = " << C_GREEN << ft_set.size() << C_RESET << std::endl << std::endl;

            std::cout << "std max_size = " << std_set.max_size()  << " | " 
                      << "ft max_size = " << C_GREEN << ft_set.max_size() << C_RESET << std::endl << std::endl;
        }


		/* ************************************************************************** */
		/*                            		 Modifiers:                               */
		/* ************************************************************************** */

        template <class T1, class T2>
        void    ft_set_modifiers(T1& std_set, T2& ft_set) {

            std::cout << C_YELLOW << "---------------------------Modifiers-------------------" << C_RESET << std::endl << std::endl;
            
            ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");
            
            std::cout << "std insert single (3) = " << std_set.insert(3).second  << " | " 
                      << "ft insert single (3) = " << C_GREEN << ft_set.insert(3).second << C_RESET << std::endl << std::endl; 

            std::cout << "std insert single (15) = " << std_set.insert(15).second  << " | " 
                      << "ft insert single (15) = " << C_GREEN << ft_set.insert(15).second << C_RESET << std::endl << std::endl;

            std::cout << "std insert single (15) = " << std_set.insert(15).second  << " | " 
                      << "ft insert single (15) = " << C_GREEN << ft_set.insert(15).second << C_RESET << std::endl << std::endl;            
            
            ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");

            std::cout << "std insert hint (16) = " << *std_set.insert(std_set.begin(), 16)  << " | " 
                      << "ft insert hint (16) = " << C_GREEN << *ft_set.insert(ft_set.begin(), 16) << C_RESET << std::endl << std::endl; 

            std::cout << "std insert hint (17) = " << *std_set.insert(std_set.begin(), 17)  << " | " 
                      << "ft insert hint (17) = " << C_GREEN << *ft_set.insert(ft_set.begin(), 17) << C_RESET << std::endl << std::endl;

            std::cout << "std insert hint (18) = " << *std_set.insert(std_set.begin(), 18)  << " | " 
                      << "ft insert hint (18) = " << C_GREEN << *ft_set.insert(ft_set.begin(), 18) << C_RESET << std::endl << std::endl;             

            ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");

            std::set<int> std_set2;
            ft::set<int>  ft_set2;
            
            for (int i = 30; i < 40; i++)
            {
                std_set2.insert(i);
                ft_set2.insert(i);
            }

            std::cout << C_BOLDMAGENTA << "insert range InputIterator" << C_RESET << std::endl << std::endl;
            
            std_set.insert(std_set2.begin(), std_set2.end());
            ft_set.insert(ft_set2.begin(), ft_set2.end());

            ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");
            
            std::cout << C_BOLDMAGENTA << "erase Iterator" << C_RESET << std::endl << std::endl;

            std_set.erase(std_set.begin());
            std_set.erase(std_set.begin());
            ft_set.erase(ft_set.begin());           
            ft_set.erase(ft_set.begin());

            ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");

            std::cout << "std erase key_type = " << std_set.erase(2)  << " | " 
                      << "ft erase key_type = " << C_GREEN << ft_set.erase(2) << C_RESET << std::endl << std::endl; 

            std::cout << "std erase key_type = " << std_set.erase(2)  << " | " 
                      << "ft erase key_type = " << C_GREEN << ft_set.erase(2) << C_RESET << std::endl << std::endl;

            std::cout << "std erase key_type = " << std_set.erase(3)  << " | " 
                      << "ft erase key_type = " << C_GREEN << ft_set.erase(3) << C_RESET << std::endl << std::endl;
             
            ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");
        
            std::cout << C_BOLDMAGENTA << "erase range Iterator" << C_RESET << std::endl << std::endl;
            
            std::set<int>::iterator std_it = std_set.begin();
            ft::set<int>::iterator ft_it = ft_set.begin();

            for(int i = 0; i < 6; i++)
            {
                std_it++;
                ft_it++;
            }
            
            std_set.erase(std_set.begin(), std_it);
            ft_set.erase(ft_set.begin(), ft_it);           
            
            ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");

            std::cout << C_BOLDMAGENTA << "swap" << C_RESET << std::endl << std::endl;
            
            std::cout << "***befor***" << std::endl;
            
            std::set<int> std_set3;
            ft::set<int>  ft_set3;
            
            for (int i = 0; i < 10; i++)
            {
                std_set3.insert(i);
                ft_set3.insert(i);
            }

            ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");
            ft_printf_set(std_set3, ft_set3, " std_set3 ", " ft_set3 ");

            std::cout << "***after***" << std::endl;

            std_set.swap(std_set3);
            ft_set.swap(ft_set3);

            ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");
            ft_printf_set(std_set3, ft_set3, " std_set3 ", " ft_set3 ");
            
            std::cout << C_BOLDMAGENTA << "clear" << C_RESET << std::endl << std::endl;

            std::cout << "***befor***" << std::endl;

            ft_printf_set(std_set2, ft_set2, " std_set2 ", " ft_set2 ");            
            ft_printf_set(std_set3, ft_set3, " std_set3 ", " ft_set3 ");            

            std::cout << "***after***" << std::endl;

            std_set2.clear();
            std_set3.clear();
            ft_set2.clear();
            ft_set3.clear();            
            
            ft_printf_set(std_set2, ft_set2, " std_set2 ", " ft_set2 ");            
            ft_printf_set(std_set3, ft_set3, " std_set3 ", " ft_set3 ");

            std::cout << "..." << std::endl << std::endl;         
            
        }

		/* ************************************************************************** */
		/*                            		Operations:                               */
		/* ************************************************************************** */

        template <class T1, class T2>
        void    ft_set_operation(T1& std_set, T2& ft_set) {

            std::cout << C_YELLOW << "---------------------------Operations-------------------" << C_RESET << std::endl << std::endl;

            std::cout << "std find = " << *std_set.find(2)  << " | " 
                      << "ft find = " << C_GREEN << *ft_set.find(2) << C_RESET << std::endl << std::endl; 

            std::cout << "std find = " << *std_set.find(3)  << " | " 
                      << "ft find = " << C_GREEN << *ft_set.find(3) << C_RESET << std::endl << std::endl; 
            
            std::cout << "std count = " << std_set.count(4)  << " | " 
                      << "ft count = " << C_GREEN << ft_set.count(4) << C_RESET << std::endl << std::endl;

            std::cout << "std count = " << std_set.count(22)  << " | " 
                      << "ft count = " << C_GREEN << ft_set.count(22) << C_RESET << std::endl << std::endl;
            
            std::cout << "std lower_bound = " << *std_set.lower_bound(3)  << " | " 
                      << "ft lower_bound = " << C_GREEN << *ft_set.lower_bound(3) << C_RESET << std::endl << std::endl;             

            std::cout << "std upper_bound = " << *std_set.upper_bound(7)  << " | " 
                      << "ft upper_bound = " << C_GREEN << *ft_set.upper_bound(7) << C_RESET << std::endl << std::endl;

            std::cout << "std equal_range = " << *std_set.equal_range(7).first  << " | " 
                      << "ft equal_range = " << C_GREEN << *ft_set.equal_range(7).first << C_RESET << std::endl << std::endl; 
        }

int main() {

 	std::cout << C_BLUE << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;
    std::cout << C_BLUE << "*                                 VECTOR                                     *" << C_RESET << std::endl << std::endl;
    std::cout << C_BLUE << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;

    std::vector<int> std_vec;
    ft::vector<int>  ft_vec;
    
    for (int i = 0; i < 10; i++)
    {
        std_vec.push_back(i);
        ft_vec.push_back(i);
    }

    ft_vec_iterator(std_vec, ft_vec);
    ft_vec_capacity(std_vec, ft_vec);
    ft_vec_element_access(std_vec, ft_vec);
    ft_vec_modifier(std_vec, ft_vec);

 	std::cout << C_BLUE << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;
    std::cout << C_BLUE << "*                                 STACK                                      *" << C_RESET << std::endl << std::endl;
    std::cout << C_BLUE << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;   

    std::stack<int> std_stack;   
    ft::stack<int>  ft_stack;   

    for (int i = 0; i < 10; i++)
    {
        std_stack.push(i);
        ft_stack.push(i);
    }    

    ft_stack_members_fonction(std_stack, ft_stack);

 	std::cout << C_BLUE << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;
    std::cout << C_BLUE << "*                                 MAP                                        *" << C_RESET << std::endl << std::endl;
    std::cout << C_BLUE << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;  
    
    std::map<int, int> std_map;
    ft::map<int, int>  ft_map;

    
    
    for (int i = 0; i < 10; i++)
    {
        std_map.insert(std::pair< int, int>(i, i + 40));
        ft_map.insert(ft::pair< int, int>(i, i + 40));
    }

    ft_printf_map(std_map, ft_map, " std_map ", " ft_map ");
    
    ft_map_iterator(std_map, ft_map);
    ft_map_capacity(std_map, ft_map);
    ft_map_element_access(std_map, ft_map);
    ft_map_modifiers(std_map, ft_map);
    ft_map_operation(std_map, ft_map);

 	std::cout << C_BLUE << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;
    std::cout << C_BLUE << "*                                 set                                        *" << C_RESET << std::endl << std::endl;
    std::cout << C_BLUE << "* ************************************************************************** *" << C_RESET << std::endl << std::endl;  
    
    std::set<int> std_set;
    ft::set<int>  ft_set;

    
    
    for (int i = 0; i < 10; i++)
    {
        std_set.insert(i);
        ft_set.insert(i);
    }

    ft_printf_set(std_set, ft_set, " std_set ", " ft_set ");
    
    ft_set_iterator(std_set, ft_set);
    ft_set_capacity(std_set, ft_set);
    ft_set_modifiers(std_set, ft_set);
    ft_set_operation(std_set, ft_set);   
    
    return 0;
}
