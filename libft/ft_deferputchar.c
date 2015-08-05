#include "libft.h"

void			ft_deferputchar(char c)
{
	static char	s_c = 0;

	if (s_c != 0)
		write(1, &s_c, 1);
	s_c = c;
}