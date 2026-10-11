/* Private MSL printf format parser. The descriptor is shared by value with long2str. */
typedef struct {
    unsigned char justification, sign, precision_specified, alternate_form;
    unsigned char argument_length, conversion;
    int width, precision;
} PrintFormat;
typedef struct { char reserved[8]; const unsigned short* classes; } CTypeMap;
typedef struct { char reserved[0x38]; CTypeMap* ctype; } Locale;
extern Locale lbl_804942B8;
extern void* __va_arg(void*, int);
static inline int IsDigit(int c)
{
    return (c < 0 || c >= 256) ? 0 : lbl_804942B8.ctype->classes[c] & 8;
}
const char* parse_format_803F6578(const char* initial_format, void* args, PrintFormat* result)
{
    PrintFormat spec;
    int c;
    char next;
    int recognized;
    int length_present;
    const char* format = initial_format;
    c = *++format;
    spec.justification = 1;
    spec.sign = 0;
    spec.precision_specified = 0;
    spec.alternate_form = 0;
    spec.argument_length = 0;
    spec.width = 0;
    spec.precision = 0;
    if (c == '%') {
        spec.conversion = c;
        *result = spec;
        return format + 1;
    }
    for (;;) {
        recognized = 1;
        switch (c) {
        case '-': spec.justification = 0; break;
        case '+': spec.sign = 1; break;
        case ' ': if (spec.sign != 1) spec.sign = 2; break;
        case '#': spec.alternate_form = 1; break;
        case '0': if (spec.justification != 0) spec.justification = 2; break;
        default: recognized = 0; break;
        }
        if (!recognized) break;
        c = *++format;
    }
    if (c == '*') {
        spec.width = *(int*)__va_arg(args, 1);
        if (spec.width < 0) {
            spec.justification = 0;
            spec.width = -spec.width;
        }
        c = *++format;
    } else {
        while (IsDigit(c)) {
            spec.width = spec.width * 10 + c - '0';
            c = *++format;
        }
    }
    if (spec.width > 509) {
        spec.conversion = 255;
        *result = spec;
        return format + 1;
    }
    if (c == '.') {
        c = *++format;
        spec.precision_specified = 1;
        if (c == '*') {
            spec.precision = *(int*)__va_arg(args, 1);
            if (spec.precision < 0) spec.precision_specified = 0;
            c = *++format;
        } else {
            while (IsDigit(c)) {
                spec.precision = spec.precision * 10 + c - '0';
                c = *++format;
            }
        }
    }
    length_present = 1;
    switch (c) {
    case 'h':
        spec.argument_length = 2;
        if ((next = format[1]) == 'h') { spec.argument_length = 1; c = next; ++format; }
        break;
    case 'l':
        spec.argument_length = 3;
        if ((next = format[1]) == 'l') { spec.argument_length = 4; c = next; ++format; }
        break;
    case 'L': spec.argument_length = 9; break;
    case 'j': spec.argument_length = 6; break;
    case 't': spec.argument_length = 8; break;
    case 'z': spec.argument_length = 7; break;
    default: length_present = 0; break;
    }
    if (length_present) c = *++format;
    spec.conversion = c;
    switch (c) {
    case 'd': case 'i': case 'o': case 'u': case 'x': case 'X':
        if (spec.argument_length == 9) { spec.conversion = 255; break; }
        if (!spec.precision_specified) spec.precision = 1;
        else if (spec.justification == 2) spec.justification = 1;
        break;
    case 'f': case 'F':
        if (spec.argument_length == 2 || spec.argument_length == 6 ||
            spec.argument_length == 7 || spec.argument_length == 8 || spec.argument_length == 4) {
            spec.conversion = 255; break;
        }
        if (!spec.precision_specified) spec.precision = 6;
        break;
    case 'a': case 'A':
        if (!spec.precision_specified) spec.precision = 13;
        if (spec.argument_length == 2 || spec.argument_length == 6 ||
            spec.argument_length == 7 || spec.argument_length == 8 ||
            spec.argument_length == 4 || spec.argument_length == 1) spec.conversion = 255;
        break;
    case 'g': case 'G':
        if (spec.precision == 0) spec.precision = 1;
        /* General format shares exponential-format validation after its zero precision rule. */
    case 'e': case 'E':
        if (spec.argument_length == 2 || spec.argument_length == 6 ||
            spec.argument_length == 7 || spec.argument_length == 8 ||
            spec.argument_length == 4 || spec.argument_length == 1) {
            spec.conversion = 255; break;
        }
        if (!spec.precision_specified) spec.precision = 6;
        break;
    case 'p':
        spec.conversion = 'x'; spec.alternate_form = 1;
        spec.argument_length = 3; spec.precision = 8;
        break;
    case 'c':
        if (spec.argument_length == 3) spec.argument_length = 5;
        else if (spec.precision_specified || spec.argument_length != 0) spec.conversion = 255;
        break;
    case 's':
        if (spec.argument_length == 3) spec.argument_length = 5;
        else if (spec.argument_length != 0) spec.conversion = 255;
        break;
    case 'n': if (spec.argument_length == 9) spec.conversion = 255; break;
    default: spec.conversion = 255; break;
    }
    *result = spec;
    return format + 1;
}

char* long2str_803F6B74(unsigned long value, char* end, PrintFormat format)
{
    unsigned long radix;
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
        if ((long)value < 0) {
            if (value != 0x80000000UL) {
                value = -(long)value;
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
