#include <pass_lib/password.h>

int main()
{
    srand(time(NULL));

    int length;
    int use_uppercase;
    int use_numbers;
    int use_special;

    printf("Password length (default 12): ");
    scanf("%d", &length);
    getchar();

    printf("Use uppercase letters (1/0): ");
    scanf("%d", &use_uppercase);
    getchar();

    printf("Use numbers (1/0): ");
    scanf("%d", &use_numbers);
    getchar();

    printf("Use special characters (1/0): ");
    scanf("%d", &use_special);
    getchar();

    char password[length + 1];
    generate_password(
            password, length, use_uppercase, use_numbers, use_special);

    printf("Your password is: %s\n", password);

    return 0;
}
