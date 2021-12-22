/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:21:03 by emende            #+#    #+#             */
/*   Updated: 2021/12/14 18:44:54 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	needlelen;

	needlelen = (int ) ft_strlen(needle);
	if (needlelen == 0)
		return ((char *)haystack);
	i = 0;
	while (len != 0 && haystack[i] && (i <= (((int ) len) - needlelen)))
	{
		if (ft_strncmp(haystack + i, needle, needlelen) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
