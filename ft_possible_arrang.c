#include "header.h"

int	check_if_present(char ch_to_check, char *num_generator, int pos)
{
	int	inc;

	inc = 0;
	while (inc < pos && ch_to_check != num_generator[inc])
		inc++;
	if (inc == pos)
		return (1);
	else
		return (0);
}

void	perm_builder(char *all_combs, int n, int num, int *postion, char *num_generator, char *views_vec)
{
	int		inc;
	char	*all_numbers;
	
	all_numbers = (char *)malloc(sizeof(char) * (n + 1));
	ft_create_numbers(n, all_numbers);
	inc = 0;
	if (num == n)
	{
		ft_top_view(num_generator, n, *postion / n * 2, views_vec);
		while (inc < n)
		{
			all_combs[*postion] = num_generator[inc++];
			*postion += 1;
		}
		all_combs[*postion] = '\0';
	}
	else
	{
		while (n > inc)
		{
			if (check_if_present(all_numbers[inc], num_generator, num))
			{
				num_generator[num] = all_numbers[inc];
				perm_builder(all_combs, n, num + 1, postion, num_generator, views_vec);
			}
			inc++;
		}
	}
	free(all_numbers);
}

void	delete_view(int loc, char *views_vec, char *all_comb, int n)
{
	int	inc;

	inc = 0;
	while (views_vec[loc + inc + 2] != '\0')
	{
		views_vec[loc + inc] = views_vec[loc + inc + 2];
		inc++;
	}
	views_vec[loc + inc] = '\0';
	inc = 0;
	while (all_comb[loc / 2 * n + inc] != '\0')
	{
		all_comb[loc / 2 * n + inc] = all_comb[loc / 2 * n + inc + n];
		inc++;
	}
	all_comb[loc / 2 * n + inc] = '\0';
}

void	remove_views(char *all_combination, char *views_vec, char *user_input, int n)
{
	int	inc;
	
	inc = 0;
	while (inc < len_char(views_vec))
	{
		if (check_view(&views_vec[inc], user_input, n))
			delete_view(inc, views_vec, all_combination, n);
		else
			inc += 2;
	}
}

void	ft_possible_arrang(int n, char *user_input)
{
	char	*all_comb;
	char	*views_vec;
	char	*test_set;
	char	*num_generator;
	int		position;

	position = 0;
	num_generator = (char *)malloc(sizeof(char) * (n + 1));
	all_comb = (char *)malloc(sizeof(char) * (n * ft_factorial(n) + 1));
	views_vec = (char *)malloc(sizeof(char) * (n * ft_factorial(n) + 1));
	test_set = (char *)malloc(sizeof(char) * (n * n + 1));
	perm_builder(all_comb, n, 0, &position, num_generator, views_vec);
	remove_views(all_comb, views_vec, user_input, n);
	ft_built(user_input, all_comb, views_vec, test_set, 0);
	free(all_comb);
	free(views_vec);
	free(test_set);
}
