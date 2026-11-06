#pragma force_active on
extern double __fabs(double);

static inline double absolute_value(double x)
{
    return __fabs(x);
}

typedef struct {
    unsigned char justification, sign, precision_specified, alternate_form;
    unsigned char argument_length, conversion;
    int width, precision;
} PrintFormat;

struct dec {
    signed char flag;
    unsigned char pad;
    short exp;
    unsigned char count, dig[36];
};

struct decform {
    unsigned char style, pad;
    short precision;
};

extern const char* lbl_80494108[14];
extern const char printf_strings_8041FAE8[43];
extern double lbl_805A4BB8;
extern char* strcpy(char*, const char*);
extern void fn_803F4710(const struct decform*, struct dec*, double);
extern char* long2str_803F6B74(unsigned long, char*, PrintFormat);

static inline unsigned char hex_digit(unsigned char* bytes, int bit,
                                      PrintFormat* format)
{
    unsigned char nibble;

    if (bit < 64) {
        unsigned char* p = bytes + (bit >> 3);
        int shift = 7 - (bit & 7);
        nibble = *p >> shift;
        if ((bit & ~7) != ((bit - 4) & ~7))
            nibble |= (p[-1] << 8) >> shift;

        nibble &= 15;
        if (nibble < 10U)
            nibble += '0';
        else if (format->conversion == 'a')
            nibble += 'a' - 10;
        else
            nibble += 'A' - 10;
    } else {
        nibble = '0';
    }
    return nibble;
}

char* double2hex_803F703C(double value, char* buffer_end, PrintFormat spec)
{
    struct decform decimal_format;
    struct dec decimal;
    PrintFormat exponent_format;
    PrintFormat* format = &spec;
    char* output;
    unsigned char point = *(const unsigned char*)lbl_80494108[0];
    unsigned char* bytes;
    int i, bit;

    if (format->precision > 509)
        return 0;

    decimal_format.style = 0;
    decimal_format.precision = 32;
    fn_803F4710(&decimal_format, &decimal, value);

    if (lbl_805A4BB8 == absolute_value(value)) {
        output = buffer_end - 6;
        strcpy(output, printf_strings_8041FAE8);
        return output;
    }

    if (decimal.dig[0] == 'I') {
        if (decimal.flag) {
            output = buffer_end - 5;
            if (format->conversion == 'A')
                strcpy(output, printf_strings_8041FAE8 + 6);
            else
                strcpy(output, printf_strings_8041FAE8 + 11);
        } else {
            output = buffer_end - 4;
            if (format->conversion == 'A')
                strcpy(output, printf_strings_8041FAE8 + 16);
            else
                strcpy(output, printf_strings_8041FAE8 + 20);
        }
        return output;
    }

    if (decimal.dig[0] == 'N') {
        if (decimal.flag) {
            output = buffer_end - 5;
            if (format->conversion == 'A')
                strcpy(output, printf_strings_8041FAE8 + 24);
            else
                strcpy(output, printf_strings_8041FAE8 + 29);
        } else {
            output = buffer_end - 4;
            if (format->conversion == 'A')
                strcpy(output, printf_strings_8041FAE8 + 34);
            else
                strcpy(output, printf_strings_8041FAE8 + 38);
        }
        return output;
    }

    exponent_format.justification = 1;
    exponent_format.sign = 1;
    exponent_format.precision_specified = 0;
    exponent_format.alternate_form = 0;
    exponent_format.argument_length = 0;
    exponent_format.conversion = 'd';
    exponent_format.width = 0;
    exponent_format.precision = 1;

    output = long2str_803F6B74(
        ((((unsigned int)((unsigned char*)&value)[0] << 25 & 0xfe000000U) |
          (unsigned int)((unsigned char*)&value)[1] << 17) >> 21) - 1023,
        buffer_end, exponent_format);

    if (format->conversion == 'a')
        *--output = 'p';
    else
        *--output = 'P';

    bytes = (unsigned char*)&value;
    bit = format->precision * 4 + 11;
    for (i = format->precision; i >= 1; --i) {
        *--output = hex_digit(bytes, bit, format);
        bit -= 4;
    }

    if (format->precision || format->alternate_form)
        *--output = point;

    *--output = '1';

    if (format->conversion == 'a')
        *--output = 'x';
    else
        *--output = 'X';

    *--output = '0';

    if (decimal.flag)
        *--output = '-';
    else if (format->sign == 1)
        *--output = '+';
    else if (format->sign == 2)
        *--output = ' ';

    return output;
}
