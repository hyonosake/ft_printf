/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_neg_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:48:53 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 17:55:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void		ft_print_neg_int_no_f_minus(int n, t_struct *blocks, int base)
{
	char	ch;

	ch = '-';
	if (blocks->f_prec && blocks->precision >= 0)
	{
		ft_print_width_digits(blocks);
		blocks->total_printed += write(1, &ch, 1);
		ft_print_precision_digits(blocks);
		ft_putnbr_base(n, blocks, base);
	}
	else
	{
		if (blocks->f_zero)
		{
			blocks->total_printed += write(1, &ch, 1);
			ft_print_positive_int(-n, blocks, base);
		}
		else
		{
			ft_print_width_digits(blocks);
			blocks->total_printed += write(1, &ch, 1);
			ft_putnbr_base(n, blocks, base);
		}
	}
}

void		ft_print_negative_int(int n, t_struct *blocks, int base)
{
	char	ch;

	ch = '-';
	if (blocks->f_minus)
	{
		blocks->total_printed += write(1, &ch, 1);
		ft_print_positive_int(n, blocks, base);
	}
	else
		ft_print_neg_int_no_f_minus(n, blocks, base);
}
