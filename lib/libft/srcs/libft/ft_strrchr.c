/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:11:04 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 14:19:04 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	while (i >= 0)
	{
		if ((char)string[i] == (unsigned char)symbol)
			return ((char *)&string[i]);
		i--;
	}
	return (NULL);
}
