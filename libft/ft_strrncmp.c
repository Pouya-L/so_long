/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:11:12 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/29 15:27:16 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);

	if (n == 0 || len1 < n || len2 < n)
		return (0);
	len1 = len1 - n;
	len2 = len2 - n;
	while (n > 0 && s1[len1] != '\0' && s2[len2] != '\0' && s1[len1] == s2[len2])
	{
		len1++;
		len2++;
		n--;
	}
	if (n == 0 || (s1[len1] == '\0' && s2[len2] == '\0'))
		return 0;
	else
		return (unsigned char)s1[len1] - (unsigned char)s2[len2];
}

