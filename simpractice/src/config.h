/*
 * Global simulator configuration file.
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__


/*
 * Just hard-coded for testing
 */
#define NUM_LAYERS              3

/*
 * Just hard-coded for testing
 */
#define NUM_NEURONS             3

/*
 * Defines for what example to use.
 */
#define SOURCE_HEADER           "mnist_source.h"
#define SOURCE                  MnistSource


/*
 * You can change this from a float to a double.
 * Using float should be faster, but not as precise.
 */
typedef float fpoint_t;




#endif //header guard






