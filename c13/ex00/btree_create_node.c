#include "ft_btree.h"
#include <stdlib.h>

t_btree *btree_create_node(void *item)
{
	t_btree *btree;

	btree = (t_btree *)malloc(sizeof(t_btree));
	btree->item = item;
	btree->left = 0;
	btree->right = 0;
	return (btree);
}