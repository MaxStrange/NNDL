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
 * Will be removed when the simulator gets integrated with
 * the NNDL compiler.
 * TODO
 */
#define NUM_NEURONS_INPUT       784
#define NUM_NEURONS_HIDDEN      125
#define NUM_NEURONS_OUTPUT      10

/*
 * Defines for what example to use.
 * This will be replaced with polymorphism soon.
 * TODO
 */
#define SOURCE_HEADER           "mnist_source.h"
#define SOURCE                  MnistSource
#define NEURON_HEADER           "simple_neuron.h"
#define NEURON                  SimpleNeuron
#define SINK_HEADER             "mnist_sink.h"
#define SINK                    MnistSink
#define SYNAPSE_HEADER          "simple_synapse.h"
#define SYNAPSE                 SimpleSynapse
#define BIAS_HEADER             "bias_synapse.h"
#define BIAS                    BiasSynapse


/*
 * You can change this from a float to a double.
 * Using float should be faster, but not as precise.
 */
typedef float fpoint_t;




#endif //header guard






