/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:22:29 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 14:18:25 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0')
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}