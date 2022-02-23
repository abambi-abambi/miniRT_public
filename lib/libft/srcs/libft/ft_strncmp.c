/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:27:13 by abambi            #+#    #+#             */
/*   Updated: 2021/04/07 15:18:25 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (num == 0)
		return (0);
	ptr1 = (unsigned char *)string1;
	ptr2 = (unsigned char *)string2;
	while ((*ptr1 != '\0' || *ptr2 != '\0') && num--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
