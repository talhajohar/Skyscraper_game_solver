#include "header.h"

void	ft_putchar(char sel_char)
{
	if (sel_char == 'E')
		write (1, "Error\n", 6);
}

void	print_line(int n)
{
	int	inc;

	inc = 0;
	while (inc < n)
	{
		write(1, "-", 1);
		inc++;
	}
	write(1, "\n", 1);
}

void	ft_print(char *test_ptr, int n)
{
	int		inc;
	char	print;

	inc = 0;
	while (inc <= n * n)
	{
		print = *(test_ptr + inc);
		write(1, &print, 1);
		write(1, " ", 1);
		if ((inc % n) == n - 1)
			write(1, "\n", 1);
		inc++;
	}
}
