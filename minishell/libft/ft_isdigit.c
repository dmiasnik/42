/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:40:04 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/09 13:51:54 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/*
#include <unistd.h>
int main()
{
	if (ft_isdigit(49))
	{
		write(1,"1",1);
	}
	return 0;
}*/