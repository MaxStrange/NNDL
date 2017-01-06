/*
 * Global simulator configuration file.
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

/*
 * The example to use.
 */
#define MNIST_EXAMPLE           false
#define XOR_EXAMPLE             false
#define AND_EXAMPLE             true

/*
 * True if you want to run the unit tests rather than running the
 * simulator normally. False for normal operation.
 */
#define RUN_UNIT_TESTS          false

#define BATCH_SIZE              1

#define DEBUG_NUM_RUNS          12

/*
 * Just hard-coded for testing
 * Will be removed when the simulator gets integrated with
 * the NNDL compiler.
 * TODO
 */
#if MNIST_EXAMPLE
    #define NUM_NEURONS_INPUT       784
    #define NUM_NEURONS_HIDDEN      125
    #define NUM_NEURONS_OUTPUT      10
#elif XOR_EXAMPLE
    #define NUM_NEURONS_INPUT       2
    #define NUM_NEURONS_HIDDEN      2
    #define NUM_NEURONS_OUTPUT      1
#elif AND_EXAMPLE
    #define NUM_NEURONS_INPUT       2
    #define NUM_NEURONS_HIDDEN      0
    #define NUM_NEURONS_OUTPUT      1
#endif

/*
 * Defines for what example to use.
 * This will be replaced with polymorphism soon.
 * TODO
 */
#define SOURCE_HEADER           "and_source.h"//"xor_source.h"//"mnist_source.h"
#define SOURCE                  AndSource//XorSource//MnistSource
#define NEURON_HEADER           "simple_neuron.h"
#define NEURON                  SimpleNeuron
#define SINK_HEADER             "and_sink.h"//"xor_sink.h"//"mnist_sink.h"
#define SINK                    AndSink//XorSink//MnistSink
#define SYNAPSE_HEADER          "simple_synapse.h"
#define SYNAPSE                 SimpleSynapse
#define BIAS_HEADER             "bias_synapse.h"
#define BIAS                    BiasSynapse


/*
 * You can change this from a float to a double.
 * Using float should be faster, but not as precise.
 */
typedef double fpoint_t;




#endif //header guard






