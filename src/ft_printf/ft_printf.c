/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:21:30 by kpawlows          #+#    #+#             */
/*   Updated: 2022/11/28 17:08:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (n == 0)
		return (src_len);
	while (i < (n - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

int	ft_intcharnb(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

void	ft_sign(char *s, int *sign, int *n)
{
		s[0] = '-';
		*n *= -1;
		*sign = 1;
}

char	*ft_min(char *s)
{
	ft_strlcpy(s, "-2147483648", 12);
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	int		sign;
	char	*s;

	size = ft_intcharnb(n);
	sign = 0;
	s = malloc(sizeof(char) * size + 2);
	if (s == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_min(s));
	if (n < 0)
		ft_sign(s, &sign, &n);
	i = size;
	while (i >= sign)
	{
		s[i] = (n % 10 + '0');
		n /= 10;
		i--;
	}
	s[size + 1] = '\0';
	return (s);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n *(-1), fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	slen;

	slen = ft_strlen(s);
	write(fd, s, slen);
}*/

int	ft_add_chars(char c, long arg)
{
	int	charcount;

	charcount = 0;
	if (c == 'c' || c == '%' || c == 'k')
		charcount = 1;
	if (c == 'd' || c == 'i')
		charcount = ft_nblen((int) arg);
	if (c == 'u')
		charcount = ft_nblen((unsigned int) arg);
	if (c == 's' && (char *)arg != NULL)
		charcount = ft_strlen((char *)arg);
	if (c == 's' && (char *)arg == NULL)
	{
		charcount = 6;
		ft_putstr_fd("(null)", 1);
	}
	return (charcount);
}

int	ft_put_value(char c, long arg)
{
	int	h;

	h = 0;
	if (c == 'c' || c == '%' || c == 'k')
		ft_putchar_fd(arg, 1);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(arg, 1);
	if (c == 'u')
		ft_putnbr_uns_fd((unsigned int)arg, 1);
	if (c == 's' && (char *)arg != NULL)
		ft_putstr_fd((char *)arg, 1);
	if (c == 'x')
		h = ft_puthex((unsigned int)arg, (unsigned int)arg, "0123456789abcdef");
	if (c == 'X')
		h = ft_puthex((unsigned int)arg, (unsigned int)arg, "0123456789ABCDEF");
	if (c == 'p')
		h = ft_putaddr((void *)arg);
	return (ft_add_chars(c, arg) + h);
}

int	ft_printf(const char *argv, ...)
{
	int		i;
	int		charcount;
	va_list	args;

	va_start(args, argv);
	i = -1;
	charcount = 0;
	while (argv[++i] != '\0')
	{
		if (argv[i] == '%')
		{
			if (argv[++i] == '%')
				charcount += ft_put_value('k', argv[i]);
			else
				charcount += ft_put_value(argv[i], va_arg(args, long));
		}
		else
			charcount += ft_put_value('k', argv[i]);
	}
	va_end(args);
	return (charcount);
}
