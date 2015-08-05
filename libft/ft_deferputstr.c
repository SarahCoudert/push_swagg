#include "libft.h"
#include <unistd.h>

void				ft_deferputstr(char *s)
{
	int		i;
	static char	s_c = 0;

	i = 0;
	while (s[i])
	{
		if (s_c != 0)
			write(1, &s_c, 1);
		s_c = s[i];
		i++;
	}	
}