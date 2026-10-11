struct dec {
    unsigned char flag;
    unsigned char pad0;
    short exp;
    unsigned char count;
    unsigned char dig[36];
};

int fn_803F3EAC(const struct dec* lhs, const struct dec* rhs) {
    int i;
    int common;

    if (lhs->dig[0] == 0) {
        return rhs->dig[0] == 0;
    }
    if (rhs->dig[0] == 0) {
        return lhs->dig[0] == 0;
    }

    if (lhs->exp == rhs->exp) {
        common = lhs->count;
        if (common > rhs->count) {
            common = rhs->count;
        }

        for (i = 0; i < common; ++i) {
            if (lhs->dig[i] != rhs->dig[i]) {
                return 0;
            }
        }

        /* Digits beyond the common prefix must be zero for equality. */
        if (common == lhs->count) {
            lhs = rhs;
        }
        for (; i < lhs->count; ++i) {
            if (lhs->dig[i] != 0) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int fn_803F3F90(const struct dec* lhs, const struct dec* rhs) {
    int i;
    int common;

    if (lhs->dig[0] == 0) {
        return rhs->dig[0] != 0;
    }
    if (rhs->dig[0] == 0) {
        return 0;
    }

    if (lhs->exp == rhs->exp) {
        common = lhs->count;
        if (common > rhs->count) {
            common = rhs->count;
        }

        for (i = 0; i < common; ++i) {
            if (lhs->dig[i] < rhs->dig[i]) {
                return 1;
            }
            if (rhs->dig[i] < lhs->dig[i]) {
                return 0;
            }
        }

        /* An omitted suffix is zero; only a nonzero rhs suffix is greater. */
        if (common == lhs->count) {
            for (; i < rhs->count; ++i) {
                if (rhs->dig[i] != 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    return lhs->exp < rhs->exp;
}
