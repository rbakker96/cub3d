/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 09:10:08 by rbakker        #+#    #+#                */
/*   Updated: 2020/02/06 10:38:38 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != 0)
			lst = lst->next;
		return (lst);
	}
	return (0);
}
