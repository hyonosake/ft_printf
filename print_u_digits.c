/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:09:29 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 17:41:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void				ft_print_zero_valued_u(unsigned int n,
										t_struct *blocks, int base)
{
	if (blocks->f_prec && !blocks->precision)
	{
		blocks->chars_to_print = 0;
		ft_print_width_digits(blocks);
		return ;
	}
	if (blocks->f_minus)
	{
		ft_print_precision_digits(blocks);
		ft_putnbr_base_u(n, blocks, base);
		ft_print_width_digits(blocks);
	}
	else
	{
		ft_print_width_digits(blocks);
		ft_print_precision_digits(blocks);
		ft_putnbr_base(n, blocks, base);
	}
}

void				ft_print_positive_u(unsigned int n,
										t_struct *blocks, int base)
{
	if (blocks->f_minus)
	{
		ft_print_precision_digits(blocks);
		ft_putnbr_base_u(n, blocks, base);
		ft_print_width_digits(blocks);
	}
	else
	{
		ft_print_width_digits(blocks);
		ft_print_precision_digits(blocks);
		ft_putnbr_base_u(n, blocks, base);
	}
}

void				ft_order_to_print_u_digits(t_struct *blocks,
											unsigned int n, int base)
{
	if (n > 0)
		ft_print_positive_u(n, blocks, base);
	if (n == 0)
		ft_print_zero_valued_u(n, blocks, base);
}

void				ft_putnbr_base_u(unsigned int n, t_struct *blocks, int base)
{
	static char		base_blocks[17] = "0123456789ABCDEF\0";
	char			result[15];
	int				i;
	unsigned int	tmp;

	i = 0;
	tmp = n;
	if (tmp == 0)
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
	{
		blocks->total_printed += write(1, &result[i--], 1);
	}
}
