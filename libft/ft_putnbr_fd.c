/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messaada <messaada@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:18:21 by messaada          #+#    #+#             */
/*   Updated: 2023/11/16 20:01:40 by messaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	printed;

	printed = 0;
	if (n == -2147483648)
		printed += write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		printed += ft_putchar_fd('-', fd);
		printed += ft_putnbr_fd(n * -1, fd);
	}
	else if (n > 9)
	{
		printed += ft_putnbr_fd(n / 10, fd);
		printed += ft_putchar_fd('0' + (n % 10), fd);
	}
	else
		printed += ft_putchar_fd(n + '0', fd);
	return (printed);
}
