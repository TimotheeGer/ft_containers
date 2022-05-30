/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:56:51 by tigerber          #+#    #+#             */
/*   Updated: 2022/05/30 16:14:19 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* https://en.wikipedia.org/wiki/ANSI_escape_code */

#ifndef COLOR_HPP
#define COLOR_HPP

#define C_RESET   "\033[0m"       /* reset */
#define C_BLACK   "\033[30m"      /* Black */
#define C_RED     "\033[31m"      /* Red */
#define C_GREEN   "\033[32m"      /* Green */
#define C_YELLOW  "\033[33m"      /* Yellow */
#define C_BLUE    "\033[34m"      /* Blue */
#define C_MAGENTA "\033[35m"      /* Magenta */
#define C_CYAN    "\033[36m"      /* Cyan */
#define C_WHITE   "\033[37m"      /* White */

#define C_BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define C_BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define C_BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define C_BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define C_BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define C_BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define C_BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define C_BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#endif