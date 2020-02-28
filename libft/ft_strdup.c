/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:03:15 by rbakker        #+#    #+#                */
/*   Updated: 2019/11/15 10:11:04 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*ptr;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (0);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
