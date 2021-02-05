#include <stdio.h>
#include <string.h>
#include "ex04/ft_btree.h"

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

int btree_level_count(t_btree *root);

void applyf(char *ch) {
	printf("%s\n", ch);
}

int main()
{
	t_btree *item = btree_create_node("1");
	item->left = btree_create_node("2");
	item->right = btree_create_node("3");
	//   1
	// 2      3
	//       5    6
	//              7
	//               8
//	item->left->left = btree_create_node("4");
//	item->left->right = btree_create_node("5");

	btree_insert_data(&item, "6", &strcmp);
	btree_insert_data(&item, "7", &strcmp);
	btree_insert_data(&item, "8", &strcmp);
	btree_insert_data(&item, "5", &strcmp);
//	btree_insert_data(&item, "99", &strcmp);
//	btree_insert_data(&item, "11", &strcmp);


	printf("%s\n", item->left->item);
	printf("%s\n", item->right->item);
	printf("%s\n", item->right->left->item);

//	printf("%s\n", item->right->right->item);
	printf("count: %d\n", btree_level_count(item));;

//	t_btree *find = (t_btree *) btree_search_item(item, "4", &strcmp);

//	if (find) {
//		printf("%s\n", );
//	}


//	printf("%s\n", item->left->item);
//	printf("%s\n", item->right->item);
//	printf("%s\n", item->right->left->item);

//	btree_apply_suffix(item, &applyf);
	printf("Hello, World!\n");
	return 0;
}
