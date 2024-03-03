#include "header.h"

int	ft_digit_wr(char *str, int n)
{
	int	inc;

	inc = 0;
	while (*(str + inc) != '\0')
	{
		if (!(*(str + inc) >= '1' && *(str + inc) <= ('0' + n)))
		{
			ft_putchar('E');
			return (-1);
		}
		inc++;
	}
	return (0);
}

int	ft_calc_n(char *str)
{
	int	inc;

	inc = 0;
	while (str[inc] != '\0')
	{
		inc++;
	}
	if ((inc % 4) != 0)
	{
		ft_putchar('E');
		return (-1);
	}
	return (inc / 4);
}

int	process_input(char *ag, char *str)
{
	int		inc;
	int		inc1;

	inc = 0;
	inc1 = 0;
	while ((*(ag + inc)) != '\0')
	{
		if (ag[inc] > '0' && ag[inc] <= '9')
			str[inc1++] = ag[inc++];
		else
		{
			ft_putchar('E');
			return (0);
		}
		if (ag[inc] == ' ' && (ag[inc + 1] > '0' && ag[inc + 1] <= '9'))
			inc++;
		else if (ag[inc] == '\0')
			str[inc1] = '\0';
		else
		{
			ft_putchar('E');
			return (0);
		}
	}
	return (ft_error_exit(str));
}

int	ft_error_exit(char *str)
{
	int	n;

	n = ft_calc_n(str);
	if (n == -1)
		return (0);
	if (ft_digit_wr(str, n) == -1)
		return (0);
	return (n);
}

int	main(int argc, char *argv[])
{
	char	str[37];
	int		s;

	if (argc != 2)
	{
		ft_putchar('E');
		return (1);
	}
	s = process_input(argv[1], str);
	if (s != 0)
	{
		ft_possible_arrang(s, str);
		return (0);
	}
	else
		return (1);
}
