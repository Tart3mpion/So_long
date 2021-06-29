/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:28:12 by ldes-cou          #+#    #+#             */
/*   Updated: 2020/12/03 17:31:53 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *n, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (*n == '\0')
		return ((char *)s);
	while (s[i] && i < len)
	{
		x = 0;
		if (s[i] == n[x])
		{
			while ((i + x) < len && s[x + i] == n[x])
			{
				x++;
				if (!(n[x]))
					return ((char *)s + i);
			}
		}
		i++;
	}
	return (0);
}
