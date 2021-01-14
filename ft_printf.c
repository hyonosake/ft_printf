/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:50:24 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 16:50:26 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void	ft_struct_init(t_struct *blocks)
{
	blocks->format = 0;
	blocks->f_minus = 0;
	blocks->f_zero = 0;
	blocks->neg_number = 0;
	blocks->width = 0;
	blocks->precision = 0;
	blocks->chars_to_print = 0;
	blocks->f_prec = 0;
	blocks->f_width = 0;
}

int		ft_printf(const char *format, ...)
{
	t_struct blocks;

	if (!format)
		return (0);
	ft_struct_init(&blocks);
	va_start(blocks.args, format);
	blocks.total_printed = 0;
	blocks.skipped_chars = 0;
	while (format[blocks.skipped_chars] != '\0')
	{
		if (format[blocks.skipped_chars] == '%')
		{
			ft_parse_flags(&format[++blocks.skipped_chars], &blocks);
			ft_struct_init(&blocks);
			continue ;
		}
		else if (format[blocks.skipped_chars] != '\0')
			blocks.total_printed +=
				write(1, &format[blocks.skipped_chars++], 1);
		else
			break ;
	}
	blocks.skipped_chars = 0;
	va_end(blocks.args);
	return (blocks.total_printed);
}
