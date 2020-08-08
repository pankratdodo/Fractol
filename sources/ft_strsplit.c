#include "fract.h"

static char		*ft_memwrd(char const *s, char c, size_t *st)
{
	size_t	len;
	size_t	i;
	char	*word;

	word = NULL;
	if (s)
	{
		len = 0;
		while (s[*st] == c || s[*st] == '\t')
			(*st)++;
		while (s[*st + len] != c && s[*st + len] != '\t' && s[*st + len])
			len++;
		if ((word = (char *)malloc(sizeof(char) * len + 1)))
		{
			i = 0;
			while (i < len)
			{
				word[i] = s[*st + i];
				i++;
			}
			word[i] = '\0';
			*st += len;
		}
	}
	return (word);
}

static char		**ft_freewrd(char **to_del, size_t wrd)
{
	size_t i;

	if (to_del)
	{
		i = 0;
		while (i < wrd)
		{
			if (to_del[i])
				free(to_del[i]);
			i++;
		}
		free(to_del);
	}
	to_del = NULL;
	return (to_del);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	size_t	hw_wrd;
	size_t	st;
	size_t	wrd;

	words = NULL;
	wrd = 0;
	st = 0;
	if (s)
	{
		hw_wrd = ft_count_wrd(s, c);
		if ((words = (char **)malloc(sizeof(char *) * (hw_wrd + 1))))
		{
			while (wrd < hw_wrd)
			{
				if ((words[wrd] = ft_memwrd(s, c, &st)) == NULL)
					return (ft_freewrd(words, wrd));
				wrd++;
			}
			words[wrd] = NULL;
		}
	}
	return (words);
}
