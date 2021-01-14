/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:54:13 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 17:54:53 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void		ft_order_to_print_char(int pos, t_struct *blocks)
{
	char	w_ch;
	char	printed;

	printed = pos;
	w_ch = ' ';
	if (blocks->f_zero && !blocks->f_minus)
		w_ch = '0';
	if (blocks->f_minus)
	{
		blocks->total_printed += write(1, &printed, 1);
		while (blocks->width-- > 1)
			blocks->total_printed += write(1, &w_ch, 1);
	}
	else
	{
		while (blocks->width-- > 1)
			blocks->total_printed += write(1, &w_ch, 1);
		blocks->total_printed += write(1, &printed, 1);
	}
}
