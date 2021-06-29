/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:06:17 by ldes-cou          #+#    #+#             */
/*   Updated: 2020/12/03 10:09:51 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_cpy;
	char	*src_cpy;

	i = 0;
	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	if ((dst_cpy == 0) && (src_cpy == 0))
		return (NULL);
	while (n--)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
