/* =========================================================================================================
  EXERCICI 00
  ==========================================================================================================*/

#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

#include <stdio.h>

int	main(void)
{
	int	a;

	a = 333;
	printf("before: %d\n", a);
	ft_ft(&a);
	printf("after : %d\n", a);
}


/* =========================================================================================================
  EXERCICI 01
  ==========================================================================================================*/

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	*ptr1;
	int	**ptr2;
	int	***ptr3;
	int	****ptr4;
	int	*****ptr5;
	int	******ptr6;
	int	*******ptr7;
	int	********ptr8;
	int	*********ptr9;

	a = 999;
	ptr1 = &a;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	printf("before: %d\n", a);
	printf("before a address: %p\n", &a);
	printf("before ptr1 aim to address: %p\n", ptr1);
	printf("before ptr1 own address: %p\n", &ptr1);
	printf("before ptr2 aim to address: %p\n", ptr2);
	printf("before ptr3 aim to address: %p\n", ptr3);
	printf("before ptr9 aim to address: %p\n", ptr9);
	ft_ultimate_ft(ptr9);
	printf("after : %d\n", a);
	printf("after a adress: %p\n", &a);
	printf("after ptr1 aim to address: %p\n", ptr1);
	printf("after ptr1 own address: %p\n", &ptr1);
	printf("after ptr2 aim to address: %p\n", ptr2);
	printf("after ptr3 aim to address: %p\n", ptr3);
	printf("after ptr9 aim to address: %p\n", ptr9);
}


/* =========================================================================================================
  EXERCICI 02
  ==========================================================================================================*/
void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

#include <stdio.h>

int		main(void)
{
	int a;
	int b;

	a = 1;
	b = 2;
	printf("before: %d %d\n", a, b);
	ft_swap(&a, &b);
	printf("after: %d %d\n", a, b);
}



/* =========================================================================================================
  EXERCICI 03
  ==========================================================================================================*/
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

#include <stdio.h>

int		main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 5;
	b = 2;
	ft_div_mod(a, b, &div, &mod);
	printf("%d / %d = %d, remainder %d\n", a, b, div, mod);
}



/* =========================================================================================================
  EXERCICI 04
  ==========================================================================================================*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int div;
	int mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

#include <stdio.h>

int		main(void)
{
	int a;
	int b;

	a = 5;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("div %d, remainder %d", a, b);
}


/* =========================================================================================================
  EXERCICI 05
  ==========================================================================================================*/

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	char next_char;

	while (true)
	{
		next_char = *str;
		if (next_char == '\0')
		{
			break ;
		}
		ft_putchar(next_char);
		str++;
	}
}

#include <stdio.h>

int		main(void)
{
	char stri[] = "Hello World again 42";
	char *first_pointer;
	
	first_pointer = &stri[0];
	ft_putstr(first_pointer);
	printf("\nEntrada : %s\n", stri);
}


/* =========================================================================================================
  EXERCICI 06
  ==========================================================================================================*/

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (*(str++) != '\0')
	{
		length++;
	}
	return (length);
}

#include <stdio.h>


int		main(void)
{
	char	string[] = "Hello World 42 again and again";
	char	*first_pointer;
	int		length;

	first_pointer = &string[0];
	length = ft_strlen(first_pointer);
	printf("length %d\n", length);
}



/* =========================================================================================================
  EXERCICI 07
  ==========================================================================================================*/

void	ft_rev_int_tab(int *tab, int size)
{
	int index;
	int tmp;

	index = 0;
	while (index < size / 2)
	{
		tmp = tab[index];
		tab[index] = tab[size - 1 - index];
		tab[size - 1 - index] = tmp;
		index++;
	}
}

#include <stdio.h>

void	print_array(int numbers[], int size)
{
	int index;

	printf("[ ");
	index = 0;
	while (index < size)
	{
		printf("%d", numbers[index]);
		if (index != size - 1)
		{
			printf(", ");
		}
		index++;
	}
	printf(" ]");
}

int		main(void)
{
	int numbers[10];
	int *first_pointer;
	int val;
	int i;

	val = 0;
	i = 0;
	while (i <= 9)
	{
		numbers[i] = val;
		i++;
		val++;
	}
	first_pointer = &numbers[0];
	printf("before: ");
	print_array(numbers, 10);
	ft_rev_int_tab(first_pointer, 10);
	printf("\nafter : ");
	print_array(numbers, 10);
}


/* =========================================================================================================
  EXERCICI 08
  ==========================================================================================================*/

#include <stdbool.h>

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		read_index;
	int		index;
	bool	swapped;

	read_index = 0;
	while (true)
	{
		swapped = false;
		index = 0;
		while (index < size)
		{
			if (tab[index] > tab[index + 1])
			{
				ft_swap(&tab[index], &tab[index + 1]);
				swapped = true;
			}
			index++;
		}
		if (!swapped)
		{
			break ;
		}
		read_index++;
	}
}

#include <stdio.h>

void	print_array(int numbers[], int size)
{
	int index;

	printf("[ ");
	index = 0;
	while (index < size)
	{
		printf("%d", numbers[index]);
		if (index != size - 1)
		{
			printf(", ");
		}
		index++;
	}
	printf(" ]");
}

int		main(void)
{
	int numbers[9] = {-2, 0, 4, 12, 14, 8, 10, 2, 6};
	int *first_pointer;
	
	first_pointer = &numbers[0];
	printf("before: ");
	print_array(numbers, 9);
	ft_sort_int_tab(first_pointer, 9);
	printf("\nafter : ");
	print_array(numbers, 9);
}

