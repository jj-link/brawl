struct dec {
    unsigned char flag;
    unsigned char pad0;
    short exp;
    unsigned char count;
    unsigned char dig[36];
};

struct decform {
    unsigned char style;
    unsigned char pad0;
    short precision;
};

extern void fn_803F45AC(struct dec* out, double value);

static inline int halfway_direction(const unsigned char* digit,
                                   const unsigned char* end,
                                   const struct dec* out, int precision) {
    int direction;

    while (digit < end) {
        if (*digit != 0) {
            return 1;
        }
        ++digit;
    }
    direction = -1;
    if ((out->dig[precision - 1] & 1) != 0) {
        direction = 1;
    }
    return direction;
}

static inline int rounding_direction(int precision, const struct dec* out) {
    const unsigned char* digit = &out->dig[precision];

    if (*digit > 5) {
        return 1;
    }
    if (*digit < 5) {
        return -1;
    }

    /* An exact halfway value rounds to an even retained digit. */
    return halfway_direction(digit + 1, &out->dig[out->count], out, precision);
}

void fn_803F4710(const struct decform* format, struct dec* out, double value) {
    int precision = format->precision;
    int i;

    fn_803F45AC(out, value);
    if (out->dig[0] > 9) {
        return;
    }
    if (precision > 36) {
        precision = 36;
    }
    if (precision > 0 && precision < out->count) {
        int direction = rounding_direction(precision, out);
        unsigned char* digits;
        unsigned char* digit;

        out->count = precision;
        if (direction >= 0) {
            digits = out->dig;
            digit = digits + precision - 1;
            for (;;) {
                if (*digit < 9) {
                    *digit = *digit + 1;
                    break;
                }
                if (digit == digits) {
                    *digit = 1;
                    out->exp += 1;
                    break;
                }
                *digit = 0;
                --digit;
            }
        }
    }

    /* Nonpositive precision leaves the converted digit count unchanged. */
    while (out->count < precision) {
        out->dig[out->count++] = 0;
    }
    out->exp -= out->count - 1;
    for (i = 0; i < out->count; ++i) {
        out->dig[i] += '0';
    }
}
