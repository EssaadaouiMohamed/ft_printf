/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messaada <messaada@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:49:33 by messaada          #+#    #+#             */
/*   Updated: 2023/11/16 20:00:11 by messaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			n += ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	else
		n += ft_putstr_fd("(null)", fd);
	return (n);
}
