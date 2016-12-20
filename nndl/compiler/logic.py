"""
Provides methods involving the logic from .ndl files, such
as that found in neuron classes.
"""

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
        return logical_expr
    elif log_type == "class":
        return _pyclass(logical_expr, var)
    else:
        return _pymath(logical_expr, var)


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
    expr = "{" + var + "==" + "(" + logical_expr + ")}"
    return expr










