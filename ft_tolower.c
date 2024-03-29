/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:14:19 by marvin            #+#    #+#             */
/*   Updated: 2023/10/17 15:14:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

char	*ft_tolower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		i++;
	}
	return (str);
}
