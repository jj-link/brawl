/* Format-driven input conversion, including the runtime's bounded-input mode. */
typedef unsigned long u32;
typedef unsigned long long u64;
typedef long long s64;
typedef int (*ReadProc)(void*, int, int);

typedef struct ScanFormat {
    unsigned char suppress;
    unsigned char width_specified;
    unsigned char length;
    unsigned char conversion;
    int width;
    unsigned char scanset[32];
} ScanFormat;

typedef struct CTypeMap {
    char reserved[8];
    const unsigned short* classes;
} CTypeMap;

typedef struct Locale {
    char reserved[0x38];
    CTypeMap* ctype;
} Locale;

extern Locale lbl_804942B8;
extern const float lbl_8059FF68[];
extern const char* fn_803F8C64(const char*, ScanFormat*);
extern void* __va_arg(void*, int);
extern u32 fn_803FBC7C(int, int, ReadProc, void*, int*, int*, int*);
extern u64 fn_803FC0AC(int, int, ReadProc, void*, int*, int*, int*);
extern double fn_803FA804(int, ReadProc, void*, int*, int*);
extern int fn_803F5EF4(void*, const char*, u32);

static inline int IsSpace(int c) {
    return (c < 0 || c >= 256) ? 0 : lbl_804942B8.ctype->classes[c] & 0x100;
}

