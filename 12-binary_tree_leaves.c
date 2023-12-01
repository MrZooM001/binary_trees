#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the size.
 *
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t count;

count = 0;
if (tree)
{
count += (!tree->left && !tree->right) ? 1 : 0;
count += binary_tree_leaves(tree->left);
count += binary_tree_leaves(tree->right);
}

return (count);
}
