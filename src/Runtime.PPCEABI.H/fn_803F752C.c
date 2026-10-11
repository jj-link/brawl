typedef struct {
    unsigned char justification, sign, precision_specified, alternate_form;
    unsigned char argument_length, conversion;
    int width, precision;
} PrintFormat;
struct dec { signed char flag; unsigned char pad; short exp; unsigned char count, dig[36]; };
struct decform { unsigned char style, pad; short precision; };
typedef struct { char reserved[8]; const unsigned short* classes; } CTypeMap;
typedef struct { char reserved[0x38]; CTypeMap* ctype; } Locale;
extern Locale lbl_804942B8;
extern const char* lbl_80494108[14];
extern const char printf_strings_8041FAE8[43];
extern double lbl_805A4BB8;
extern char* strcpy(char*, const char*);
extern void fn_803F4710(const struct decform*, struct dec*, double);
extern void fn_803F7404(struct dec*, int);
static inline int IsUpper(int c) {
    return (c < 0 || c >= 256) ? 0 : lbl_804942B8.ctype->classes[c] & 0x200;
}
/* Produce a NUL-terminated decimal conversion backwards from buffer_end. */
char* float2str_803F752C(double value, char* buffer_end, PrintFormat spec) {
    PrintFormat* format = &spec;
    struct decform decimal_format;
    struct dec decimal;
    char* output;
    int point = *(const unsigned char*)lbl_80494108[0];
    int exponent;
    char* digits;
    if (format->precision > 509) return 0;
    decimal_format.style = 0;
    decimal_format.precision = 32;
    fn_803F4710(&decimal_format, &decimal, value);
    digits = (char*)decimal.dig + decimal.count;
    while (decimal.count > 1 && (int)(unsigned char)*--digits == '0') {
        --decimal.count;
        ++decimal.exp;
    }
    switch (decimal.dig[0]) {
    case '0': decimal.exp = 0; break;
    case 'I':
        if (value < lbl_805A4BB8) {
            output = buffer_end - 5;
            if (IsUpper(format->conversion)) strcpy(output, printf_strings_8041FAE8 + 6);
            else strcpy(output, printf_strings_8041FAE8 + 11);
        } else {
            output = buffer_end - 4;
            if (IsUpper(format->conversion)) strcpy(output, printf_strings_8041FAE8 + 16);
            else strcpy(output, printf_strings_8041FAE8 + 20);
        }
        return output;
    case 'N':
        if ((signed char)decimal.flag) {
            output = buffer_end - 5;
            if (IsUpper(format->conversion)) strcpy(output, printf_strings_8041FAE8 + 24);
            else strcpy(output, printf_strings_8041FAE8 + 29);
        } else {
            output = buffer_end - 4;
            if (IsUpper(format->conversion)) strcpy(output, printf_strings_8041FAE8 + 34);
            else strcpy(output, printf_strings_8041FAE8 + 38);
        }
        return output;
    }
    decimal.exp += decimal.count - 1;
    output = buffer_end - 1;
    *output = 0;
    switch (format->conversion) {
    case 'g': case 'G':
        if (decimal.count > format->precision) fn_803F7404(&decimal, format->precision);
        if (decimal.exp < -4 || decimal.exp >= format->precision) {
            if (format->alternate_form) --format->precision;
            else format->precision = decimal.count - 1;
            if (format->conversion == 'g') format->conversion = 'e';
            else format->conversion = 'E';
            goto scientific;
        }
        if (format->alternate_form) format->precision -= decimal.exp + 1;
        else {
            format->precision = decimal.count - (decimal.exp + 1);
            if (format->precision < 0) format->precision = 0;
        }
        goto fixed;
    case 'e': case 'E':
    scientific:
        {
        int count;
        char* digits;
        unsigned char sign;
        if (decimal.count > format->precision + 1) fn_803F7404(&decimal, format->precision + 1);
        exponent = decimal.exp;
        sign = '+';
        if (exponent < 0) { exponent = -exponent; sign = '-'; }
        count = 0;
        while (exponent != 0 || count < 2) {
            *--output = exponent % 10 + '0';
            exponent /= 10;
            ++count;
        }
        output[-1] = sign;
        output -= 2;
        *output = format->conversion;
        if (format->precision + (buffer_end - output) > 509) return 0;
        if (decimal.count < format->precision + 1) {
            count = format->precision + 2 - decimal.count;
            while (--count) *--output = '0';
        }
        count = decimal.count;
        digits = (char*)decimal.dig + count;
        while (--count) *--output = *--digits;
        if (format->precision || format->alternate_form) *--output = point;
        *--output = decimal.dig[0];
        if ((signed char)decimal.flag) *--output = '-';
        else if (format->sign == 1) *--output = '+';
        else if (format->sign == 2) *--output = ' ';
        break;
        }
    case 'f': case 'F':
    fixed:
        {
        int count, exponent, i;
        char* digits;
        int integral, fractional;
        count = decimal.count;
        exponent = decimal.exp;
        fractional = count - exponent - 1;
        if (fractional < 0) fractional = 0;
        if (fractional > format->precision) {
            fn_803F7404(&decimal, count - (fractional - format->precision));
            count = decimal.count;
            exponent = decimal.exp;
            fractional = count - exponent - 1;
            if (fractional < 0) fractional = 0;
        }
        integral = exponent + 1;
        if (integral < 0) integral = 0;
        if (integral + fractional > 509) return 0;
        digits = (char*)decimal.dig + decimal.count;
        for (i = 0; i < format->precision - fractional; ++i) *--output = '0';
        for (i = 0; i < fractional && i < decimal.count; ++i) *--output = *--digits;
        for (; i < fractional; ++i) *--output = '0';
        if (format->precision || format->alternate_form) *--output = point;
        if (integral) {
            for (i = 0; i < integral - decimal.count; ++i) *--output = '0';
            for (; i < integral; ++i) *--output = *--digits;
        } else *--output = '0';
        if ((signed char)decimal.flag) *--output = '-';
        else if (format->sign == 1) *--output = '+';
        else if (format->sign == 2) *--output = ' ';
        break;
        }
    }
    return output;
}
