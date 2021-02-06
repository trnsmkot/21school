#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
	t_btree *btree;

	btree = (t_btree *) malloc(sizeof(t_btree));
	if (btree)
	{
		btree->item = item;
		btree->left = (t_btree *)0;
		btree->right = (t_btree *)0;
	}
	return (btree);
}