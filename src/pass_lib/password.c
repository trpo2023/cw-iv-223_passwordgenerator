#include <pass_lib/password.h>

char random_upper_case()
{
    return (char)(rand() % 26 + 'A');
}

char random_lower_case()
{
    return (char)(rand() % 26 + 'a');
}

char random_digit()
{
    return (char)(rand() % 10 + '0');
}

char random_symbol()
{
    char symbols[] = "!@#$%^&*()_+-={}[]\\|;'\":/?.>,<`~";
    int index = rand() % sizeof(symbols);
    return symbols[index];
}

void generate_password(
        char* password,
        int length,
        int use_upper_case,
        int use_digits,
        int use_symbols)
{
    int i;
    for (i = 0; i < length; i++) {
        int type = rand() % 4;
        switch (type) {
        case 0:
            password[i] = random_lower_case();
            break;
        case 1:
            if (use_upper_case) {
                password[i] = random_upper_case();
            } else {
                i--;
            }
            break;
        case 2:
            if (use_digits) {
                password[i] = random_digit();
            } else {
                i--;
            }
            break;
        case 3:
            if (use_symbols) {
                password[i] = random_symbol();
            } else {
                i--;
            }
        }
    }
    password[length] = '\0';
}