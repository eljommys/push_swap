/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:14:26 by marvin            #+#    #+#             */
/*   Updated: 2021/03/12 17:14:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../minilibft.h"
# include <unistd.h>
# include <stdio.h>

void	ft_end(char **commands, int ret);
int		check_args(int argc, char **argv);
void	add_char(char **str, char c);
char	**add_str(char **commands, char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	swap(char to, int *a, int *b, int *a_b);
void	push(char to, int *a, int *b, int *a_b);
void	rotate(char to, int *a, int *b, int *a_b);
void	r_rotate(char to, int *a, int *b, int *a_b);

#endif
