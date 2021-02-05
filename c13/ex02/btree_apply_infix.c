#include "ft_btree.h"
// infix traversal -  Inorder (Left, Root, Right) : 4 2 5 1 3
// Центрированный тип обхода (Inorder traversal)
// Сначала посетите все узлы в левом поддереве
// Затем корневой узел
// Посетите все узлы в правом поддереве
// inorder(root->left)
// display(root->data)
// inorder(root->right)
void btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}