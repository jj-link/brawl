struct dec {
    unsigned char flag;
    unsigned char pad0;
    short exp;
    unsigned char count;
    unsigned char dig[36];
};

/* Round ASCII digits to the requested width, dropping trailing zeroes.
 * Exact halfway values round to an even retained digit.
 */
void fn_803F7404(struct dec* value, int width) {
    int carry;
    int remaining;
    signed char digit;
    int count;
    unsigned char* base;
    unsigned char* position;
    unsigned char* end;

    if (width < 0) {
    zero:
        value->exp = 0;
        value->count = 1;
        value->dig[0] = '0';
        return;
    }
    count = value->count;
    if (width >= count) {
        return;
    }
    base = (unsigned char*)value + width;
    digit = base[5] - '0';
    position = base + 5;
    if (digit == 5) {
        end = value->dig + count;
        do {
            --end;
        } while (end > position && (int)*end == '0');
        if (end == position) {
            carry = position[-1] & 1;
        } else {
            carry = 1;
        }
    } else {
        carry = digit > 5;
    }
    for (remaining = width; remaining != 0; --remaining) {
        digit = (signed char)(*--position + carry - '0');
        carry = digit > 9;
        if (carry || digit == 0) {
            --width;
        } else {
            *position = digit + '0';
            break;
        }
    }
    if (carry) {
        carry = value->exp;
        value->count = 1;
        value->exp = carry + 1;
        value->dig[0] = '1';
    } else if (width == 0) {
        goto zero;
    } else {
        value->count = width;
    }
}
