/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stass <stass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:54:31 by stass             #+#    #+#             */
/*   Updated: 2021/01/21 10:54:31 by stass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_comb2(void)
{
    char i = '0', j = '1', k = '2';
    int print_comma = 0;
    
    while (i <= '9')
    {
        while (j <= '9')
        {
            if (j > i)
            {
                while (k <= '9')
                {
                    if (k > j)
                    {
                        if (print_comma > 0)
                        {
                            write(1, ", ", 2);
                        }
                        write(1, &i, 1);
                        write(1, &j, 1);
                        write(1, &k, 1);
                        print_comma = 1;
                    }
                    k++;
                }
            }
            k = j;
            j++;
        }
        j = i;
        i++;
    }
}
