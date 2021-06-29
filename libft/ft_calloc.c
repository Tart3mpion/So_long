/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:56:49 by ldes-cou          #+#    #+#             */
/*   Updated: 2020/12/03 10:18:20 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;
	int		len;

	i = 0;
	len = (size * count);
	str = malloc(len);
	if (!str)
		return (NULL);
	while (len--)
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}
