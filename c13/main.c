#include <stdio.h>
#include <string.h>
#include "ex04/ft_btree.h"

void applyf(char *ch) {
	printf("%s\n", ch);
}

int main()
{
	t_btree *item = btree_create_node("1");
	item->left = btree_create_node("2");
	item->right = btree_create_node("3");
	//  1
	// 2 3
	//    6

//	item->left->left = btree_create_node("4");
//	item->left->right = btree_create_node("5");

	btree_insert_data(&item, "6", &strcmp);

	printf("%s\n", item->left->item);
	printf("%s\n", item->right->item);
	printf("%s\n", item->right->left->item);

//	btree_apply_suffix(item, &applyf);
	printf("Hello, World!\n");
	return 0;
}
