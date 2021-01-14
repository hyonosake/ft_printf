/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:51:33 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 17:59:16 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

int				ft_isdigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int				ft_isformat(char format)
{
	static char	frm[10] = "dixXoscpu\0";
	int			i;

	i = 0;
	while (frm[i])
	{
		if (format == frm[i])
			return (1);
		i++;
	}
	return (0);
}

int				ft_strlen(char *s)
{
	int			len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

int				ft_find_min(int a, int b)
{
	return ((a) < (b) ? (a) : (b));
}

int				ft_find_abs(int a, int b)
{
	if (a < 0)
		return (0);
	return ((a) - (b) > 0 ? ((a) - (b)) : ((b) - (a)));
}
