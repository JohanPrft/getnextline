
#include "get_next_line.h"

void	trim_buff(char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buff[i] != '\n' && i < BUFFER_SIZE - 1)
		i++;
	i++;
	j = 0;
	if (buff[i] == '\n')
		buff[j] = buff[i];
	while (buff[i] != '\n' && buff[j] && i < BUFFER_SIZE)
	{
		buff[j] = buff[i];
		i++;
		j++;
	}
	if (buff[i] == '\n')
		buff[j++] = buff[i];
	buff[j] = '\0';
}

char	*get_strbuff(char	*buff)
{
	int		i;
	char	*str;

	i = 0;
	while (buff[i - 1] != '\n')
		i++;
	str = malloc(sizeof(*str) * (i + 1));
	i = 0;
	while (buff[i - 1] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = '\0';
	trim_buff(buff);
	return (str);
}

int	main(void)
{
	char buff[BUFFER_SIZE] = "emploi\nsale\n";
	char	*str;

	str = get_strbuff(buff);
	printf("%s", str);
	printf("%s", buff);
	return (0);
}
