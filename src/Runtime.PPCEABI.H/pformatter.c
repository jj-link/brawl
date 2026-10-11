/* Preserve the jump table's four-byte alignment within the original printf data. */
#pragma section data_type ".data$pformatter" ".bss"

typedef unsigned long u32;
typedef unsigned long size_t;
typedef struct {
    unsigned char justification, sign, precision_specified, alternate_form;
    unsigned char argument_length, conversion;
    int width, precision;
} PrintFormat;
typedef void* (*WriteProc)(void*, const char*, size_t);

extern void* __va_arg(void*, int);
extern const char* parse_format_803F6578(const char*, void*, PrintFormat*);
extern char* long2str_803F6B74(unsigned long, char*, PrintFormat);
extern char* longlong2str_803F6D9C(unsigned long long, char*, PrintFormat);
extern char* float2str_803F752C(double, char*, PrintFormat);
extern char* double2hex_803F703C(double, char*, PrintFormat);
extern char* strchr(const char*, int);
extern size_t strlen(const char*);
extern void* memchr(const void*, int, size_t);
extern size_t wcstombs(char*, const unsigned short*, size_t);
struct FormattingStrings {
    char numeric_tokens[42];
    char empty[1];
};
extern const struct FormattingStrings printf_strings_8041FAE8;
extern const unsigned short printf_empty_wide_8059FF50[1];

/* Format through the caller's writer, retaining the private MSL descriptor ABI. */
int __pformatter_803F7CFC(WriteProc write, void* destination,
                         const char* initial_format, void* args) {
    char buffer[512];
    PrintFormat spec;
    char padding = ' ';
    int length;
    char* text;
    int count = 0;
    int width;
    const char* conversion_start;
    const char* format = initial_format;
    long value;
    unsigned long long wide_value;
    double floating;
    void* result;

    while (*format) {
        conversion_start = strchr(format, '%');
        if (!conversion_start) {
            length = strlen(format);
            count += length;
            if (length && !write(destination, format, length)) return -1;
            break;
        }
        length = conversion_start - format;
        count += length;
        if (length && !write(destination, format, length)) return -1;
        format = parse_format_803F6578(conversion_start, args, &spec);
        switch (spec.conversion) {
        case 'd':
        case 'i':
            if (spec.argument_length == 3) value = *(long*)__va_arg(args, 1);
            else if (spec.argument_length == 4) wide_value = *(long long*)__va_arg(args, 2);
            else if (spec.argument_length == 6) wide_value = *(long long*)__va_arg(args, 2);
            else if (spec.argument_length == 7) value = *(long*)__va_arg(args, 1);
            else if (spec.argument_length == 8) value = *(long*)__va_arg(args, 1);
            else value = *(int*)__va_arg(args, 1);
            if (spec.argument_length == 2) value = (short)value;
            if (spec.argument_length == 1) value = (signed char)value;
            if (spec.argument_length == 4 || spec.argument_length == 6) {
                text = longlong2str_803F6D9C(wide_value, buffer + sizeof(buffer), spec);
                if (text) goto signed_length;
                goto bad_conversion;
            } else {
                text = long2str_803F6B74(value, buffer + sizeof(buffer), spec);
                if (!text) goto bad_conversion;
            }
signed_length:
            length = buffer + sizeof(buffer) - 1 - text;
            break;
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (spec.argument_length == 3) value = *(unsigned long*)__va_arg(args, 1);
            else if (spec.argument_length == 4) wide_value = *(unsigned long long*)__va_arg(args, 2);
            else if (spec.argument_length == 6) wide_value = *(unsigned long long*)__va_arg(args, 2);
            else if (spec.argument_length == 7) value = *(unsigned long*)__va_arg(args, 1);
            else if (spec.argument_length == 8) value = *(unsigned long*)__va_arg(args, 1);
            else value = *(unsigned int*)__va_arg(args, 1);
            if (spec.argument_length == 2) value = (unsigned short)value;
            if (spec.argument_length == 1) value = (unsigned char)value;
            if (spec.argument_length == 4 || spec.argument_length == 6) {
                text = longlong2str_803F6D9C(wide_value, buffer + sizeof(buffer), spec);
                if (text) goto unsigned_length;
                goto bad_conversion;
            } else {
                text = long2str_803F6B74(value, buffer + sizeof(buffer), spec);
                if (!text) goto bad_conversion;
            }
unsigned_length:
            length = buffer + sizeof(buffer) - 1 - text;
            break;
        case 'f': case 'F': case 'e': case 'E': case 'g': case 'G':
            if (spec.argument_length == 9) floating = *(long double*)__va_arg(args, 3);
            else floating = *(double*)__va_arg(args, 3);
            text = float2str_803F752C(floating, buffer + sizeof(buffer), spec);
            if (!text) goto bad_conversion;
            length = buffer + sizeof(buffer) - 1 - text;
            break;
        case 'a': case 'A':
            if (spec.argument_length == 9) floating = *(long double*)__va_arg(args, 3);
            else floating = *(double*)__va_arg(args, 3);
            text = double2hex_803F703C(floating, buffer + sizeof(buffer), spec);
            if (!text) goto bad_conversion;
            length = buffer + sizeof(buffer) - 1 - text;
            break;
        case 's':
            if (spec.argument_length == 5) {
                const unsigned short* wide = *(const unsigned short**)__va_arg(args, 1);
                if (!wide) wide = printf_empty_wide_8059FF50;
                if ((int)wcstombs(buffer, wide, sizeof(buffer)) < 0) goto bad_conversion;
                text = buffer;
            } else {
                text = *(char**)__va_arg(args, 1);
            }
            if (!text) text = (char*)printf_strings_8041FAE8.empty;
            if (spec.alternate_form) {
                length = (unsigned char)*text++;
                if (spec.precision_specified && length > spec.precision) length = spec.precision;
            } else if (spec.precision_specified) {
                length = spec.precision;
                result = memchr(text, 0, length);
                if (result) length = (char*)result - text;
            } else {
                length = strlen(text);
            }
            break;
        case 'n':
            result = *(void**)__va_arg(args, 1);
            switch (spec.argument_length) {
            case 0: *(int*)result = count; break;
            case 2: *(short*)result = count; break;
            case 3: *(long*)result = count; break;
            case 6: *(long long*)result = count; break;
            case 7: *(long*)result = count; break;
            case 8: *(long*)result = count; break;
            case 4: *(long long*)result = count; break;
            }
            continue;
        case 'c':
            text = buffer;
            *text = *(int*)__va_arg(args, 1);
            length = 1;
            break;
        case '%':
            *buffer = '%';
            text = buffer;
            length = 1;
            break;
        case 255:
        default:
        bad_conversion:
            length = strlen(conversion_start);
            count += length;
            if (length && !write(destination, conversion_start, length)) return -1;
            return count;
        }
        width = length;
        if (spec.justification) {
            padding = spec.justification == 2 ? '0' : ' ';
            if ((*text == '+' || *text == '-' || *text == ' ') && padding == '0') {
                if (!write(destination, text, 1)) return -1;
                ++text;
                --length;
            }
            while (width < spec.width) {
                if (!write(destination, &padding, 1)) return -1;
                ++width;
            }
        }
        if (length && !write(destination, text, length)) return -1;
        if (!spec.justification) {
            while (width < spec.width) {
                char space = ' ';
                if (!write(destination, &space, 1)) return -1;
                ++width;
            }
        }
        count += width;
    }
    return count;
}
