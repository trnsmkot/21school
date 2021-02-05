#include "ft_btree.h"
// suffix traversal
// Обратный тип обхода (Postorder traversal)
// посетить все узлы в левом поддереве
// посетить корневой узел
// посетить все узлы в правом поддереве
// postorder(root->left)
// postorder(root->right)
// display(root->data)
void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}