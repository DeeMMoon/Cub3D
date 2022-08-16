/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:52:11 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:34 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;
	int		last;

	p = (char *) s;
	i = 0;
	last = -1;
	while (p[i])
	{
		if (p[i] == (unsigned char)c)
			last = i;
		i++;
	}
	if (last > -1)
		return (&p[last]);
	if (p[i] == (unsigned char)c)
		return (&p[i]);
	return (0);
}	
