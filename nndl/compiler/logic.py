"""
Provides methods involving the logic from .ndl files, such
as that found in neuron classes.
"""

import os

class Rule:
    """
    Holds rule logic
    """
    def __init__(self, layer_rule, neuron_rule):
        self.layer = layer_rule.strip("{").strip("}")
        self.neuron = neuron_rule.strip("{").strip("}")

    def __str__(self):
        return "(Layers: " + str(self.layer) + ", Neurons: " +\
                str(self.neuron) + ")"

    def __repr__(self):
        return str(self)

def py(logical_expr, log_type, var):
    """
    Expands the logical_expr into a log_pred_expr.
    For example, if given [ALL] for a layer, this function returns
    {i==i}
    The var parameter is i for connection from layer
                         j for connection from neuron
                         k for connection to layer
                         l for connection to neuron
    """
    if log_type == "pred":
        return _pylogical(logical_expr, var)
    elif log_type == "class":
        return _pyclass(logical_expr, var)
    else:
        return _pymath(logical_expr, var)


def _pylogical(logical_expr, var):
    ands = logical_expr.strip("{").strip("}").split("&&")
    ands = ["(" + a + ")" for a in ands]
    logical_expr = " and ".join(ands)

    ors = logical_expr.split("||")
    ors = ["(" + o + ")" for o in ors]
    logical_expr = " or ".join(ors)

    return logical_expr

def _pyclass(logical_expr, var):
    # A class-type logical expression: [ something ]
    expr = logical_expr.strip('[').strip(']')
    if expr == "ALL":
        expr = "{" + var + "==" + var + "}"
    else:
        lowerbound = expr.split("-")[0]
        upperbound = expr.split("-")[1]
        expr = "{" + var + ">=" + lowerbound +\
                var + "<=" + upperbound + "}"
    return expr


def _pymath(logical_expr, var):
    expr = "{" + var + "==" + "int(" + logical_expr + ")}"
    return expr

def pygen(rules, network):
    """
    Generates the python file to execute to get the connections.
    """
    t = _pyboilerplate(network)
    t += _pyconnect(rules, network)
    with open("apply_rules.py", 'w') as f:
        f.write(t)
    mod = __import__("apply_rules")
    print("Python module written to apply_rules.py.")
    print("Applying the logic from the python module. For large networks, this may take a while...")
    mod.apply_rules(network)
    print("Done.")
    return network


def _pyboilerplate(network):
    t = \
    """def apply_rules(network):
    for i, from_layer in enumerate(network.layers):
        for j, from_neuron in enumerate(from_layer):
            for k, to_layer in enumerate(network.layers):
                for l, to_neuron in enumerate(to_layer):"""
    return t

def _pyconnect(rules, network):
    """
    Figures out how the rules go together
    """
    indent = "    " * 5
    t = "" + os.linesep
    for from_to in rules:
        from_rule = from_to[0]
        tos = from_to[1]

        irule = "(" + from_rule.layer + ")"
        jrule = "(" + from_rule.neuron + ")"

        for to_rule in tos:
            krule = "(" + to_rule.layer + ")"
            lrule = "(" + to_rule.neuron + ")"

            t += indent + "if " + irule + " and " + jrule +\
                    " and " + krule + " and " + lrule + ":" + os.linesep
            t += indent + "    " + "network.add_connection(i, j, k, l)"
            t += os.linesep

    return t







