/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:29 by marvin            #+#    #+#             */
/*   Updated: 2021/03/10 20:51:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		check_args(int argc, char **argv)
{
	int i;
	int j;

	if (argc < 2)
		return 1;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] < '0' || '9' < argv[i][j])
				return 1;
	}
	return 0;
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	add_char(char **str, char c)
{
	char	*new;
	int		i;
	int		len;

	len = ft_strlen(*str);
	new = (char *)malloc(sizeof(char) * len + 1);
	i = -1;
	while (++i < len)
		new[i] = (*str)[i];
	new[i] = 0;
	if (len)
		free(*str);
	*str = new;
}

int		main(int argc, char **argv)
{
	char	c;
	int		r;
	char	*str;

	if (check_args(argc, argv))
		return 1;
	 while ((r = read(0, &c, 1)) && r != -1)
		add_char(&str, c);
	printf("%s\n", str);
	return 0;
}
