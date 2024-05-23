/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** my getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    long num = 0;
    int neg = 1;

    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            neg = neg *  -1;
    for (; str[i] > 47 && str[i] < 58 && str[i] != '\0'; i++) {
        if (str[i] > 47 && str[i] < 58) {
            num = num * 10;
            num = num + str[i] - 48;
        }
        if (neg == -1 && num > 2147483648)
            return (0);
        else if (neg == 1 && num > 2147483647)
            return (0);
    }
    return ((int)num * neg);
}
