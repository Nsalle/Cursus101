/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 23:09:44 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:42:10 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		nbword(const char *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

static char		*ft_malloc_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*rep;

	len = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	if (!(rep = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		rep[i] = s[i];
		i++;
	}
	rep[i] = '\0';
	return (rep);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**rep;
	int		j;

	if (s == NULL)
		return (NULL);
	if (!(rep = (char**)malloc(sizeof(char*) * nbword(s, c) + 1)))
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			rep[j++] = ft_malloc_word(s, c);
		}
		while (*s && *s != c)
			s++;
	}
	rep[j] = NULL;
	return (rep);
}
