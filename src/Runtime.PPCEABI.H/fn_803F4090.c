struct dec {
    unsigned char flag;
    unsigned char pad0;
    short exp;
    unsigned char count;
    unsigned char dig[36];
};

/* Subtract normalized magnitudes: lhs must be greater than a nonzero rhs.
 * The sign, unused bytes, and unused digits are inherited from lhs.
 */
void fn_803F4090(struct dec* out, const struct dec* lhs,
                const struct dec* rhs) {
    int width;
    int offset;
    unsigned char* digits;
    unsigned char* digit;
    const unsigned char* right_digits;
    const unsigned char* right;
    const unsigned char* discarded;

    *out = *lhs;
    if (rhs->dig[0] == 0) {
        return;
    }

    width = out->count;
    if (width < rhs->count) {
        width = rhs->count;
    }
    offset = out->exp - rhs->exp;
    width += offset;
    if (width > 36) {
        width = 36;
    }
    while (out->count < width) {
        out->dig[out->count++] = 0;
    }

    {
        int aligned_count = rhs->count + offset;

        digits = out->dig;
        digit = digits + width;
        if (aligned_count < width) {
            digit = digits + aligned_count;
        }
    }
    right_digits = rhs->dig;
    right = right_digits + ((digit - digits) - offset);
    discarded = right;

    /* Work from the least significant overlapping column toward the left.
     * Borrowing adds ten to each successive column before subtracting one.
     */
    while (digit > digits && right > right_digits) {
        --digit;
        --right;
        if (*digit < *right) {
            unsigned char* borrow = digit - 1;

            while (*borrow == 0) {
                --borrow;
            }
            while (borrow != digit) {
                --*borrow;
                ++borrow;
                *borrow += 10;
            }
        }
        *digit -= *right;
    }

    if (discarded - right_digits < rhs->count) {
        int decrement = 0;

        if (*discarded < 5) {
            decrement = 1;
        } else if (*discarded == 5) {
            const unsigned char* remaining = discarded + 1;
            const unsigned char* end = rhs->dig + rhs->count;

            while (remaining < end) {
                if (*remaining != 0) {
                    goto normalize;
                }
                ++remaining;
            }
            digit = digits + (discarded - right_digits) + offset;
            --digit;
            if (*digit & 1) {
                decrement = 1;
            }
        }

        /* Preserve the target's cursor choice: a tail below five adjusts
         * the cursor left by subtraction; only an exact half repositions
         * it to the last retained column.
         */
        if (decrement) {
            if (*digit < 1) {
                unsigned char* borrow = digit - 1;

                while (*borrow == 0) {
                    --borrow;
                }
                while (borrow != digit) {
                    --*borrow;
                    ++borrow;
                    *borrow += 10;
                }
            }
            --*digit;
        }
    }

normalize:
    {
        unsigned char* first = digits;

        while (*first == 0) {
            ++first;
        }
        if (first > digits) {
            unsigned char skipped = first - digits;

            out->exp -= skipped;
            digit = digits + out->count;
            while (first < digit) {
                *digits++ = *first++;
            }
            out->count -= skipped;
        }
    }
    digits = out->dig;
    digit = digits + out->count;
    while (digit > digits) {
        if (*--digit != 0) {
            break;
        }
    }
    {
        int length = digit - digits;

        out->count = length + 1;
    }
}
