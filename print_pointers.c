/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:50:09 by alex              #+#    #+#             */
/*   Updated: 2021/01/14 19:52:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void				ft_print_p(unsigned long n, t_struct *blocks, int base)
{
	static char		ident[3] = "0x\0";

	if (blocks->f_minus)
	{
		blocks->total_printed += write(1, ident, 2);
		ft_print_precision_digits(blocks);
		ft_putnbr_pointer(n, blocks, base);
		ft_print_width_digits(blocks);
	}
	else
	{
		ft_print_width_digits(blocks);
		blocks->total_printed += write(1, ident, 2);
		ft_print_precision_digits(blocks);
		ft_putnbr_pointer(n, blocks, base);
	}
}

void				ft_putnbr_pointer(unsigned long n,
									t_struct *blocks, int base)
{
	static char		base_blocks[17] = "0123456789ABCDEF\0";
	char			result[19];
	unsigned long	tmp;
	int				i;

	i = 0;
	tmp = n;
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

void				ft_init_pointer(t_struct *blocks)
{
	void			*p_value;
	unsigned long	p_long;

	p_value = va_arg(blocks->args, void *);
	if (!(char *)p_value)
	{
		blocks->width -= 2;
		ft_print_null_pointer(blocks);
	}
	else
	{
		p_long = (unsigned long)p_value;
		ft_define_pointer(p_long, blocks, 16);
	}
}

void				ft_print_null_pointer(t_struct *blocks)
{
	static char		ident[3] = "0x\0";

	if (blocks->f_minus)
	{
		blocks->total_printed += write(1, ident, 2);
		if (blocks->f_prec)
		{
			ft_print_precision_digits(blocks);
			ft_print_width_digits(blocks);
		}
		else
		{
			blocks->width--;
			blocks->total_printed += write(1, &ident[0], 1);
			ft_print_width_digits(blocks);
		}
	}
	else
		ft_print_null_pointer_no_f_m(blocks);
}

void				ft_print_null_pointer_no_f_m(t_struct *blocks)
{
	static char		ident[3] = "0x\0";

	if (blocks->f_prec)
	{
		ft_print_width_digits(blocks);
		blocks->total_printed += write(1, ident, 2);
		if (blocks->precision < 0)
			blocks->total_printed += write(1, &ident[0], 1);
		ft_print_precision_digits(blocks);
	}
	else
	{
		if (blocks->f_zero)
		{
			blocks->total_printed += write(1, ident, 2);
			ft_print_width_digits(blocks);
		}
		else
		{
			blocks->width--;
			ft_print_width_digits(blocks);
			blocks->total_printed += write(1, ident, 2);
			blocks->total_printed += write(1, &ident[0], 1);
		}
	}
}
