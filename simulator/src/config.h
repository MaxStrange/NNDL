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

/*
 * If you want to use batch training, define the number of data vectors
 * in a batch here, or set it to 1 for no batch training.
 */
#define BATCH_SIZE              4

#define DEBUG_NUM_RUNS          10000

#if MNIST_EXAMPLE
    #define NUM_NEURONS_INPUT       784
    #define NUM_NEURONS_HIDDEN      125
    #define NUM_NEURONS_OUTPUT      10

    #define SOURCE_HEADER           "mnist_source.h"
    #define SOURCE                  MnistSource
    #define SINK_HEADER             "mnist_sink.h"
    #define SINK                    MnistSink
#elif XOR_EXAMPLE
    #define NUM_NEURONS_INPUT       2
    #define NUM_NEURONS_HIDDEN      2
    #define NUM_NEURONS_OUTPUT      1

    #define SOURCE_HEADER           "xor_source.h"
    #define SOURCE                  XorSource
    #define SINK_HEADER             "xor_sink.h"
    #define SINK                    XorSink
#elif AND_EXAMPLE
    #define NUM_NEURONS_INPUT       2
    #define NUM_NEURONS_HIDDEN      0
    #define NUM_NEURONS_OUTPUT      1

    #define SOURCE_HEADER           "and_source.h"
    #define SOURCE                  AndSource
    #define SINK_HEADER             "and_sink.h"
    #define SINK                    AndSink
#endif


#define NEURON_HEADER           "simple_neuron.h"
#define NEURON                  SimpleNeuron
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






