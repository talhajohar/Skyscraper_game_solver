#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

int		ft_built(char *user_input, char *all_comb, char *views_vec, char *test_ptr, int row);
int		check_col_rep(char *test_ptr, int row, int n);
int		ft_test_return(char *test_ptr, char *user_input, int n);
int		ft_pair_search(char *pair, char *views_inc, int n, int *pair_loc);
int		ft_test(char *test_ptr, char *user_input, int n);
int		ft_view_col(int col, char *user_input, int n, char *view_col);
int		ft_row_val(int n);
int		ft_factorial(int n);
void	ft_print(char *test_ptr, int n);
void	ft_top_view(char a[], int n, int start_pos, char views[]);
void	ft_create_numbers(int n, char *all_numbers);
int		check_if_present(char ch_to_check, char *num_generator, int pos);
void	perm_builder(char *all_combs, int n, int num, int *postion, char *num_generator, char *views_vec);
int		len_char(char *ch);
void	delete_view(int loc, char *views_vec, char *all_comb, int n);
int		check_view(char *view, char *user_input, int n);
void	remove_views(char *all_comb, char *views_vec, char *user_input, int n);
void	ft_possible_arrang(int n, char *user_input);
void	ft_putchar(char sel_char);
int		ft_calc_n(char *str);
int		create_test_ptr(char *test_ptr, char *all_comb, int row, int n);
void	set_value_pairs(char *pair, int *pair_locs, int row, char *user_input);
int		ft_error_exit(char *str);

#endif
