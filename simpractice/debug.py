import math
import numpy as np


def feedforward(X, W):
    dI = np.array([0.1, 0.1])
    s = np.dot(X + dI, W)
    return 1 / (1 + math.e ** (-s))

W = np.array([-0.44482, 0.447476])
eta = 0.6

input_vecs = [
                np.array([0, 0]),
                np.array([0, 1]),
                np.array([1, 0]),
                np.array([1, 1])
             ]
labels = [0, 0, 0, 1]

print("Weights: ", W)

for _ in range(0, 20):
    for X, t in zip(input_vecs, labels):
        print("Data for this iteration: ", X)
        raw = feedforward(X, W)
        d_o = (raw - t) * raw * (1 - raw)
        print("d_o: ", d_o)
        W -= eta * d_o * X
        got = 1 if raw >= 0.5 else 0
        print("RAW: ", raw)
        print("GOT: " + str(got) + " LABEL: " + str(t))
        print("Weights: ", W)







