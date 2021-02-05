#ifndef FT_BTREE_H

# define FT_BTREE_H

typedef struct s_btree
{
	struct s_btree *left;
	struct s_btree *right;
	void *item;
} t_btree;

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));

#endif
