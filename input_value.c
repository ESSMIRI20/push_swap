#include "push_swap.h"

int	ft_atoi(char *s)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 0;
	r = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
	{
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			r = -1;
		i++;
	}
	while (s[i] != '\0' && (s[i] <= 57 && s[i] >= 48))
	{
		j = j * 10;
		j += s[i] - 48;
		i++;
	}
	return (j * r);
}


static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static char	*copy_word(const char *start, size_t length)
{
	size_t	i;
	char	*word;

	word = malloc(length + 1);
	i = 0;
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[length] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		**result;
	const char	*start;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i++] = copy_word(start, s - start);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

void check_int(t_stack **stack, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	char **r = ft_split(s, ' ');
	if (r[i] == NULL)
	{
		put_str("Error\n");
		exit(1);
	}
	while (r[i])
	{
	if (r[i][j] == '-' || r[i][j] == '+')
		j++;
	while (r[i][j])
	{
		if ((r[i][j] <= 57 && r[i][j] >= 48))
			j++;
		else
		{
			put_str("Error\n");
			exit(1);
		}
	}
	//	printf("%d\t", atoi(r[i]));
	ft_lstadd_back(stack, ft_atoi(r[i]));
	i++;
	}	
}