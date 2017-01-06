"""
This is a feed forward neural network in Python to help debug the AND example.
"""
import math
import numpy as np
import random


ACTIVATION_EXPONENTIAL = True
BACK_PROP = True
BIAS_INPUT = -0.1
DATA_SET_SIZE = 3  # This is the number of sets of 4
LEARNING_RATE = 0.6


def activation(s):
    """
    Activation function for the network.
    Takes s, the sum of x * w and determines
    the activation value for neuron output.
    """
    if ACTIVATION_EXPONENTIAL:
        numerator = 1.0
        denominator = 1.0 + math.e ** -s
        return numerator / denominator
    else:
        activate = 1 if s > 0 else 0
        return activate


def backprop(y, label, X, W):
    """
    Returns the new weights for the network based on the
    calculated value y and the label that y should have been.
    """
    global LEARNING_RATE
    if BACK_PROP:
        del_o = (y - label) * y * (1.0 - y)
        new_weights = W - LEARNING_RATE * del_o * X
        return new_weights
    else:
        new_weights = W - (LEARNING_RATE * (y - label) * X)
        return new_weights


def clamp(val):
    """
    Clamps a value to 0 or 1
    """
    return 1 if val >= 0.5 else 0


def feedforward(X, W):
    """
    Loads X into the network whose weights are W.
    Returns the output of the network.
    """
    s = np.dot(X, W)
    y = activation(s)
    return y


def get_label(X):
    """
    Returns the label that corresponds to X.
    """
    if X[0] + X[1] == 2:
        return 1
    else:
        return 0


def print_after(W):
    """
    Prints the new weights after the backprop.
    """
    print("WEIGHTS AFTER BACKPROP: ", W)
    print("========================")


def print_info(i, t, W, X, y):
    """
    Prints the information for this step before backprop.
    """
    print("========================")
    print("Step: ", i)
    print("LABEL: ", t)
    print("WEIGHTS: ", W)
    print("DATA: ", X)
    print("FF OUTPUT: " + str(y) + " --> " + str(clamp(y)))


if __name__ == "__main__":
    # Generate the dataset
    allowable_data = [
                        np.array([0, 0]),
                        np.array([0, 1]),
                        np.array([1, 0]),
                        np.array([1, 1])
                      ]
#    dataset = [allowable_data for _ in range(DATA_SET_SIZE)]
#    for datagroup in dataset:
#        random.shuffle(datagroup)
    dataset = [
        [np.array([0, 0]), np.array([0, 1]), np.array([1, 0]), np.array([1, 1])],
        [np.array([1, 0]), np.array([0, 0]), np.array([0, 1]), np.array([1, 1])],
        [np.array([1, 0]), np.array([0, 0]), np.array([0, 1]), np.array([1, 1])]
        ]

    # Initialize the network's weights
    W = np.array([-0.44482, 0.447476, -0.44482])

    # Run the network on the whole dataset
    for i, datagroup in enumerate(dataset):
        print("EPOCH: ", i)
        num_right_this_epoch = 0
        for j, X in enumerate(datagroup):
            X = np.append(X, np.array(BIAS_INPUT))
            y = feedforward(X, W)
            t = get_label(X)
            num_right_this_epoch += 1 if clamp(y) == t else 0
            print_info(i * len(allowable_data) + j, t, W, X, y)
            W = backprop(y, t, X, W)
            print_after(W)
        accuracy = num_right_this_epoch / 4
        print("========ACCURACY OVER THE LAST EPOCH: " + str(accuracy) + "==========")










