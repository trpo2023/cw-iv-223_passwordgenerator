#include <ctest.h>
#include <string.h>

#include <pass_lib/password.h>

CTEST(random_upper_case, returns_valid_uppercase_letter)
{
    // Act
    char letter = random_upper_case();

    // Assert
    ASSERT_TRUE(letter >= 'A' && letter <= 'Z');
}

CTEST(random_lower_case, returns_valid_lowercase_letter)
{
    // Act
    char letter = random_lower_case();

    // Assert
    ASSERT_TRUE(letter >= 'a' && letter <= 'z');
}

CTEST(random_digit, returns_valid_digit)
{
    // Act
    char digit = random_digit();

    // Assert
    ASSERT_TRUE(digit >= '0' && digit <= '9');
}

CTEST(random_symbol, returns_valid_symbol)
{
    // Act
    char symbol = random_symbol();

    // Assert
    const char symbols[] = "!@#$%^&*()_+-={}[]\\|;'\":/?.>,<`~";
    ASSERT_TRUE(strchr(symbols, symbol) != NULL);
}

CTEST(generate_password, length_zero)
{
    // Arrange
    int length = 0;
    int use_upper_case = 1;
    int use_digits = 1;
    int use_symbols = 1;

    char password[1];

    // Act
    generate_password(
            password, length, use_upper_case, use_digits, use_symbols);

    // Assert
    ASSERT_EQUAL('\0', password[0]);
}

CTEST(generate_password, length_positive)
{
    // Arrange
    size_t length = 8;
    int use_upper_case = 1;
    int use_digits = 1;
    int use_symbols = 1;

    char password[length + 1];

    // Act
    generate_password(
            password, length, use_upper_case, use_digits, use_symbols);

    // Assert
    ASSERT_TRUE(strlen(password) == length);
}

CTEST(generate_password, no_upper_case)
{
    // Arrange
    int length = 12;
    int use_upper_case = 0;
    int use_digits = 1;
    int use_symbols = 1;

    char password[length + 1];

    // Act
    generate_password(
            password, length, use_upper_case, use_digits, use_symbols);

    // Assert
    for (int i = 0; i < length; i++) {
        ASSERT_TRUE(
                islower(password[i]) || isdigit(password[i])
                || ispunct(password[i]));
    }
}
