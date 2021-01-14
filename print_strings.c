/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:36:03 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 17:39:36 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void			ft_order_to_print_string(char *s, t_struct *blocks)
{
	static char	nul[7] = "(null)\0";

	if (!s)
		s = nul;
	if (blocks->f_minus)
	{
		ft_print_precision_string(s, blocks);
		ft_print_width_string(s, blocks);
	}
	else
	{
		ft_print_width_string(s, blocks);
		ft_print_precision_string(s, blocks);
	}
}

void			ft_print_width_string(char *s, t_struct *blocks)
{
	char		w_ch;
	int			w_amount;

	w_ch = ' ';
	if (!blocks->f_prec || blocks->precision < 0)
		w_amount = blocks->width - ft_strlen(s);
	else if (blocks->f_prec && !blocks->precision)
		w_amount = blocks->width;
	else
		w_amount = blocks->width - ft_find_min(blocks->precision, ft_strlen(s));
	if (blocks->f_zero && !blocks->f_minus)
		w_ch = '0';
	while (w_amount > 0)
	{
		blocks->total_printed += write(1, &w_ch, 1);
		w_amount--;
	}
}

void			ft_print_precision_string(char *s, t_struct *blocks)
{
	int			p_amount;

	if (blocks->f_prec > 0 && blocks->precision > 0)
		p_amount = blocks->precision;
	else if (blocks->f_prec && !blocks->precision)
		p_amount = 0;
	else
		p_amount = ft_strlen(s);
	while (p_amount > 0 && *s)
	{
		blocks->total_printed += write(1, s++, 1);
		p_amount--;
	}
}
