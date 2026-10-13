typedef unsigned char u8;
typedef signed char s8;

struct ScanFormat {
    u8 suppress;
    u8 width_specified;
    u8 length;
    u8 conversion;
    int width;
    u8 scanset[32];
};

struct CTypeTable {
    unsigned char reserved[8];
    const unsigned short* classes;
};

extern const struct ScanFormat lbl_8041FB18;
extern char lbl_804942B8[];
struct ScanWordPair {
    unsigned long first;
    unsigned long second;
};

static inline void ScanCopyFormat(struct ScanFormat* destination,
                                  const struct ScanFormat* source) {
    int i;
    for (i = 0; i < sizeof(*source) / sizeof(struct ScanWordPair); ++i) {
        ((struct ScanWordPair*)destination)[i] =
            ((const struct ScanWordPair*)source)[i];
    }
}

static inline int ScanIsDigit(int character) {
    return (character < 0 || character >= 256) ? 0 :
        (*(struct CTypeTable**)(lbl_804942B8 + 0x38))->classes[character] & 8;
}

const char* fn_803F8C64(const char* format, struct ScanFormat* result) {
    int character = (u8)*++format;
    struct ScanFormat spec = lbl_8041FB18;
    int has_length;
    int invert;
    int end;
    int i;
    u8* set;

    character = (s8)character;
    if (character == '%') {
        spec.conversion = character;
        *result = spec;
        return format + 1;
    }
    if (character == '*') {
        character = (s8)*++format;
        spec.suppress = 1;
    }
    if (ScanIsDigit(character)) {
        spec.width = 0;
        do {
            spec.width = spec.width * 10 + character - '0';
            character = (s8)*++format;
        } while (ScanIsDigit(character));
        if (spec.width == 0) {
            int width = spec.width;
            spec.conversion = 0xff;
            *(unsigned long*)result = *(const unsigned long*)&spec;
            result->width = width;
            for (i = 1; i < sizeof(spec) / sizeof(struct ScanWordPair); ++i) {
                ((struct ScanWordPair*)result)[i] =
                    ((const struct ScanWordPair*)&spec)[i];
            }
            return format + 1;
        }
        spec.width_specified = 1;
    }
    has_length = 1;
    switch (character) {
    case 'h':
        spec.length = 2;
        if ((s8)format[1] == 'h') {
            spec.length = 1;
            character = (s8)*++format;
        }
        break;
    case 'l':
        spec.length = 3;
        if ((s8)format[1] == 'l') {
            spec.length = 7;
            character = (s8)*++format;
        }
        break;
    case 'L': spec.length = 9; break;
    case 'j': spec.length = 4; break;
    case 'z': spec.length = 5; break;
    case 't': spec.length = 6; break;
    default: has_length = 0; break;
    }
    if (has_length) {
        character = (s8)*++format;
    }
    spec.conversion = character;
    switch (character) {
    case 'd': case 'i': case 'o': case 'u': case 'x': case 'X':
        if (spec.length == 9) spec.conversion = 0xff;
        break;
    case 'a': case 'A': case 'e': case 'E': case 'f': case 'F': case 'g': case 'G':
        if (spec.length == 1 || spec.length == 2 ||
            (u8)(spec.length + 252) <= 3) {
            spec.conversion = 0xff;
        } else if (spec.length == 3) {
            spec.length = 8;
        }
        break;
    case 'p':
        spec.length = 3;
        spec.conversion = 'x';
        break;
    case 'c':
        if (spec.length == 3) spec.length = 10;
        else if (spec.length != 0) spec.conversion = 0xff;
        break;
    case 's':
        if (spec.length == 3) spec.length = 10;
        else if (spec.length != 0) spec.conversion = 0xff;
        for (i = 0; i < 32; ++i) spec.scanset[i] = 0xff;
        spec.scanset[1] = 0xc1;
        spec.scanset[4] = 0xfe;
        break;
    case '[':
        if (spec.length == 3) spec.length = 10;
        else if (spec.length != 0) spec.conversion = 0xff;
        character = (s8)*++format;
        invert = 0;
        if (character == '^') {
            character = (s8)*++format;
            invert = 1;
        }
        if (character == ']') {
            spec.scanset[']' >> 3] |= 1 << (']' & 7);
            character = (s8)*++format;
        }
        while (character != 0 && character != ']') {
            spec.scanset[(u8)character >> 3] |= 1 << (character & 7);
            if (format[1] == '-' && (end = (s8)format[2]) != 0 && end != ']') {
                while (++character <= end) {
                    spec.scanset[(u8)character >> 3] |= 1 << (character & 7);
                }
                format += 3;
                character = (s8)*format;
            } else {
                character = (s8)*++format;
            }
        }
        if (character == 0) {
            spec.conversion = 0xff;
        } else if (invert) {
            set = spec.scanset;
            for (i = 0; i < 32; ++i) {
                *set = ~*set;
                ++set;
            }
        }
        break;
    case 'n': break;
    default: spec.conversion = 0xff; break;
    }
    ScanCopyFormat(result, &spec);
    return format + 1;
}
