#include "header.h"

void	reverse_order(char *vec, int n)
{
	int		inc;
	char	temp;

	inc = 0;
	while (inc < n / 2)
	{
		temp = vec[inc];
		vec[inc] = vec[n - inc - 1];
		vec[n - inc - 1] = temp;
		inc++;
	}
}

int	view_calc(char *vec, int n, char test, int rev)
{
	int		inc;
	int		no_building;
	char	last_building;
	char	building_views;

	inc = 0;
	no_building = 1;
	if (rev == 1)
		reverse_order(vec, n);
	last_building = vec[inc];
	while (inc < n - 1)
	{
		if (vec[inc + 1] > last_building)
		{
			no_building++;
			last_building = vec[inc + 1];
		}
		inc++;
	}
	building_views = '0' + no_building;
	return (test != building_views);
}

int	ft_view_col(int col, char *user_input, int n, char *view_col)
{
	if (view_calc(view_col, n, *(user_input + col), 0)
		|| view_calc(view_col, n, *(user_input + col + n), 1))
		return (1);
	else
		return (0);
}

int	create_test_ptr(char *test_ptr, char *all_comb, int row, int n)
{
	int	inc;

	inc = 0;
	while (inc < n)
	{
		*(test_ptr + inc + row * n) = all_comb[inc];
		inc++;
	}
	return (0);
}

void	set_value_pairs(char *pair, int *pair_locs, int row, char *user_input)
{
	int	n;

	n = ft_calc_n(user_input);
	*pair = user_input[n * 2 + row];
	*(pair + 1) = user_input[n * 3 + row];
	*pair_locs = 0;
	*(pair_locs + 1) = -2;
}
