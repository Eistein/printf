#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * write_char - Prints a character
 * @c: character to print
 * @buff: buffer to handle print
 * @flag:  calculates active flags
 * @wid: get width
 * @pre: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed
 */
int write_char(char c, char buff[], int flag, int wid, int pre, int s)
{ /* character is stored at left and padding at buffer's right */
    int i = 0;
    char padd = ' ';

    UNUSED(pre);
    UNUSED(s);

    if (flag & F_ZERO)
        padd = '0';

    buff[i++] = c;
    buff[i] = '\0';

    if (wid > 1)
    {
        buff[BUFF_SIZE - 1] = '\0';
        for (i = 0; i < wid - 1; i++)
            buff[BUFF_SIZE - i - 2] = padd;

        if (flag & F_MINUS)
            return (write(1, &buff[0], 1) +
                    write(1, &buff[BUFF_SIZE - i - 1], wid - 1));
        else
            return (write(1, &buff[BUFF_SIZE - i - 1], wid - 1) +
                    write(1, &buff[0], 1));
    }

    return (write(1, &buff[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a number
 * @is_neg: whether the number is negative
 * @ind: character index
 * @buff: buffer to handle print
 * @flag:  calculates active flags
 * @wid: get width
 * @pre: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed
 */
int write_number(int is_neg, int ind, char buff[], int flag, int wid, int pre, int s)
{
    int len = BUFF_SIZE - ind - 1;
    char padd = ' ', extra_char = 0;

    UNUSED(s);

    if ((flag & F_ZERO) && !(flag & F_MINUS))
        padd = '0';

    if (is_neg)
        extra_char = '-';
    else if (flag & F_PLUS)
        extra_char = '+';
    else if (flag & F_SPACE)
        extra_char = ' ';

    return (write_num(ind, buff, flag, wid, pre, len, padd, extra_char));
}
