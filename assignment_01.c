// assignment 1
// Number Systems

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decimalToBinary(int decimal)
{
    char *binary = (char *)malloc(sizeof(int) + 1);
    if (binary == NULL)
    {
        printf("Clear Memory!!!\n");
        return 0;
    }
    *binary = '\0';
    // printf("%d/n", &binary);
    if (decimal == 0)
    {
        binary--;
        *binary = '0';
    }
    while (decimal > 0)
    {
        binary--;
        *binary = decimal % 2 + '0';
        decimal = decimal / 2;
    }
    return binary;
}

int binaryToDecimal(char *binary, int length)
{
    int decimal = 0;
    int x = 1;
    // printf("%d\n",binary);
    binary = binary + length - 1;
    // printf("%d\n",binary);
    for (int i = 0; i < length; ++i, --binary)
    {
        if (*binary == '1')
        {
            decimal = decimal + x;
        }
        x = x * 2;
    }
    return decimal;
}

char *decimalToOctal(int decimal)
{
    char *octal = (char *)malloc(23);
    if (octal == NULL)
    {
        printf("Clear Memory!!!\n");
        return 0;
    }
    octal = octal + 22;
    *octal-- = '\0';
    if (decimal == 0)
    {
        *octal = '0';
    }
    else
    {
        char remainder;
        while (decimal > 0)
        {
            remainder = (decimal % 8) + '0';
            *octal-- = remainder;
            decimal = decimal / 8;
        }
        octal++;
    }
    return octal;
}

int octToDecimal(char *oct, int length)
{
    int decimal = 0;
    int x = 1;
    oct = oct + length - 1;
    for (int i = 0; i < length; i++, oct--)
    {
        int coefficient = *oct - '0';
        decimal = decimal + (x * coefficient);
        x = x * 8;
    }

    return decimal;
}

char remainderToHex(int remainder)
{
    if (remainder >= 0 && remainder <= 9)
        return remainder + '0';
    else
        return remainder - 10 + 'A'; // if(remainder >= 10 && remainder <= 15)
}

char *decimalToHex(int decimal)
{
    char *hex = (char *)malloc(17);
    if (hex == NULL)
    {
        printf("Clear Memory!!!\n");
        return 0;
    }
    hex = hex + 16;
    *hex = '\0';
    char remainder;
    while (decimal > 0)
    {
        hex--;
        remainder = remainderToHex(decimal % 16);
        *hex = remainder;
        decimal = decimal / 16;
    }
    return hex;
}

int valueOf(char digit)
{
    switch (digit)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
    case 'a':
        return 10;
    case 'B':
    case 'b':
        return 11;
    case 'C':
    case 'c':
        return 12;
    case 'D':
    case 'd':
        return 13;
    case 'E':
    case 'e':
        return 14;
    case 'F':
    case 'f':
        return 15;
    default:
        return 0;
    }
}

int hexToDecimal(char *hex, int length)
{
    int decimal = 0;
    int x = 1;
    hex += length - 1;
    for (int i = length - 1; i >= 0; i--, hex--)
    {
        decimal = decimal + (x * valueOf(*hex));
        x = x * 16;
    }
    return decimal;
}

int main()
{
    while (1)
    {
        printf("\nMENU:\n1. Decimal to Binary\n2. Binary to Decimal\n3. Decimal to Octal\n4. Octal to Decimal\n5. Decimal to HexaDecimal\n6. HexaDecimal to Decimal\n7. Exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int number;
            printf("Enter the Decimal Number you want to convert: ");
            scanf("%d", &number);
            char *binary = decimalToBinary(number);
            printf("%d in Decimal equals %s in Binary.\n", number, binary);
            // printf("%d, %d", sizeof(int), sizeof(long));
            break;
        }
        case 2:
        {
            char binary[33];
            int length, decimal;
            printf("Enter the Binary Number you want to convert: ");
            scanf("\n%32s", binary);
            length = strlen(binary);
            decimal = binaryToDecimal(binary, length);
            printf("%s in binary is %d in decimal\n", binary, decimal);
            break;
        }
        case 3:
        {
            int decimal;
            char *octal;
            printf("Enter the Decimal Number you want to convert: ");
            scanf("%d", &decimal);
            octal = decimalToOctal(decimal);
            printf("%d in Decimal equals %s in Octal\n", decimal, octal);
            break;
        }
        case 4:
        {
            char oct[23];
            int length;
            int decimal;
            printf("Enter the Octal Number you want to convert: ");
            scanf("\n%22s", oct);
            length = strlen(oct);
            decimal = octToDecimal(oct, length);
            printf("%s in Octal is %d in Decimal\n", oct, decimal);
            break;
        }
        case 5:
        {
            int decimal;
            char *hex;
            printf("Enter the Decimal Number you want to convert: ");
            scanf("%d", &decimal);
            hex = decimalToHex(decimal);
            printf("%lu in Decimal equals %s in HexaDecimal\n", decimal, hex);
            break;
        }
        case 6:
        {
            char hex[17];
            int length;
            int decimal;
            printf("Enter the HexaDecimal Number you want to convert: ");
            scanf("\n%16s", hex);
            length = strlen(hex);
            decimal = hexToDecimal(hex, length);
            printf("%s in HexaDecimal is %d in Decimal\n", hex, decimal);
            break;
        }
        case 7:
        {
            return 0;
            break;
        }
        default:
        {
            printf("Wrong Input!!!\n");
            break;
        }
        }
    }
    return 0;
}