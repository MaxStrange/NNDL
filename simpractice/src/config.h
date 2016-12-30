/*
 * Global simulator configuration file.
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__


/*
 * True if you want to run the unit tests rather than running the
 * simulator normally. False for normal operation.
 */
#define RUN_UNIT_TESTS          true

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






