typedef int (*ReadProc)(void*, int, int);

struct dec {
    unsigned char flag;
    unsigned char pad0;
    short exp;
    unsigned char count;
    unsigned char dig[36];
};

struct CTypeTable {
    unsigned char reserved[8];
    const unsigned short* classes;
    const unsigned char* upper;
};

struct Locale {
    unsigned char reserved[0x38];
    struct CTypeTable* ctype;
};

struct InfinityName {
    signed char text[9];
};

extern struct Locale lbl_804942B8;
extern const char* lbl_80494108[];
extern struct InfinityName lbl_8041FB40;
extern unsigned char lbl_805A4BC8;
extern unsigned char lbl_805A4BC9;
extern unsigned char lbl_805A4BCA;
extern unsigned char lbl_805A4BCB;
extern unsigned char lbl_805A4BCC;
extern const double lbl_805A4BD0;
extern const double lbl_805A4BD8;
extern const double lbl_805A4BE0;
extern const float lbl_8059FF6C[];
extern const double lbl_8059FF70[];
extern double fn_803F48B0(const struct dec*);
extern double fn_80400D90(const char*);
extern void* memset(void*, int, unsigned long);

static inline int classify(int c, int mask) {
    return c < 0 || c >= 256 ? 0 :
        lbl_804942B8.ctype->classes[c] & mask;
}

static inline int uppercase(int c) {
    return c < 0 || c >= 256 ? c :
        lbl_804942B8.ctype->upper[c];
}

/* Callback actions are read (0) and pushback (1). Width excludes whitespace.
 * Keep the decimal and hexadecimal state machines separate: their accepted
 * terminal states and exponent/sign handling differ in the original runtime.
 */
