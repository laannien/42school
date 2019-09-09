#include "libft.h"

char	*strdup(const char *s)
{
	int i;
	char *result;

	i = 0;
	result = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!result)
	{
		return (NULL);
	}
	while(s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
