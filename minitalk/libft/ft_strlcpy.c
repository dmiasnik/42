/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:47:30 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/11/12 11:35:57 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	q;

	q = 0;
	while (dstsize > 0 && q < dstsize - 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		q++;
	}
	while (*src != '\0')
	{
		src++;
		q++;
	}
	if (dstsize > 0)
		*dst = '\0';
	return (q);
}
