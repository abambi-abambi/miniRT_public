/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:20:26 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 14:17:01 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem1;

	elem1 = (t_list *)malloc(sizeof(t_list));
	if (!elem1)
		return (NULL);
	elem1->content = content;
	elem1->next = NULL;
	return (elem1);
}
