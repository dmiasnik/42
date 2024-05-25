/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:47:39 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/17 11:47:53 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*r;	
	size_t	slen;

	slen = ft_strlen(s);
	if (slen <= start)
		len = 0;
	slen = slen - start;
	if (slen < len)
		len = slen;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	r = res;
	while (*s && start-- > 0)
		s++;
	while (*s && len-- > 0)
		*res++ = *s++;
	*res = 0;
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*r;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	r = res;
	while (*s1)
	{
		*res = *s1;
		s1++;
		res++;
	}
	while (*s2)
	{
		*res = *s2;
		s2++;
		res++;
	}
	*res = 0;
	return (r);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	while (*s)
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (*s == cc)
		return ((char *)s);
	return (0);
}
