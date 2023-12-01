#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_balance - a function that measures the balance factor
 * of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 *
 * Return: 0 If tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
if (tree)
{
return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

return (0);
}
