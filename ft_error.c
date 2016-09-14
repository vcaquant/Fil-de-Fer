#include "fdf.h"

int   ft_error(int ac)
{
  if (ac != 2)
  {
    ft_putstr("error syntax : ./fdf <file>");
    return (-1);
  }
  return (0);
}
