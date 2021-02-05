#include "ft_btree.h"

void btree_infix(t_btree *root, int (*cmpf)(void *, void *), void *data_ref, t_btree **find)
{
	if (!root)
		return;
	btree_infix(root->left, cmpf, data_ref, find);
	if (!*find && cmpf(root->item, data_ref) == 0)
		*find = root;
	btree_infix(root->right, cmpf, data_ref, find);
}

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	t_btree *find = 0;
	btree_infix(root, cmpf, data_ref, &find);
	return find ? find : ((void *) 0);
}