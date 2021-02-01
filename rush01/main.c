#include <stdio.h>

typedef struct s_line
{
	int e1;
	int e2;
	int e3;
	int e4;
} line;
typedef struct s_border
{
	line left;
	line right;
	line top;
	line bottom;
} border;

int get_side_num(struct s_line side, int index)
{
	if (index == 0)
		return side.e1;
	else if (index == 1)
		return side.e2;
	else if (index == 2)
		return side.e3;
	else
		return side.e4;
}

int check_full_line(int check_line[6])
{
	int index = 1;
	int max = 0;
	int sum = 0;
	while (index < 5)
	{
		if (check_line[index] > max)
		{
			max = check_line[index];
			sum++;
		}
		index++;
	}
	if (sum != check_line[0])
		return (0);
	index = 4;
	max = 0;
	sum = 0;
	while (index > 0)
	{
		if (check_line[index] > max)
		{
			max = check_line[index];
			sum++;
		}
		index--;
	}
	if (sum != check_line[5])
		return (0);
	return (1);
}

void fill_check_line(int line[6], const int collections[3])
{
	int index = 1;
	int idx_col = 0;

	while (index < 5)
	{
		if (line[index] == 0)
		{
			line[index] = collections[idx_col];
			idx_col++;
		}
		index++;
	}
}

int find_next_valid_line(struct s_border border, int index, int array[4][4], int idx_coll, int solution[4])
{
	int collections[6][3] = {
			{1, 2, 3},
			{1, 3, 2},
			{2, 1, 3},
			{2, 3, 1},
			{3, 1, 2},
			{3, 2, 1}
	};

	idx_coll++;

	while (idx_coll < 6)
	{
		int check_line[6] = {
				get_side_num(border.left, index),
				array[index][0],
				array[index][1],
				array[index][2],
				array[index][3],
				get_side_num(border.right, index)
		};

		fill_check_line(check_line, collections[idx_coll]);


		if (check_full_line(check_line))
		{
			int ii = 0;
			int new_a[4][4] = {};

			while (ii < index)
			{
				int check_line2[6] = {0, array[ii][0], array[ii][1], array[ii][2], array[ii][3], 0};
				fill_check_line(check_line2, collections[solution[ii]]);
				new_a[ii][0] = check_line2[1];
				new_a[ii][1] = check_line2[2];
				new_a[ii][2] = check_line2[3];
				new_a[ii][3] = check_line2[4];
				ii++;
			}
//
			ii = 0;
			int yy = 0;
			int kkk = 1;
			while (ii < 4) {
				while (yy < index) {
					kkk = yy + 1;
					while (kkk < index) {
						if (new_a[yy][ii] == new_a[kkk][ii]) {
//							printf(" \nii =  %d %d %d |||||||||| \n", ii, yy, kkk);
//							printf("\n =|%d - %d|= \n", new_a[yy][ii], new_a[kkk][ii]);
							return (-1);
						}
						kkk++;
					}
					++yy;
				}
				++ii;
			}


//			printf("\n");
//
//			int index2 = 0;
//			while (index2 < 6)
//			{
//				printf("|%d|", check_line[index2]);
//				index2++;
//			}
			return (idx_coll);
		}

		idx_coll++;
	}
	return (-1);
}

int find_solution(struct s_border border, int idx, int array[4][4], int solution[4])
{
	int idx_var = -1;

	while (idx_var < 6)
	{
		idx_var = find_next_valid_line(border, idx, array, idx_var, solution);
		if (idx_var >= 0)
		{
			solution[idx] = idx_var;
			if (idx < 3)
			{
				if (find_solution(border, idx + 1, array, solution) == 0)
				{
					return (0);
				}
			} else
			{
				return (0);
			}
		} else
		{
			break;
		}
	}
	return (-1);
}

void print_solution(int array[4][4], int solution[4]) {
	int collections[6][3] = {
			{1, 2, 3},
			{1, 3, 2},
			{2, 1, 3},
			{2, 3, 1},
			{3, 1, 2},
			{3, 2, 1}
	};

//	int index = 0;
//	int index2 = 0;
//	int idx_col = 0;
//
//	while (index < 4)
//	{
//		while (index < 4)
//		{
//			if (line[index] == 0)
//			{
//				line[index] = collections[idx_col];
//				idx_col++;
//			}
//			index++;
//		}
//	}

}

int main()
{
	int array[4][4] = {
			{4, 0, 0, 0}, // {4, 1, 3, 2}
			{0, 4, 0, 0}, // {1, 4, 3, 2},
			{0, 0, 4, 0}, // {2, 3, 4, 1},
			{0, 0, 0, 4} //  {3, 2, 1, 4}
	};

	border mb = {
			{1, 2, 3, 2},
			{3, 3, 2, 1},
			{1, 2, 3, 3},
			{2, 3, 2, 1}
	};

	int solution[4] = {-1, -1, -1, -1};

	find_solution(mb, 0, array, &solution);

	printf("\n\n");
	int index = 0;
	while (index < 4)
	{
		printf(" (%d)", solution[index]);
		index++;
	}

//	int idx_var_1 = -1;
//	while (idx_var_1 < 6)
//	{
//		idx_var_1 = find_valid_line(mb, 0, array, idx_var_1);
//		if (idx_var_1 >= 0)
//		{
//			int idx_var_2 = -1;
//			while (idx_var_2 < 6)
//			{
//				idx_var_2 = find_valid_line(mb, 1, array, idx_var_2);
//				if (idx_var_2 >= 0)
//				{
//					int idx_var_3 = -1;
//					while (idx_var_3 < 6)
//					{
//						idx_var_3 = find_valid_line(mb, 2, array, idx_var_3);
//						if (idx_var_3 >= 0)
//						{
//							int idx_var_4 = -1;
//							while (idx_var_4 < 6)
//							{
//								idx_var_4 = find_valid_line(mb, 3, array, idx_var_4);
//								if (idx_var_4 >= 0)
//								{
//									// our solution
//								} else
//									break;
//							}
//						} else
//							break;
//					}
//				} else
//					break;
//			}
//		} else
//			return (-100);
//	}

	return (0);
}
