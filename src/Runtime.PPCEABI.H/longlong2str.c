// MSL integer conversion: the caller passes a private format descriptor by value.
typedef struct {
    unsigned char justification;
    unsigned char sign;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char argument_length;
    unsigned char conversion;
    int width;
    int precision;
} PrintFormat;

char* longlong2str_803F6D9C(unsigned long long number, char* end, PrintFormat format)
{
    unsigned long long value = number;
    unsigned long long radix;
    char* p = end;
    int digits;
    int negative = 0;
    int digit;

    *--p = 0;
    digits = 0;
    if (value == 0 && format.precision == 0 &&
        !(format.alternate_form && format.conversion == 'o')) {
        return p;
    }

    switch (format.conversion) {
    case 'd':
    case 'i':
        radix = 10;
        if ((long long)value < 0) {
            if (value != 0x8000000000000000ULL) {
                value = -(long long)value;
            }
            negative = 1;
        }
        break;
    case 'o':
        radix = 8;
        format.sign = 0;
        break;
    case 'u':
        radix = 10;
        format.sign = 0;
        break;
    case 'x':
    case 'X':
        radix = 16;
        format.sign = 0;
        break;
    }

    do {
        digit = value % radix;
        value = value / radix;
        if (digit < 10) {
            digit += '0';
        } else {
            digit = format.conversion == 'x' ? digit + 'a' - 10 : digit + 'A' - 10;
        }
        *--p = digit;
        ++digits;
    } while (value != 0);

    if (radix == 8 && format.alternate_form && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format.justification == 2) {
        format.precision = format.width;
        if (negative || format.sign) {
            --format.precision;
        }
        if (radix == 16 && format.alternate_form) {
            format.precision -= 2;
        }
    }

    if (format.precision + (end - p) > 509) {
        return 0;
    }
    while (digits < format.precision) {
        *--p = '0';
        ++digits;
    }

    if (radix == 16 && format.alternate_form) {
        *--p = format.conversion;
        *--p = '0';
    }
    if (negative) {
        *--p = '-';
    } else if (format.sign == 1) {
        *--p = '+';
    } else if (format.sign == 2) {
        *--p = ' ';
    }
    return p;
}
