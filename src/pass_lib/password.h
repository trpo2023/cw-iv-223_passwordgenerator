#pragma once
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char random_upper_case();
char random_lower_case();
char random_digit();
char random_symbol();
void generate_password(
        char* password,
        int length,
        int use_upper_case,
        int use_digits,
        int use_symbols);