/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0k <mo0k@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:35:54 by jmoucade          #+#    #+#             */
/*   Updated: 2018/05/27 00:32:52 by mo0k             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
size_t	ft_strlen(char *str);
char	*ft_strcat(char *dest, const char *src)
{
	int len;
	int i;

	i = -1;
	len = ft_strlen(dest);
	while (*(src + ++i))
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}
