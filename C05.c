ex00

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	factorial;
	int	index;

	if (nb < 0)
		return (0);
	index = 1;
	factorial = 1;
	while (index < nb + 1)
		factorial = factorial * index++;
	return (factorial);
}

int	main(void)
{
	int n;

	n = -2;
	while (n < 7)
	{
		printf("fact(%d) = %d\n", n, ft_iterative_factorial(n));
		n++;
	}
}



ex01

#include <stdio.h>

int	ft_recursive_factorial_recursive(int factorial, int number)
{
	factorial *= number--;
	if (number > 0)
		return (ft_recursive_factorial_recursive(factorial, number));
	return (factorial);
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (ft_recursive_factorial_recursive(1, nb));
}

int	main(void)
{
	int n;

	n = -2;
	while (n < 7)
	{
		printf("fact(%d) = %d\n", n, ft_recursive_factorial(n));
		n++;
	}
}


ex02

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int result;

	if (power < 0)
		return (0);
	result = 1;
	while (power-- > 0)
		result *= nb;
	return (result);
}

int	main(void)
{
	printf("10^2 = %d\n", ft_iterative_power(10, 2));
	printf("10^0 = %d\n", ft_iterative_power(10, 0));
	printf("10^-1 = %d\n", ft_iterative_power(10, -1));
	printf("10^5 = %d\n", ft_iterative_power(10, 5));
}



ex03

#include <stdio.h>

int	ft_recursive_power_recursive(int number, int power, int result)
{
	if (power-- > 0)
		return (ft_recursive_power_recursive(number, power, result *= number));
	return (result);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (ft_recursive_power_recursive(nb, power, 1));
}

int	main(void)
{
	printf("10^2 = %d\n", ft_recursive_power(10, 2));
	printf("10^0 = %d\n", ft_recursive_power(10, 0));
	printf("10^-1 = %d\n", ft_recursive_power(10, -1));
	printf("10^5 = %d\n", ft_recursive_power(10, 5));
}



ex04

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

int	main(void)
{
	int	index;

	index = -2;
	while (index < 16)
	{
		printf("fibonacci(%d) = %d\n", index, ft_fibonacci(index));
		index++;
	}
}


ex05

#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	unsigned int		sqrt;
	unsigned int		index;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	index = 0;
	while ((sqrt = index * index) <= (unsigned int)nb)
		index++;
	index -= 1;
	return (index * index == (unsigned int)nb ? index : 0);
}

int	main(void)
{
	int number;

	number = -2;
	while (number < 26)
	{
		printf("sqrt(%d) = %d\n", number, ft_sqrt(number));
		number++;
	}
	printf("sqrt(%d) = %d\n", 1000000, ft_sqrt(1000000));
	printf("sqrt(%d) = %d\n", INT_MAX, ft_sqrt(INT_MAX));
	printf("sqrt(%d) = %d\n", INT_MIN, ft_sqrt(INT_MIN));
	printf("sqrt(%d) = %d\n", 2147395600, ft_sqrt(2147395600));
}



ex06

#include <stdio.h>
#include <limits.h>
#include <math.h>

int	ft_sqrt(int nb)
{
	unsigned int		sqrt;
	unsigned int		index;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	index = 0;
	while ((sqrt = index * index) <= (unsigned int)nb)
		index++;
	index -= 1;
	return (index);
}

int	ft_is_prime(int nb)
{
	int	index;
	int	sqrt;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	index = 2;
	sqrt = ft_sqrt(nb);
	while ((index <= sqrt) && (nb % index != 0))
		index++;
	return (index > sqrt);
}

int	is_prime(int prime)
{
	int	i;
	int	sq;

	if (prime <= 1)
		return (0);
	sq = (int)sqrt(prime);
	for (i = 2; (i <= sq) && (prime % i != 0); i++);
	return (i > sq);
}

int	main(void)
{
	int	number;
	int	results[2];
	int	count;

	number = 0;
	count = 0;
	while (number < 50000)
	{
		results[0] = is_prime(number);
		results[1] = ft_is_prime(number);
		printf("is_prime(%d) = %d  --  %d\n", number, results[1], results[0]);
		if (results[0] != results[1])
			return (1);
		number++;
		if (results[0])
			count++;
	}
	printf("is_prime(%d) = %d\n", INT_MAX, is_prime(INT_MAX));
	printf("first 50'000 number, %d prime\n", count);
	return (0);
}



ex07

