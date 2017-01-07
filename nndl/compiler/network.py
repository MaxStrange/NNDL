"""
ADT for holding random network stuff.
"""

import os

class Network:
    """
    """
    def __init__(self):
        self.connections = []
        self.layers = []
        self.layer_names = []

    def __str__(self):
        as_str = "{Connections: " + str(self.connections) + ";" + os.linesep
        as_str += "Layers: " + str(self.layers) + ";" + os.linesep
        as_str += "Layer_names: " + str(self.layer_names) + ";}"
        return as_str

    def add_layer(self, nrows, ncols, neurtype, name):
        """
        Adds a layer to the network with nrows and ncols.
        """
        self.layer_names.append(name)
        self.layers.append([neurtype for _ in range(nrows * ncols)])

    def add_connection(self, i, j, k, l):
        """
        Adds a connection between layer[i]'s [j] neuron and
        layer[k]'s [l] neuron.
        """
        nfrom = self.layer_names[i] + "_" + str(j)
        nto = self.layer_names[k] + "_" + str(l)
        connection = (nfrom, nto)
        if connection not in self.connections:
            self.connections.append(connection)







