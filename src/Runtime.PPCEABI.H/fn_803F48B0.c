struct dec {
    unsigned char flag;
    unsigned char pad0;
    short exp;
    unsigned char count;
    unsigned char dig[36];
};

extern const double lbl_805A4B68;
extern const double lbl_805A4B70;
extern const double lbl_805A4B78;
extern const double lbl_805A4B80;
extern const double lbl_805A4B88;
extern const float lbl_8059FF6C[];
extern const char lbl_8041F500[0xe0];
extern double lbl_804940C8[8];
extern double fn_804004AC(double magnitude, double sign);
extern double fn_80400B44(double base, double exponent);
extern double fn_80400778(double value, int exponent);
extern int fn_803F64E8(double value);
extern void fn_803F3A54(struct dec* out, const char* digits, int exponent);
extern int fn_803F3EAC(const struct dec* lhs, const struct dec* rhs);
extern int fn_803F3F90(const struct dec* lhs, const struct dec* rhs);
extern void fn_803F4090(struct dec* out, const struct dec* lhs,
                        const struct dec* rhs);
extern void fn_803F45AC(struct dec* out, double value);

/* Convert the external ASCII decimal record, then bracket the result with
 * adjacent doubles and compare decimal distances for round-to-nearest-even. */
double fn_803F48B0(const struct dec* input) {
    struct dec number;
    struct dec maximum;
    struct dec current;
    struct dec adjacent;
    struct dec lower_distance;
    struct dec upper_distance;
    union binary64 {
        double value;
        unsigned long long bits;
        struct { unsigned long high, low; } words;
    } special;
    struct { unsigned long high, low; } result;
    union binary64 neighbor;
    double value;
    unsigned char* digit;
    unsigned char* end;
    int exponent;
    int below;
    int downward;

    if (input->count == 0) {
        return fn_804004AC(lbl_805A4B68,
                          (signed char)input->flag == 0 ? lbl_805A4B70 : lbl_805A4B78);
    }
    switch (input->dig[0]) {
    case '0':
        return fn_804004AC(lbl_805A4B68,
                          (signed char)input->flag == 0 ? lbl_805A4B70 : lbl_805A4B78);
    case 'I':
        return fn_804004AC(lbl_8059FF6C[0],
                          (signed char)input->flag == 0 ? lbl_805A4B70 : lbl_805A4B78);
    case 'N':
        special.bits = 0x7ff0000000000000ULL;
        if ((signed char)input->flag != 0) {
            special.bits = 0x8000000000000000ULL;
            special.words.high |= 0x7ff00000;
        }
        special.words.high |= 0x00080000;
        return special.value;
    }

    number = *input;
    digit = number.dig;
    end = digit + number.count;
    for (; digit < end; ++digit) {
        *digit -= '0';
    }
    number.exp += number.count - 1;
    exponent = number.exp;
    fn_803F3A54(&maximum, lbl_8041F500 + 0xb8, 308);
    if (fn_803F3F90(&maximum, &number)) {
        return fn_804004AC(lbl_8059FF6C[0],
                          (signed char)input->flag == 0 ? lbl_805A4B70 : lbl_805A4B78);
    }

    value = number.dig[0];
    digit = number.dig + 1;
    while (digit < end) {
        int i;
        int width = (end - digit) % 8;
        unsigned long chunk = 0;
        double scaled;
        double combined;
        if (width == 0) {
            width = 8;
        }
        for (i = 0; i < width; ++i) {
            chunk = chunk * 10 + *digit++;
        }
        scaled = value * lbl_804940C8[width - 1];
        combined = scaled + chunk;
        if (chunk != 0 && scaled == combined) {
            break;
        }
        value = combined;
        exponent -= width;
    }
    if (exponent < 0) {
        value /= fn_80400B44(lbl_805A4B80, -exponent);
    } else {
        value *= fn_80400B44(lbl_805A4B80, exponent);
    }
    value = fn_80400778(value, exponent);
    *(double*)&result = value;
    if (fn_803F64E8(value) == 2) {
        value = lbl_805A4B88;
        *(double*)&result = value;
    }
    below = 0;
    fn_803F45AC(&current, value);
    if (!fn_803F3EAC(&current, &number)) {
        if (fn_803F3F90(&current, &number)) {
            below = 1;
        }
        downward = !below;
        neighbor.value = value;
        for (;;) {
            if (!downward) {
                ++neighbor.bits;
                switch (fn_803F64E8(neighbor.value)) {
                case 2:
                    goto finish;
                default:
                    break;
                }
            } else {
                --neighbor.bits;
            }
            fn_803F45AC(&adjacent, neighbor.value);
            if (below && !fn_803F3F90(&adjacent, &number)) {
                break;
            }
            if (!below && !fn_803F3F90(&number, &adjacent)) {
                double old_value = value;
                value = neighbor.value;
                lower_distance = current;
                current = adjacent;
                adjacent = lower_distance;
                *(double*)&result = value;
                neighbor.value = old_value;
                break;
            }
            current = adjacent;
            value = neighbor.value;
            *(double*)&result = value;
        }
        fn_803F4090(&lower_distance, &number, &current);
        fn_803F4090(&upper_distance, &adjacent, &number);
        if (fn_803F3EAC(&lower_distance, &upper_distance)) {
            if (result.low & 1) {
                value = neighbor.value;
                *(double*)&result = value;
            }
        } else if (!fn_803F3F90(&lower_distance, &upper_distance)) {
            value = neighbor.value;
            *(double*)&result = value;
        }
    }
finish:
    if ((signed char)number.flag != 0) {
        value = -value;
        *(double*)&result = value;
    }
    return value;
}