#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	unsigned int		sqrt;
	unsigned int		index;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	index = 0;
	while ((sqrt = index * index) <= (unsigned int)nb)
		index++;
	index -= 1;
	return (index);
}

int	ft_is_prime(int nb)
{
	int	index;
	int	sqrt;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	index = 2;
	sqrt = ft_sqrt(nb);
	while ((index <= sqrt) && (nb % index != 0))
		index++;
	return (index > sqrt);
}

int	ft_find_next_prime(int nb)
{
	while (true)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}

int	main(void)
{
	int	index;

	index = -2;
	while (index < 100)
	{
		printf("find_next_prime(%d) = %d\n", index, ft_find_next_prime(index));
		index++;
	}
	printf("find_next_prime(%d) = %d\n", INT_MAX, ft_find_next_prime(INT_MAX));
}



ex08

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

#define BOARD_SIZE 10

bool	is_queen_at_risk(int board[][BOARD_SIZE], int at_x, int at_y)
{
	int	x;
	int	y;
	int	offsets[2];

	offsets[0] = at_y - at_x;
	offsets[1] = at_y + at_x;
	x = 0;
	while (x < BOARD_SIZE)
	{
		y = 0;
		while (y < BOARD_SIZE)
		{
			if (x == at_x || y == at_y
				|| y == x + offsets[0] || y == -x + offsets[1])
				if (board[y][x])
					return (true);
			y++;
		}
		x++;
	}
	return (false);
}

void	dump_board(int board[][BOARD_SIZE], int c_x, int c_y)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < BOARD_SIZE)
	{
		j = 0;
		while (j < BOARD_SIZE)
		{
			if (c_y == i && c_x == j)
				c = board[i][j] ? 'O' : 'x';
			else
				c = board[i][j] ? 'o' : '-';
			printf("%c ", c);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}

void	clear_column(int board[][BOARD_SIZE], int x)
{
	int	index;

	index = 0;
	while (index < BOARD_SIZE)
	{
		board[index++][x] = false;
	}
}

void	print_queen_position(int board[][BOARD_SIZE])
{
	int	y;
	int	column;

	y = 0;
	while (y < BOARD_SIZE)
	{
		column = 0;
		while (column < BOARD_SIZE)
		{
			if (board[y][column])
			{
				write(1, &"0123456789"[column], 1);
				break ;
			}
			column++;
		}
		y++;
	}
	write(1, "\n", 1);
}

bool	recursive_find(int board[][BOARD_SIZE], int x, int *soluce)
{
	int	y;

	if (x >= BOARD_SIZE)
		return (true);
	y = 0;
	while (y < BOARD_SIZE)
	{
		if (!is_queen_at_risk(board, x, y))
		{
			board[y][x] = true;
			if (recursive_find(board, x + 1, soluce))
			{
				*soluce += 1;
				print_queen_position(board);
				// dump_board(board, x, y);
				// clear_column(board, x);
			}
			board[y][x] = false;
		}
		y++;
	}
	return (false);
}

int		ft_ten_queens_puzzle(void)
{
	int	soluce;
	int	board[BOARD_SIZE][BOARD_SIZE];
	int	column;

	soluce = 0;
	column = 0;
	while (column++ < BOARD_SIZE)
		clear_column(board, column - 1);
	recursive_find(board, 0, &soluce);
	printf("found %d\n", soluce);
	return (soluce);
}

int		main(void)
{
	ft_ten_queens_puzzle();
}

+++++++++++++++++++++++++
#include<stdio.h>
#include<math.h>
 
int board[20],count;
 
int main()
{
int n,i,j;
void queen(int row,int n);
 
printf(" - N Queens Problem Using Backtracking -");
printf("\n\nEnter number of Queens:");
scanf("%d",&n);
queen(1,n);
return 0;
}
 
//function for printing the solution
void print(int n)
{
int i,j;
printf("\n\nSolution %d:\n\n",++count);
 
for(i=1;i<=n;++i)
  printf("\t%d",i);
 
for(i=1;i<=n;++i)
{
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) //for nxn board
  {
   if(board[i]==j)
    printf("\tQ"); //queen at i,j position
   else
    printf("\t-"); //empty slot
  }
}
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
int i;
for(i=1;i<=row-1;++i)
{
  //checking column and digonal conflicts
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
}
 
return 1; //no conflicts
}
 
//function to check for proper positioning of queen
void queen(int row,int n)
{
int column;
for(column=1;column<=n;++column)
{
  if(place(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n) //dead end
    print(n); //printing the board configuration
   else //try queen with next position
    queen(row+1,n);
  }
}
}

