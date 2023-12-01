#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

int binary_tree_is_leaf(const binary_tree_t *node);
size_t binary_tree_depth(const binary_tree_t *tree);
const binary_tree_t *get_tree_leaf(const binary_tree_t *tree);
int tree_is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth,
size_t level);

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf.
 *
 * @node: a pointer to the node to check.
 *
 * Return: 1 if node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
if (node->left != NULL && node->right != NULL)
{
return (0);
}

return (1);
}

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

/**
 * tree_is_perfect_recursive - a function taht recursively checks if
 * binary tree is full.
 *
 * @tree: a pointer to the root node of the tree to check.
 * @leaf_depth: a pointer to the root node of the tree to check.
 * @level: a pointer to the root node of the tree to check.
 *
 * Return: 0 If tree is NULL.
 */
int tree_is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth,
size_t level)
{
if (binary_tree_is_leaf(tree))
{
return (level == leaf_depth ? 1 : 0);
}

if (tree->left == NULL || tree->right == NULL)
{
return (0);
}

return (tree_is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
tree_is_perfect_recursive(tree->right, leaf_depth, level + 1));
}


/**
 * get_tree_leaf - get a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to get a leaf from.
 *
 * Return: A pointer to the first leaf.
 */
const binary_tree_t *get_tree_leaf(const binary_tree_t *tree)
{
if (binary_tree_is_leaf(tree) == 1)
{
return (tree);
}

return (tree->left ? get_tree_leaf(tree->left) : get_tree_leaf(tree->right));
}


/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect.
 *
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}
return (tree_is_perfect_recursive(tree,
binary_tree_depth(get_tree_leaf(tree)), 0));
}
