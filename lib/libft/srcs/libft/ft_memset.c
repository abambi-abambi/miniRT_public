/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:46:51 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 14:17:58 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*ptr;

	ch = (unsigned char)c;
	ptr = dest;
	while (len-- > 0)
	{
		*ptr = ch;
		ptr++;
	}
	return (dest);
}
