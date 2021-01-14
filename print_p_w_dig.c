/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_w_dig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:52:37 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 17:53:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void		ft_print_width_digits(t_struct *blocks)
{
	char	width_ch;
	int		amount;

	amount = blocks->width -
	ft_find_max(blocks->chars_to_print, blocks->precision) - blocks->neg_number;
	if (blocks->f_minus)
		width_ch = ' ';
	else if (blocks->f_zero && (!blocks->f_prec || blocks->precision < 0))
		width_ch = '0';
	else
		width_ch = ' ';
	while (amount > 0)
	{
		blocks->total_printed += write(1, &width_ch, 1);
		amount--;
	}
}

void		ft_print_precision_digits(t_struct *blocks)
{
	char	prec_ch;
	int		amount;

	amount = blocks->precision - blocks->chars_to_print;
	prec_ch = '0';
	while (amount > 0 && amount)
	{
		blocks->total_printed += write(1, &prec_ch, 1);
		amount--;
	}
}
