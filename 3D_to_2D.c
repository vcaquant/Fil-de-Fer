#include "fdf.h"

t_env   ft_3D_to_2D(int x, int y, int z)
{
  t_env   n;

  n.p = (16777215 - (((z * z / 2) / 27 * 132344 + 42) % 16777215)) / 2;
  x = x * 30;
  z = z * -2;
  y = y * 30;
  n.x = (x - y) * 0.894427191 + 960;
  n.y = (z + (x + y) * 0.4472135955) + 128;
  return (n);
}
