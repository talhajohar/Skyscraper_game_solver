#include "header.h"

int	ft_test(char *test_ptr, char *user_input, int n)
{
	int		inc;
	int		inc1;
	char	*view_col;

	view_col = (char *)malloc(sizeof(char) * n);
	inc = 0;
	while (inc < n)
	{
		inc1 = 0;
		while (inc1 < n)
		{
			view_col[inc1] = *(test_ptr + inc1 * n + inc);
			inc1++;
		}
		if (ft_view_col(inc, user_input, n, view_col))
		{
			free(view_col);
			return (0);
		}
		inc++;
	}
	free(view_col);
	return (1);
}

int	ft_pair_search(char *pair, char *views_inc, int n, int *pair_loc)
{
	int	inc;

	inc = *(pair_loc + 1);
	while (views_inc[inc] != '\0')
	{
		if (*(pair) == *(views_inc + inc)
			&& *(pair + 1) == *(views_inc + inc + 1))
		{
			*(pair_loc) = inc / 2 * n;
			*(pair_loc + 1) = inc;
			return (0);
		}
		inc = inc + 2;
	}
	return (1);
}

int	ft_test_return(char *test_ptr, char *user_input, int n)
{
	int	test_value;

	test_value = ft_test(test_ptr, user_input, n);
	if (test_value == 1)
	{
		ft_print(test_ptr, n);
		return (-2);
	}
	else
		return (0);
}

int	ft_built(char *user_input, char *all_comb, char *views_vec, char *test_ptr, int row)
{
	char	pair[2];
	int		pair_locs[2];
	int		inc;
	int		n;

	n = ft_calc_n(user_input);
	if (row == n)
		return (ft_test_return(test_ptr, user_input, n));
	else
	{
		set_value_pairs(&pair[0], &pair_locs[0], row, user_input);
		while (pair_locs[0] != -1 && (pair_locs[1] == -2
				|| (views_vec[pair_locs[1]] != '\0')))
		{
			pair_locs[1] = pair_locs[1] + 2;
			if (ft_pair_search(pair, views_vec, n, pair_locs))
				return (0);
			inc = create_test_ptr(test_ptr, &all_comb[pair_locs[0]], row, n);
			if (check_col_rep(test_ptr, row + 1, n))
				inc = ft_built(user_input, all_comb, views_vec, test_ptr, row + 1);
			if (inc == -2)
				return (-2);
		}
	}
	return (0);
}
