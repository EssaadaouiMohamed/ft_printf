/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messaada <messaada@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:36:40 by messaada          #+#    #+#             */
/*   Updated: 2023/11/16 20:18:36 by messaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(size_t number, char *base)
{
	size_t	len;
	int		n;

	n = 0;
	len = ft_strlen(base);
	if (number >= len)
		n += ft_putnbr_base(number / len, base);
	n += ft_putchar_fd(base[number % len], 1);
	return (n);
}
