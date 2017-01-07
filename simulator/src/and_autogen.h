
/*
 * This file and the corresponding .cpp file was auto generated
 * with the nndl compiler for the nndl simulator.
 */
#ifndef __AND_AUTOGEN_H__
#define __AND_AUTOGEN_H__

#include <vector>

#include "layer.h"
#include "synapse.h"

std::vector<Layer *> create_layers(void);

std::vector<Synapse *>& connect_layers(const std::vector<Layer *> &layers,
        std::vector<Synapse *> &connections);

#endif //header guard