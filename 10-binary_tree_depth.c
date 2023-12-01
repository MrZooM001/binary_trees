#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a node
 * in a binary tree.
 *
 * @tree: a pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, the function must return 0,
 * A NULL pointer is not a leaf
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
int depth;

depth = (tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0;

return (depth);
}
