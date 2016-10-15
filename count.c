#include "fdf.h"

int   ft_count_x(char *str)
{
    int   count;

    count = 0;
    while (*str != '\n' && *str != '\0')
    {
      while (*str == ' ')
        str++;
      if ((*str <= '9' && *str >= '0') || *str == '-')
        count++;
      while (*str != '\0' && *str != ' ' && *str != '\n')
        str++;
    }
    return (count);
}

int			*ft_putline(char *str)
{
	int *tab;
	int columns;
	int i;

	if (!str || *str == '\n' || *str == '\0')
		return (NULL);
	columns = ft_count_x(str);
	if (*str == '\n' || columns == 0)
		return (NULL);
	tab = (int*)malloc(sizeof(int) * (columns + 1));
	i = 0;
	tab[i++] = columns;
	while (*str != '\0' && *str != '\n')
	{
    while (*str == ' ')
			str++;
		if ((*str <= '9' && *str >= '0') || *str == '-')
			tab[i++] = ft_atoi(str);
		while (*str != '\0' && *str != '\n' && *str != ' ')
			str++;
	}
	return (tab);
}
