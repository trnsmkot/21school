#include "ft_btree.h"

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree *btree;

	if ((btree = *root))
		if (!btree->left && btree->right)
			if (cmpf(item, btree->right->item) > 0)
				btree_insert_data(&btree->right, item, cmpf);
			else
				btree->left = btree_create_node(item);
		else if (btree->left && !btree->right)
			if (cmpf(item, btree->left->item) < 0)
				btree_insert_data(&btree->left, item, cmpf);
			else
				btree->right = btree_create_node(item);
		else if (!btree->left && !btree->right)
			if (cmpf(item, btree->item) > 0)
				btree->right = btree_create_node(item);
			else
				btree->left = btree_create_node(item);
		else if (cmpf(item, btree->right->item) > 0)
			btree_insert_data(&btree->right, item, cmpf);
		else
			btree_insert_data(&btree->left, item, cmpf);
	else
		*root = btree_create_node(item);
}