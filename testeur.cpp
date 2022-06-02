/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:21:48 by tigerber          #+#    #+#             */
/*   Updated: 2022/06/02 15:26:35 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <cstddef>
#include <vector>
#include <map>
#include <stack>
#include <type_traits>
#include "containers/color.hpp"
#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include "containers/map.hpp"

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
            
            std::vector<int>::iterator std_itb = std_vec.begin();
            std::vector<int>::iterator std_ite = std_vec.end();
            
            ft::vector<int>::iterator ft_itb = ft_vec.begin();
            ft::vector<int>::iterator ft_ite = ft_vec.end();
            
            while (std_itb != std_ite)
                std::cout << std_str << std::setw(5) << *std_itb++ << " | " << ft_str << C_GREEN << *ft_itb++ << C_RESET << std::endl;            
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
            std::cout << "ft_stack empty = " << C_GREEN << ft_stack.empty() << C_RESET << std::endl;
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
    
    return 0;
}
