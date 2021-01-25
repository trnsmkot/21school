#include <stdio.h>
#include <unistd.h>
#include "ft_putchar.h"
#include "ft_print_alphabet.h"
#include "ft_print_reverse_alphabet.h"
#include "ft_print_numbers.h"
#include "ft_is_negative.h"
#include "ft_print_comb.h"
#include "ft_print_comb2.h"

int main(int argc, const char * argv[]) {
    // ex00
    write(1, "ex00: ", 6);
    ft_putchar('c');
    ft_putchar('\n');
    
    // ex01
    write(1, "ex01: ", 6);
    ft_print_alphabet();
    ft_putchar('\n');
    
    // ex02
    write(1, "ex02: ", 6);
    ft_print_reverse_alphabet();
    ft_putchar('\n');
    
    // ex03
    write(1, "ex03: ", 6);
    ft_print_numbers();
    ft_putchar('\n');
    
    // ex04
    write(1, "ex04: ", 6);
    ft_is_negative(10);
    ft_putchar('\n');
    
    // ex05
    write(1, "ex05: ", 6);
    ft_print_comb();
    ft_putchar('\n');
    
    // ex06
    write(1, "ex06: ", 6);
    ft_print_comb2();
    ft_putchar('\n');
    
    // ex07
    write(1, "ex07: ", 6);
//    ft_print_numbers();
    ft_putchar('\n');
    
    // ex08
    write(1, "ex08: ", 6);
//    ft_print_numbers();
    ft_putchar('\n');
    
    
    return 0;
}
