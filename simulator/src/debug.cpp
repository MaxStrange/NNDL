#include <iostream>
#include <string>

#include "debug.h"


std::string debug_print_closing(std::string str)
{
    return debug_banner + "End: " + str + debug_banner;
}

std::string debug_print_header(std::string str)
{
    return debug_banner + str + debug_banner;
}







