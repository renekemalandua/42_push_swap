/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:01:09 by akemalan          #+#    #+#             */
/*   Updated: 2025/09/24 22:01:10 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_operation_count = 0;

void feedback_operations(int argc, int total_ops)
{
    int n = argc - 1; // subtrai o nome do programa

    printf("Total Stack: %d\nTotal operations: %d\n", n, total_ops);

    if (n == 100)
    {
        if (total_ops < 700)
            printf("✅ Excelente! Menos de 700 operações (100%%)\n");
        else if (total_ops <= 1100)
            printf("⚠️ Bom! Menos de 1100 operações (mínimo 80%%)\n");
        else if (total_ops <= 1300)
            printf("⚠️ Aceitável! Menos de 1300 operações (mínimo 80%%)\n");
        else
            printf("❌ Muitas operações, não atende ao requisito\n");
    }
    else if (n == 500)
    {
        if (total_ops <= 5500)
            printf("✅ Excelente! Até 5500 operações (100%%)\n");
        else if (total_ops <= 8500)
            printf("⚠️ Bom! Até 8500 operações (mínimo 80%%)\n");
        else if (total_ops <= 11500)
            printf("⚠️ Aceitável! Até 11500 operações (mínimo 80%%)\n");
        else
            printf("❌ Muitas operações, não atende ao requisito\n");
    }
    else
    {
        printf("⚠️ Stack de %d elementos, sem regras específicas de benchmark\n", n);
    }
}
