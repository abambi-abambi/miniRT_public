/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:28:10 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 15:36:10 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	ft_len_num(int n, long long int n_copy, int i)
{
	if (n == 0)
		i++;
	else if (n < 0)
	{
		n_copy *= -1;
		i++;
	}
	while (n_copy > 0)
	{
		n_copy /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	long long int	n_copy;
	char			*ptr;

	i = 0;
	n_copy = (long long int)n;
	i = ft_len_num(n, n_copy, i);
	if (n < 0)
		n_copy *= -1;
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[i--] = '\0';
	while (i >= 0)
	{
		ptr[i] = "0123456789"[n_copy % 10];
		n_copy /= 10;
		i--;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
