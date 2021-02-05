#include "ft_btree.h"

t_btree *btree_create_node(void *item);

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree *btree;

	btree = *root;
	if (!btree)
	{
		*root = btree_create_node(item);
		return;
	}

	

	if (cmpf(btree->left, item)) {

	} else if (cmpf(btree->right, item)) {

	}
}