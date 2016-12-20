"""
ADT for holding random network stuff.
"""

class Network:
    """
    """
    def __init__(self):
        self.layers = []

    def add_layer(self, nrows, ncols, neurtype):
        """
        Adds a layer to the network with nrows and ncols.
        """
        self.layers.append([neurtype for _ in range(nrows * ncols)])
