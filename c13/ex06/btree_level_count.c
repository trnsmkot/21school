#include "ft_btree.h"

void btree_count(t_btree *root, int *count, int left, int right)
{
	if (!root)
	{
		if (*count < left)
			*count = left;
		if (*count < right)
			*count = right;
		return;
	}
	btree_count(root->left, count, left + 1, right);
	btree_count(root->right, count, left, right + 1);
}

int btree_level_count(t_btree *root)
{
	int count;

	count = 0;
	btree_count(root, &count, 0, 0);
	return (count);
}