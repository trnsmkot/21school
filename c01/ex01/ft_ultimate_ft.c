//void sub_ft_ultimate_ft(int *********nbr)
//{
//
//}
void ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
	int a;
	int *nbr8;
	int **nbr7;
	int ***nbr6;
	int ****nbr5;
	int *****nbr4;
	int ******nbr3;
	int *******nbr2;
	int ********nbr1;




	a = 42;
	nbr8 = &a;
//	*nbr1 = &(*a + 10);
//	*nbr = &(*nbr8 + 10);


	nbr7 = &nbr8;
	nbr6 = &nbr7;
	nbr5 = &nbr6;
	nbr4 = &nbr5;
	nbr3 = &nbr4;
	nbr2 = &nbr3;
	nbr1 = &nbr2;
	*nbr = nbr1;
}