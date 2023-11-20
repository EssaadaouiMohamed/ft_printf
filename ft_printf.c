/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messaada <messaada@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:09:44 by messaada          #+#    #+#             */
/*   Updated: 2023/11/17 11:56:10 by messaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer(unsigned long num)
{
	int	n;

	n = 0;
	if (((void *)num) == NULL)
		return (ft_putstr_fd("(nil)", 1));
	n += ft_putstr_fd("0x", 1);
	n += ft_putnbr_base(num, "0123456789abcdef");
	return (n);
}

static int	print_type(char c, va_list ptr)
{
	int	n;

	n = 0;
	if (c == 'c')
		return (ft_putchar_fd(va_arg(ptr, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(ptr, char *), 1));
	else if (c == 'p')
		return (print_pointer(va_arg(ptr, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(ptr, int), 1));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789"));
	else if (c == 'x')
		return ((ft_putnbr_base(va_arg(ptr, unsigned int),
					"0123456789abcdef")));
	else if (c == 'X')
		return ((ft_putnbr_base(va_arg(ptr, unsigned int),
					"0123456789ABCDEF")));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		n;

	n = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			n += print_type(str[i + 1], ptr);
			i++;
		}
		else
			n += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(ptr);
	return (n);
}

int main()
{
	printf(NULL);
}
