/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:02:40 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/12 18:21:39 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	getlen(char const *s, unsigned int start, size_t len)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (slen <= start)
		return (0);
	slen = slen - start;
	if (slen < len)
		return (slen);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*r;

	len = getlen(s, start, len);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	r = res;
	while (*s && start > 0)
	{
		s++;
		start--;
	}
	while (*s && len > 0)
	{
		*res = *s;
		s++;
		res++;
		len--;
	}
	*res = 0;
	return (r);
}
