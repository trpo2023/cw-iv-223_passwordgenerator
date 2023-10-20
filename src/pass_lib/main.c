#include <password.h>

int main()
{
    srand(time(NULL));

    int dlina;
    int registor;
    int tsifru;
    int simvoli;

    printf("Password length (default 12): ");
    scanf("%d", &dlina);
    getchar();

    printf("Use uppercase letters (1/0): ");
    scanf("%d", &registor);
    getchar();

    

    return 0;
}