double fn_803FA804(int width, ReadProc read, void* context,
                   int* consumed, int* overflow) {
    int hex_state = 0;
    int negative = 0;
    int exponent_negative = 0;
    int sign_present = 0;
    int hex_exponent_negative = 0;
    struct dec number = {0};
    struct InfinityName infinity;
    unsigned char hex[8];
    signed char nan_name[5];
    union {
        double value;
        unsigned char bytes[8];
    } binary;
    int state = 1;
    int spaces = 0;
    int exponent = 0;
    int decimal_offset = 0;
    int hex_exponent = 0;
    int hex_digits = 0;
    int count = 1;
    int character;
    int decimal_point = (unsigned char)lbl_80494108[0][0];
    int nibble_index;
    unsigned char* hex_position;
    signed char* name_position;
    int matched;
    int token_count;
    double result;

    *overflow = 0;
    character = read(context, 0, 0);
    while (count <= width && character != -1 && !(state & 0x1800)) {
        switch (state) {
        case 1:
            if (classify(character, 0x100)) {
                character = read(context, 0, 0);
                ++spaces;
                break;
            }
            switch (uppercase(character)) {
            case '-':
                negative = 1;
            case '+':
                ++count;
                character = read(context, 0, 0);
                sign_present = 1;
                break;
            case 'I':
                ++count;
                character = read(context, 0, 0);
                state = 0x4000;
                break;
            case 'N':
                ++count;
                character = read(context, 0, 0);
                state = 0x2000;
                break;
            default:
                state = 2;
                break;
            }
            break;
        case 0x4000:
            infinity = lbl_8041FB40;
            name_position = infinity.text + 1;
            token_count = 1;
            while (token_count < 8 && *name_position == uppercase(character)) {
                ++name_position;
                ++token_count;
                ++count;
                character = read(context, 0, 0);
            }
            if (token_count == 3 || token_count == 8) {
                result = negative ? (float)-(double)lbl_8059FF6C[0] : lbl_8059FF6C[0];
                *consumed = sign_present + spaces + token_count;
                return result;
            }
            state = 0x1000;
            break;
        case 0x2000: {
            int payload_count = 0;
            nan_name[0] = lbl_805A4BC8;
            nan_name[1] = lbl_805A4BC9;
            nan_name[2] = lbl_805A4BCA;
            nan_name[3] = lbl_805A4BCB;
            nan_name[4] = lbl_805A4BCC;
            {
            char payload[32] = {0};
            name_position = nan_name + 1;
            matched = 1;
            while (matched < 4 && *name_position == uppercase(character)) {
                ++name_position;
                ++matched;
                ++count;
                character = read(context, 0, 0);
            }
            if (matched == 3 || matched == 4) {
                if (matched == 4) {
                    char* position = payload;
                    while (payload_count < 32 &&
                           (classify(character, 8) || classify(character, 1) ||
                            character == decimal_point)) {
                        *position++ = character;
                        ++payload_count;
                        ++count;
                        character = read(context, 0, 0);
                    }
                    if (character != ')') {
                        state = 0x1000;
                        break;
                    }
                    ++payload_count;
                }
                payload[payload_count] = 0;
                result = negative ? -fn_80400D90(payload) : fn_80400D90(payload);
                *consumed = (sign_present + matched) + (payload_count + spaces);
                return result;
            }
            state = 0x1000;
            break;
            }
        }
        case 2:
            if (character == decimal_point) {
                state = 0x10;
                ++count;
                character = read(context, 0, 0);
            } else if (!classify(character, 8)) {
                state = 0x1000;
            } else if (character == '0') {
                ++count;
                character = read(context, 0, 0);
                if (uppercase(character) == 'X') {
                    hex_state = 1;
                    state = 0x8000;
                } else {
                    state = 4;
                }
            } else {
                state = 8;
            }
            break;
        case 4:
            if (character == '0') {
                ++count;
                character = read(context, 0, 0);
            } else {
                state = 8;
            }
            break;
        case 8:
            if (!classify(character, 8)) {
                if (character == decimal_point) {
                    state = 0x20;
                    ++count;
                    character = read(context, 0, 0);
                } else {
                    state = 0x40;
                }
                break;
            }
            if (number.count < 20) {
                number.dig[number.count++] = character;
            } else {
                ++decimal_offset;
            }
            ++count;
            character = read(context, 0, 0);
            break;
        case 0x10:
            if (!classify(character, 8)) {
                state = 0x1000;
            } else {
                state = 0x20;
            }
            break;
        case 0x20:
            if (!classify(character, 8)) {
                state = 0x40;
                break;
            }
            if (number.count < 20) {
                if (character != '0' || number.count != 0) {
                    number.dig[number.count++] = character;
                }
                --decimal_offset;
            }
            ++count;
            character = read(context, 0, 0);
            break;
        case 0x40:
            if (uppercase(character) == 'E') {
                state = 0x80;
                ++count;
                character = read(context, 0, 0);
            } else {
                state = 0x800;
            }
            break;
        case 0x80:
            if (character == '+') {
                ++count;
                character = read(context, 0, 0);
            } else if (character == '-') {
                ++count;
                character = read(context, 0, 0);
                exponent_negative = 1;
            }
            state = 0x100;
            break;
        case 0x100:
            if (!classify(character, 8)) {
                state = 0x1000;
            } else if (character == '0') {
                state = 0x200;
                ++count;
                character = read(context, 0, 0);
            } else {
                state = 0x400;
            }
            break;
        case 0x200:
            if (character == '0') {
                ++count;
                character = read(context, 0, 0);
            } else {
                state = 0x400;
            }
            break;
        case 0x400:
            if (!classify(character, 8)) {
                state = 0x800;
                break;
            }
            exponent = character + exponent * 10 - '0';
            if (exponent > 32767) {
                *overflow = 1;
            }
            ++count;
            character = read(context, 0, 0);
            break;
        case 0x8000:
            switch (hex_state) {
            case 1:
                memset(hex, 0, sizeof(hex));
                hex_position = hex;
                hex_digits = 0;
                nibble_index = 0;
                hex_state = 2;
                ++count;
                character = read(context, 0, 0);
                break;
            case 2:
                if (character == '0') {
                    ++count;
                    character = read(context, 0, 0);
                } else {
                    hex_state = 4;
                }
                break;
            case 4:
                if (!classify(character, 0x400)) {
                    if (character == decimal_point) {
                        hex_state = 8;
                        ++count;
                        character = read(context, 0, 0);
                    } else {
                        hex_state = 0x10;
                    }
                    break;
                }
                if (hex_digits < sizeof(hex) * 2 - 2) {
                    int packed = hex_position[nibble_index / 2];
                    int digit;
                    unsigned char merged;
                    unsigned char low;
                    unsigned char high;
                    ++hex_digits;
                    character = uppercase(character);
                    digit = character - '0';
                    if (character >= 'A') {
                        digit = character - '7';
                    }
                    low = digit;
                    high = (digit & 15) << 4;
                    merged = packed | high;
                    if (nibble_index % 2) {
                        merged = packed | low;
                    }
                    packed = merged;
                    hex_position[nibble_index / 2] = packed;
                    ++nibble_index;
                    ++count;
                    character = read(context, 0, 0);
                } else {
                    ++count;
                    character = read(context, 0, 0);
                }
                break;
            case 8:
                if (!classify(character, 0x400)) {
                    hex_state = 0x10;
                    break;
                }
                if (hex_digits < sizeof(hex) * 2 - 2) {
                    int packed = hex_position[nibble_index / 2];
                    int digit;
                    unsigned char merged;
                    unsigned char low;
                    unsigned char high;
                    character = uppercase(character);
                    digit = character - '0';
                    if (character >= 'A') {
                        digit = character - '7';
                    }
                    low = digit;
                    high = (digit & 15) << 4;
                    merged = packed | high;
                    if (nibble_index % 2) {
                        merged = packed | low;
                    }
                    packed = merged;
                    hex_position[nibble_index / 2] = packed;
                    ++nibble_index;
                    ++count;
                    character = read(context, 0, 0);
                } else {
                    ++count;
                    character = read(context, 0, 0);
                }
                break;
            case 0x10:
                if (uppercase(character) == 'P') {
                    hex_state = 0x20;
                    ++count;
                    character = read(context, 0, 0);
                } else {
                    state = 0x800;
                }
                break;
            case 0x20:
                if (character == '-') {
                    hex_exponent_negative = 1;
                } else if (character != '+') {
                    read(context, character, 1);
                    --count;
                }
                hex_state = 0x40;
                ++count;
                character = read(context, 0, 0);
                break;
            case 0x40:
                if (!classify(character, 8)) {
                    state = 0x1000;
                } else if (character == '0') {
                    hex_state = 0x80;
                    ++count;
                    character = read(context, 0, 0);
                } else {
                    hex_state = 0x100;
                }
                break;
            case 0x80:
                if (character == '0') {
                    ++count;
                    character = read(context, 0, 0);
                } else {
                    hex_state = 0x100;
                }
                break;
            case 0x100:
                if (!classify(character, 8)) {
                    state = 0x800;
                    break;
                }
                hex_exponent = character + hex_exponent * 10 - '0';
                /* The original checks the decimal exponent here. */
                if (exponent > 32767) {
                    *overflow = 1;
                }
                ++count;
                character = read(context, 0, 0);
                break;
            }
            break;
        }
    }
    if (state != 0x8000 ? !(state & 0xe2c) :
        (count - 1 <= 2 || !(hex_state & 0x18e))) {
        *consumed = 0;
    } else {
        *consumed = count + spaces - 1;
    }
    read(context, character, 1);
    if (!hex_state) {
        int digits;
        unsigned char* position;
        if (exponent_negative) {
            exponent = -exponent;
        }
        digits = number.count;
        position = number.dig + digits;
        while (digits-- && *--position == '0') {
            ++decimal_offset;
        }
        number.count = digits + 1;
        if (number.count == 0) {
            number.dig[number.count++] = '0';
        }
        exponent += decimal_offset;
        if (exponent < -32768 || exponent > 32767) {
            *overflow = 1;
        }
        if (*overflow) {
            if (exponent_negative) {
                return lbl_805A4BD0;
            }
            return negative ? -lbl_8059FF70[0] : lbl_8059FF70[0];
        }
        number.exp = exponent;
        result = fn_803F48B0(&number);
        if (lbl_805A4BD0 != result && result < lbl_805A4BD8) {
            *overflow = 1;
        } else if (result > lbl_805A4BE0) {
            *overflow = 1;
            result = lbl_8059FF70[0];
        }
        if (negative && (state & 0xe2c)) {
            result = -result;
        }
        return result;
    } else {
        unsigned int leading = 0;
        unsigned int shift;
        unsigned char carry;
        unsigned int bits;
        unsigned char* output;
        if (hex_exponent_negative) {
            hex_exponent = -hex_exponent;
        }
        hex_exponent += hex_digits * 4;
        while (leading < 4 && !(hex[0] & (0x80 >> leading))) {
            ++leading;
            --hex_exponent;
        }
        shift = leading + 1;
        if (shift) {
            carry = 0;
            for (hex_position = hex + 7; hex_position >= hex; --hex_position) {
                unsigned char next = *hex_position >> (8 - shift);
                *hex_position = (*hex_position << shift) | carry;
                carry = next;
            }
        }
        memset(binary.bytes, 0, sizeof(binary.bytes));
        hex_position = hex;
        output = binary.bytes + 1;
        for (bits = 0; bits < 52; bits += 8) {
            unsigned char digit = *hex_position;
            unsigned int right_shift;
            if (bits + 8 > 52) {
                digit &= 0xff << (52 - bits);
            }
            right_shift = (bits + 12) % 8;
            ++hex_position;
            *output |= (unsigned char)(digit >> right_shift);
            ++output;
            *output |= (unsigned char)(digit << (8 - right_shift));
        }
        hex_exponent += 1022;
        if (hex_exponent & ~0x7ff) {
            *overflow = 1;
            return lbl_805A4BD0;
        }
        hex_exponent <<= 21;
        binary.bytes[0] |= (unsigned int)hex_exponent >> 25;
        binary.bytes[1] |= (unsigned int)hex_exponent >> 17;
        if (negative) {
            binary.bytes[0] |= 0x80;
        }
        return binary.value;
    }
}
