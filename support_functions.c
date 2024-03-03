#include "header.h"

int	ft_row_val(int n)
{
	int	row_val;

	row_val = 0;
	while (n > 0)
	{
		row_val = row_val + n;
		n--;
	}
	return (row_val);
}

int	check_col_rep(char *test_ptr, int row, int n)
{
	int	inc;
	int	inc_c;

	inc = 0;
	while (n > inc)
	{
		inc_c = 0;
		while (inc_c < row - 1)
		{
			if (test_ptr[inc + inc_c * n] == test_ptr[inc + (row - 1) * n])
				return (0);
			inc_c++;
		}
		inc++;
	}
	return (1);
}

int	len_char(char *ch)
{
	int	inc;

	inc = 0;
	while (ch[inc] != '\0')
		inc++;
	return (inc);
}

void	ft_create_numbers(int n, char *all_numbers)
{
	int	inc;

	inc = 0;
	while (inc < n)
	{
		*(all_numbers + inc) = '1' + inc;
		inc++;
	}
	*(all_numbers + n) = '\0';
}

int	check_view(char *view, char *user_input, int n)
{
	int	inc;

	inc = len_char(user_input) / 2;
	while (inc < len_char(user_input) * 3 / 4)
	{
		if (user_input[inc] == view[0] && user_input[inc + n] == view[1])
			return (0);
		inc++;
	}
	return (1);
}
