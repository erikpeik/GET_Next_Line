/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:59:40 by emende            #+#    #+#             */
/*   Updated: 2021/12/09 19:23:02 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	z;
	size_t	len;

	z = 0;
	i = ft_strlen(s1);
	len = ft_strlen(s2);
	while (z < len)
	{
		s1[i] = s2[z];
		z++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
