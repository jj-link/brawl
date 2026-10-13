typedef unsigned long long u64;
typedef int (*ReadProc)(void* context, int character, int action);

typedef struct CTypeTable {
    unsigned char reserved[8];
    const unsigned short* classes;
    const unsigned char* upper;
} CTypeTable;

extern char lbl_804942B8[];

static inline int classify(int character, int mask) {
    return character < 0 || character >= 256 ? 0 :
        (*(CTypeTable**)(lbl_804942B8 + 0x38))->classes[character] & mask;
}

static inline int uppercase(int character) {
    return character < 0 || character >= 256 ? character :
        (*(CTypeTable**)(lbl_804942B8 + 0x38))->upper[character];
}

// Parse an unsigned magnitude; return the sign separately and always push
// back the lookahead character. Width excludes leading whitespace.
u64 fn_803FC0AC(int base, int width, ReadProc read, void* context,
               int* consumed, int* negative, int* overflow) {
    int state = 1;
    int count = 0;
    int spaces = 0;
    u64 value = 0;
    u64 cutoff = 0;
    int character;

    *overflow = 0;
    *negative = 0;
    if (base < 0 || base == 1 || base > 36 || width < 1) {
        state = 64;
    } else {
        ++count;
        character = read(context, 0, 0);
    }
    if (base != 0) {
        cutoff = ~(u64)0 / base;
    }

    while (count <= width && character != -1 && !(state & 96)) {
        switch (state) {
        case 1:
            if (classify(character, 0x100)) {
                character = read(context, 0, 0);
                ++spaces;
                break;
            }
            if (character == '+') {
                ++count;
                character = read(context, 0, 0);
            } else if (character == '-') {
                ++count;
                character = read(context, 0, 0);
                *negative = 1;
            }
            state = 2;
            break;
        case 2:
            if ((base == 0 || base == 16) && character == '0') {
                state = 4;
                ++count;
                character = read(context, 0, 0);
            } else {
                state = 8;
            }
            break;
        case 4:
            if (character == 'X' || character == 'x') {
                base = 16;
                state = 8;
                ++count;
                character = read(context, 0, 0);
            } else {
                if (base == 0) {
                    base = 8;
                }
                state = 16;
            }
            break;
        case 8:
        case 16:
            if (base == 0) {
                base = 10;
            }
            if (0 == cutoff) {
                cutoff = ~(u64)0 / base;
            }
            if (classify(character, 8)) {
                character -= '0';
                if (character >= base) {
                    state = state == 16 ? 32 : 64;
                    character += '0';
                    break;
                }
            } else if (!classify(character, 1) || uppercase(character) - '7' >= base) {
                if (state == 16) {
                    state = 32;
                } else {
                    state = 64;
                }
                break;
            } else {
                character = uppercase(character) - '7';
            }
            if (value > cutoff) {
                *overflow = 1;
            }
            value *= base;
            if ((u64)character > ~(u64)0 - value) {
                *overflow = 1;
            }
            value += character;
            state = 16;
            ++count;
            character = read(context, 0, 0);
            break;
        }
    }

    if (!(state & 52)) {
        value = 0;
        *consumed = 0;
    } else {
        *consumed = count + spaces - 1;
    }
    read(context, character, 1);
    return value;
}
