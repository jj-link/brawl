struct dec {
    unsigned char flag;
    unsigned char pad0;
    short exp;
    unsigned char count;
    unsigned char dig[36];
};

extern const double lbl_805A4B68;
extern int fn_803F64D0(double value);
extern int fn_803F64E8(double value);
extern double fn_804006F0(double value, int* exponent);
extern unsigned long long fn_803F1960(double value);
extern void fn_803F36F0(struct dec* out, unsigned long long value);
extern void fn_803F3B40(struct dec* out, int exponent);
extern void fn_803F37CC(struct dec* out, const struct dec* lhs,
                      const struct dec* rhs);
extern double fn_80400778(double value, int exponent);
extern int __cntlzw(unsigned int value);

static inline int significant_bits(unsigned int high, unsigned int low) {
    unsigned int trailing;

    high |= 0x00100000;
    /* (word - 1) & ~word contains exactly its trailing zero bits. */
    trailing = 32 - __cntlzw((low - 1) & ~low);
    if (low == 0) {
        high = 32 - __cntlzw((high - 1) & ~high);
        trailing = high + 32;
    }
    return 53 - trailing;
}

static inline void convert_signed_decimal(signed char sign, struct dec* out,
                                          double value) {
    int exponent;
    union {
        double value;
        struct {
            unsigned long high;
            unsigned long low;
        } words;
    } fraction;
    struct dec power;
    struct dec integer;
    int significant;

    if (lbl_805A4B68 == value) {
        out->flag = sign;
        out->exp = 0;
        out->count = 1;
        out->dig[0] = 0;
        return;
    }
    if (fn_803F64E8(value) <= 2) {
        out->flag = sign;
        out->exp = 0;
        out->count = 1;
        out->dig[0] = fn_803F64E8(value) == 1 ? 'N' : 'I';
        return;
    }
    if (sign != 0) {
        value = -value;
    }
    value = fn_804006F0(value, &exponent);
    fraction.value = value;
    significant = significant_bits(fraction.words.high, fraction.words.low);

    /* Factor the value into an integer significand and a power of two. */
    fn_803F3B40(&power, exponent - significant);
    fn_803F36F0(&integer,
                fn_803F1960(fn_80400778(value, significant)));
    fn_803F37CC(out, &integer, &power);
    out->flag = sign;
}

void fn_803F45AC(struct dec* out, double value) {
    signed char sign = fn_803F64D0(value) != 0;

    convert_signed_decimal(sign, out, value);
}
