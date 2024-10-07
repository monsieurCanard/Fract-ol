/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:57 by marvin            #+#    #+#             */
/*   Updated: 2023/10/24 10:56:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void ft_putstr_fd(char *s, int fd)
{
	int i;
	ssize_t ret;

	i = 0;
	if (!s)
		return;
	if (fd < 0)
		return;
	while (s[i])
		ret = write(fd, &s[i++], 1);
	(void)ret;
}
