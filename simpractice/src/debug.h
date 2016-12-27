/*
 * This module just provides some random useful debugging crap.
 */
#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <iostream>
#include <string>


const std::string debug_banner = "==============";


/*
 * Returns a string that can be used to separate different parts
 * of the console output for debugging purposes.
 */
std::string debug_print_closing(std::string str);

/*
 * Returns a string that can be used to separate different parts
 * of the console output for debugging purposes.
 */
std::string debug_print_header(std::string str);

#endif //header guard





