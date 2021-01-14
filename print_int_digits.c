/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:26:04 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 17:53:51 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void				ft_print_positive_int(int n, t_struct *blocks, int base)
{
	if (blocks->f_minus)
	{
		ft_print_precision_digits(blocks);
		ft_putnbr_base(n, blocks, base);
		ft_print_width_digits(blocks);
	}
	else
	{
		ft_print_width_digits(blocks);
		ft_print_precision_digits(blocks);
		ft_putnbr_base(n, blocks, base);
	}
}

void				ft_print_zero_valued_int(int n, t_struct *blocks, int base)
{
	if (blocks->f_prec && !blocks->precision)
	{
		if (!blocks->f_width || n == 0)
			blocks->chars_to_print = 0;
		ft_print_width_digits(blocks);
		return ;
	}
	ft_print_positive_int(-n, blocks, base);
}

void				ft_order_to_print_digits(t_struct *blocks, int n, int base)
{
	if (n > 0)
		ft_print_positive_int(n, blocks, base);
	if (n == 0)
		ft_print_zero_valued_int(n, blocks, base);
	if (n < 0 && base == 10)
		ft_print_negative_int(n, blocks, base);
	if (n < 0 && base != 10)
		ft_print_positive_int(n, blocks, base);
}

void				ft_putnbr_base(int n, t_struct *blocks, int base)
{
	static char		base_blocks[17] = "0123456789ABCDEF\0";
	char			result[12];
	unsigned int	tmp;
	int				i;

	i = 0;
	if (n < 0 && base == 10)
		tmp = -n;
	else
		tmp = n;
	if (n == 0)
	{
		result[i] = '0';
		blocks->total_printed += write(1, &result[i], 1);
		return ;
	}
	while (tmp > 0)
	{
		result[i] = ft_check_hex(blocks->format, base_blocks[tmp % base]);
		tmp /= base;
		i++;
	}
	i--;
	while (i > -1)
		blocks->total_printed += write(1, &result[i--], 1);
}
