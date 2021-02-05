#include <stdio.h>
#include "ex00/ft_btree.h"

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
t_btree *btree_create_node(void *item);

void applyf(char *ch) {
	printf("%s\n", ch);
}

int main()
{
	t_btree *item = btree_create_node("1");
	item->left = btree_create_node("2");
	item->right = btree_create_node("3");

	item->left->left = btree_create_node("4");
	item->left->right = btree_create_node("5");

//	btree_apply_suffix(item, &applyf);
	printf("Hello, World!\n");
	return 0;
}
