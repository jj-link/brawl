struct dec {
    unsigned char flag;
    unsigned char pad0;
    short exp;
    unsigned char count;
    unsigned char dig[36];
};

void fn_803F37CC(struct dec* out, const struct dec* lhs,
                const struct dec* rhs) {
    unsigned char product[72];
    unsigned long carry = 0;
    int column = lhs->count + rhs->count - 1;
    unsigned char* cursor = product + column + 1;
    unsigned char* end = cursor;
    int i;
    unsigned char* digit;
    unsigned char* digits;

    out->flag = 0;
    while (column > 0) {
        int right_index = rhs->count - 1;
        int left_index = column - right_index - 1;
        int terms;
        const unsigned char* left;
        const unsigned char* right;

        if (left_index < 0) {
            left_index = 0;
            right_index = column - 1;
        }
        left = lhs->dig + left_index;
        right = rhs->dig + right_index;
        terms = right_index + 1;
        if (terms > lhs->count - left_index) {
            terms = lhs->count - left_index;
        }
        for (; terms > 0; --terms) {
            int left_digit = *left++;
            int right_digit = *right--;
            int coefficient = left_digit * right_digit;

            carry += coefficient;
        }
        --column;
        *--cursor = carry % 10;
        carry /= 10;
    }
    out->exp = lhs->exp + rhs->exp;
    if (carry != 0) {
        *--cursor = carry;
        out->exp += 1;
    }
    i = 0;
    while (i < 36 && cursor < end) {
        out->dig[i] = *cursor;
        ++i;
        ++cursor;
    }
    out->count = i;
    if (cursor >= end) {
        return;
    }
    if (*cursor < 5) {
        return;
    }
    if (*cursor != 5) {
        goto increment;
    }
    {
        const unsigned char* remaining = cursor + 1;

        while (remaining < end) {
            if (*remaining != 0) {
                goto increment;
            }
            ++remaining;
        }
        if ((cursor[-1] & 1) == 0) {
            return;
        }
    }
increment:
    digits = out->dig;
    digit = digits + out->count - 1;
    for (;;) {
        if (*digit < 9) {
            *digit = *digit + 1;
            return;
        }
        if (digit == digits) {
            *digit = 1;
            out->exp += 1;
            return;
        }
        *digit = 0;
        --digit;
    }
}
