#include "ft_btree.h"


// prefix traversal - Preorder (Root, Left, Right) : 1 2 4 5 3
// Посетите корневой узел
// Посетите все узлы в левом поддереве
// Посетите все узлы в правом поддереве
// display(root->data)
// preorder(root->left)
// preorder(root->right)
void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}