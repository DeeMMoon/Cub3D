/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:04:51 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/16 12:58:52 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
		{
			result = (unsigned char *)(s + i);
			return (result);
		}
		i++;
	}
	return (0);
}
