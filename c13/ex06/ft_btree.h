#ifndef FT_BTREE_H

# define FT_BTREE_H

typedef struct s_btree
{
	struct s_btree *left;
	struct s_btree *right;
	void *item;
} t_btree;

int btree_level_count(t_btree *root);

#endif
