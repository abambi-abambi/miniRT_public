/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:53:24 by abambi            #+#    #+#             */
/*   Updated: 2021/04/08 13:36:36 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	while (*string)
	{
		if (*string == (unsigned char)symbol)
			return ((char *)string);
		string++;
	}
	if (*string == (unsigned char)symbol)
		return ((char *)string);
	return (NULL);
}
