#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

int tree_is_full_recursive(const binary_tree_t *tree);

/**
 * tree_is_full_recursive - a function taht recursively checks if
 * binary tree is full.
 *
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 0 If tree is NULL.
 */
int tree_is_full_recursive(const binary_tree_t *tree)
{
if (tree != NULL)
{
if ((tree->left != NULL && tree->right == NULL) ||
(tree->left == NULL && tree->right != NULL) ||
tree_is_full_recursive(tree->left) == 0 ||
tree_is_full_recursive(tree->right) == 0)
{
return (0);
}
}
return (1);
}

/**
 * binary_tree_is_full - a function that measures the balance factor
 * of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 *
 * Return: 0 If tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}

return (tree_is_full_recursive(tree));
}
