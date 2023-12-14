/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:42:17 by marvin            #+#    #+#             */
/*   Updated: 2023/10/17 16:42:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	while (len -- > 0)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (((char *)s1)[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
