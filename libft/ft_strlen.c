#include "libft.h"

int        ft_strlen(const char *str)
{
    int         i;

	if (!str)
		return (0);
    i = 0;
    while (str[i])
    {
        i += 1;
    }
    return (i);
}