int fn_803F9318(ReadProc read, void* context, const char* initial_format, void* args, int bounded) {
    char c;
    int consumed;
    int negative;
    int overflow;
    ScanFormat spec;
    s64 signed_wide = 0;
    u64 unsigned_wide;
    char* character_start;
    char* string_start;
    char* destination;
    int characters;
    int assignments;
    int conversions;
    int input;
    const char* format;
    long signed_value;
    u32 unsigned_value;
    char format_char;
    char format_space;
    u32 capacity;
    int room;
    int base;
    int failed = 0;
    characters = 0;
    assignments = 0;
    conversions = 0;
    format = initial_format;

    while ((format_char = *format) != 0) {
        if (IsSpace(format_char)) {
            while (IsSpace(format_space = *++format)) {}
            if (failed) {
                continue;
            }
            while (IsSpace(c = read(context, 0, 0))) {
                characters++;
            }
            read(context, c, 1);
            continue;
        }
        if (format_char != '%' && !failed) {
            if ((unsigned char)format_char != (c = read(context, 0, 0))) {
                read(context, c, 1);
                if (!bounded) {
                    goto done;
                }
                failed = 1;
                format++;
                continue;
            }
            characters++;
            format++;
            continue;
        }
        format = fn_803F8C64(format, &spec);
        if (!spec.suppress && spec.conversion != '%') {
            destination = *(char**)__va_arg(args, 1);
        } else {
            destination = 0;
        }
        if (spec.conversion != 'n' && !failed && read(context, 0, 2)) {
            if (!bounded) {
                goto done;
            }
            failed = 1;
        }
        switch (spec.conversion) {
        case 'd':
            base = 10;
            goto signed_conversion;
        case 'i': {
            base = 0;
signed_conversion:
            if (failed) {
                signed_wide = 0;
                signed_value = 0;
            } else {
                if (spec.length == 7 || spec.length == 4) {
                    unsigned_wide = fn_803FC0AC(base, spec.width, read, context, &consumed, &negative, &overflow);
                } else {
                    unsigned_value = fn_803FBC7C(base, spec.width, read, context, &consumed, &negative, &overflow);
                }
                if (consumed == 0) {
                    if (!bounded) {
                        goto done;
                    }
                    failed = 1;
                    signed_wide = 0;
                    signed_value = 0;
                } else {
                    characters += consumed;
                    if (spec.length == 7 || spec.length == 4) {
                        if (negative) {
                            signed_wide = -unsigned_wide;
                        } else {
                            signed_wide = unsigned_wide;
                        }
                    } else {
                        signed_value = unsigned_value;
                        if (negative) {
                            signed_value = -unsigned_value;
                        }
                    }
                }
            }
            if (destination) {
                switch (spec.length) {
                case 0: *(int*)destination = signed_value; break;
                case 1: *(signed char*)destination = signed_value; break;
                case 2: *(short*)destination = signed_value; break;
                case 3: *(long*)destination = signed_value; break;
                case 4: *(s64*)destination = signed_wide; break;
                case 5: *(long*)destination = signed_value; break;
                case 6: *(long*)destination = signed_value; break;
                case 7: *(s64*)destination = signed_wide; break;
                }
                if (!failed) {
                    assignments++;
                }
            }
            conversions++;
            break;
        }
        case 'o':
            base = 8;
            goto unsigned_conversion;
        case 'u':
            base = 10;
            goto unsigned_conversion;
        case 'x':
        case 'X': {
            base = 16;
unsigned_conversion:
            if (failed) {
                unsigned_wide = 0;
                unsigned_value = 0;
            } else {
                if (spec.length == 7 || spec.length == 4) {
                    unsigned_wide = fn_803FC0AC(base, spec.width, read, context, &consumed, &negative, &overflow);
                } else {
                    unsigned_value = fn_803FBC7C(base, spec.width, read, context, &consumed, &negative, &overflow);
                }
                if (consumed == 0) {
                    if (!bounded) {
                        goto done;
                    }
                    failed = 1;
                    unsigned_wide = 0;
                    unsigned_value = 0;
                } else {
                    characters += consumed;
                    if (negative) {
                        if (spec.length == 7) {
                            unsigned_wide = -unsigned_wide;
                        }
                        if (spec.length != 7) {
                            unsigned_value = -unsigned_value;
                        }
                    }
                }
            }
            if (destination) {
                switch (spec.length) {
                case 0: *(unsigned int*)destination = unsigned_value; break;
                case 1: *(unsigned char*)destination = unsigned_value; break;
                case 2: *(unsigned short*)destination = unsigned_value; break;
                case 3: *(u32*)destination = unsigned_value; break;
                case 4: *(u64*)destination = unsigned_wide; break;
                case 5: *(u32*)destination = unsigned_value; break;
                case 6: *(u32*)destination = unsigned_value; break;
                case 7: *(u64*)destination = unsigned_wide; break;
                }
                if (!failed) {
                    assignments++;
                }
            }
            conversions++;
            break;
        }
        case 'a': case 'A': case 'e': case 'E':
        case 'f': case 'F': case 'g': case 'G': {
            double value;
            if (failed) {
                value = lbl_8059FF68[0];
            } else {
                value = fn_803FA804(spec.width, read, context, &consumed, &overflow);
                if (consumed == 0) {
                    if (!bounded) {
                        goto done;
                    }
                    failed = 1;
                    value = lbl_8059FF68[0];
                } else {
                    characters += consumed;
                }
            }
            if (destination) {
                switch (spec.length) {
                case 0: *(float*)destination = value; break;
                case 8: *(double*)destination = value; break;
                case 9: *(long double*)destination = value; break;
                }
                if (!failed) {
                    assignments++;
                }
            }
            conversions++;
            break;
        }
        case 'c':
            if (!spec.width_specified) {
                spec.width = 1;
            }
            if (destination) {
                if (bounded) {
                    room = 1;
                    capacity = *(u32*)__va_arg(args, 1);
                }
                consumed = 0;
                if (failed) {
                    if (capacity) {
                        *destination = 0;
                    }
                    continue;
                }
                character_start = destination;
                while (spec.width-- && (!bounded || (room = ((u32)capacity > consumed))) && (input = read(context, 0, 0)) != -1) {
                    c = input;
                    if (spec.length == 10) {
                        fn_803F5EF4(destination, &c, 1);
                        destination++;
                    } else {
                        *destination++ = c;
                    }
                    consumed++;
                }
                c = input;
                if (consumed == 0 || (bounded && !room)) {
                    if (!bounded) {
                        goto done;
                    }
                    failed = 1;
                    if (capacity) {
                        *character_start = 0;
                    }
                    continue;
                }
                characters += consumed;
                assignments++;
            } else {
                consumed = 0;
                while (spec.width-- && (input = read(context, 0, 0)) != -1) {
                    c = input;
                    consumed++;
                }
                c = input;
                if (consumed == 0) {
                    goto done;
                }
            }
            conversions++;
            break;
        case '%':
            if (failed) {
                continue;
            }
            while (IsSpace(c = read(context, 0, 0))) {
                characters++;
            }
            if (c != '%') {
                read(context, c, 1);
                if (!bounded) {
                    goto done;
                }
                failed = 1;
                continue;
            }
            characters++;
            break;
        case 's':
            if (!failed) {
                c = read(context, 0, 0);
                while (IsSpace(c)) {
                    characters++;
                    c = read(context, 0, 0);
                }
                read(context, c, 1);
            }
            /* The descriptor supplies the non-whitespace bitmap for %s. */
        case '[':
            if (destination) {
                if (bounded) {
                    room = 1;
                    capacity = *(u32*)__va_arg(args, 1) - 1;
                }
                consumed = 0;
                if (failed) {
                    if (capacity) {
                        *destination = 0;
                    }
                    continue;
                }
                string_start = destination;
                while (spec.width-- && (!bounded || (room = (capacity >= (u32)consumed))) && (input = read(context, 0, 0)) != -1) {
                    unsigned int character = (unsigned char)input;
                    c = input;
                    if (!(spec.scanset[character >> 3] & (1 << (character & 7)))) {
                        break;
                    }
                    if (spec.length == 10) {
                        fn_803F5EF4(destination, &c, 1);
                        destination += 2;
                    } else {
                        *destination++ = character;
                    }
                    consumed++;
                }
                c = input;
                if (consumed == 0 || (bounded && !room)) {
                    read(context, c, 1);
                    if (!bounded) {
                        goto done;
                    }
                    failed = 1;
                    if (capacity) {
                        *string_start = 0;
                    }
                    continue;
                }
                characters += consumed;
                if (spec.length == 10) {
                    *(unsigned short*)destination = 0;
                } else {
                    *destination = 0;
                }
                assignments++;
            } else {
                consumed = 0;
                while (spec.width-- && (input = read(context, 0, 0)) != -1) {
                    c = input;
                    if (!(spec.scanset[((unsigned char)input) >> 3] & (1 << (input & 7)))) {
                        break;
                    }
                    consumed++;
                }
                c = input;
                if (consumed == 0) {
                    read(context, c, 1);
                    continue;
                }
                characters += consumed;
            }
            if (spec.width >= 0) {
                read(context, c, 1);
            }
            conversions++;
            break;
        case 'n':
            if (destination) {
                switch (spec.length) {
                case 0: *(int*)destination = characters; break;
                case 2: *(short*)destination = characters; break;
                case 3: *(long*)destination = characters; break;
                case 1: *(signed char*)destination = characters; break;
                case 7: *(s64*)destination = characters; break;
                }
            }
            break;
        case 0xff:
            goto done;
        default:
            goto done;
        }
    }
done:
    if (read(context, 0, 2) && conversions == 0) {
        return -1;
    }
    return assignments;
}
