#include "header.h"

int	ft_down_view(char a[], int n)
{
	int	no_building;
	int	inc;
	int	last_building;

	no_building = 1;
	inc = 0;
	last_building = a[n - 1];
	while (inc < n - 1)
	{
		if (a[n - inc - 2] > last_building)
		{
			no_building++;
			last_building = a[n - inc - 2];
		}
		inc++;
	}
	return (no_building);
}

void	ft_top_view(char a[], int n, int start_pos, char views[])
{
	int		inc;
	int		no_building;
	char	last_building;
	char	building_views;

	inc = 0;
	no_building = 1;
	last_building = a[inc];
	while (inc < n - 1)
	{
		if (a[inc + 1] > last_building)
		{
			no_building++;
			last_building = a[inc + 1];
		}
		inc++;
	}
	building_views = '0' + ft_down_view(a, n);
	views[1 + start_pos] = building_views;
	building_views = '0' + no_building;
	views[start_pos] = building_views;
	views[2 + start_pos] = '\0';
}

int	ft_factorial(int n)
{
	int	fact;

	fact = 1;
	while (n > 0)
	{
		fact = fact * n;
		n--;
	}
	return (fact);
}

void	store_char(char *a, char *b)
{
	int	inc;

	inc = 0;
	while (*(a + inc) != '\0')
	{
		*(b + inc) = *(a + inc);
		inc++;
	}
	*(b + inc) = '\0';
}
