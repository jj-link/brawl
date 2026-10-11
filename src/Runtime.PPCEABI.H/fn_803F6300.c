// Unaligned copy engines used by the memmove dispatcher.
// Invoked with count >= 32 and (dst ^ src) & 3 != 0, so after aligning the
// destination the source is always 1..3 bytes off a word boundary and the
// word merge shift is 8, 16 or 24 (never 0 or 32).

// Keep each source cursor live from byte alignment through the word merges.
static inline void CopyForwardWords(const char* src, char* dst, unsigned long* remaining) {
    unsigned int head;
    unsigned int right_shift;
    unsigned int left_shift;
    unsigned int source_offset;
    const char* s;
    unsigned int words;
    char* word_dst;
    unsigned int carry;
    unsigned int next;
    unsigned int merged;

    head = -(unsigned long)dst & 3;
    s = src - 1;
    --dst;
    if (head != 0) {
        *remaining -= head;
        do {
            *++dst = *++s;
        } while (--head != 0);
    }

    // Keep the last aligned source word: each destination word spans two
    // source words, and the carry must survive stores into an overlapping range.
    source_offset = ((unsigned int)s + 1) & 3;
    word_dst = dst - 3;
    words = *remaining >> 3;
    s -= source_offset;
    left_shift = source_offset * 8;
    carry = *(const unsigned int*)(s += 1);
    right_shift = 32 - left_shift;
    do {
        next = *(const unsigned int*)(s + 4);
        carry <<= left_shift;
        merged = next >> right_shift;
        next <<= left_shift;
        *(unsigned int*)(word_dst + 4) = carry | merged;
        carry = *(const unsigned int*)(s += 8);
        *(unsigned int*)(word_dst += 8) = next | (carry >> right_shift);
    } while (--words != 0);

    if ((*remaining & 4) != 0) {
        next = *(const unsigned int*)(s += 4);
        *(unsigned int*)(word_dst += 4) = (carry << left_shift) | (next >> right_shift);
    }

    {
        const char* tail_src;
        char* tail_dst;
        *remaining &= 3;
        tail_src = s + 3;
        tail_dst = word_dst + 3;
        if (*remaining != 0) {
            tail_src -= 4 - source_offset;
            do {
                *++tail_dst = *++tail_src;
            } while (--*remaining != 0);
        }
    }
}

void fn_803F6300(void* dst, const void* src, unsigned long n) {
    CopyForwardWords((const char*)src, (char*)dst, &n);
}

static inline void CopyBackwardWords(const char* src, char* d, unsigned long* remaining) {
    unsigned int head;
    const char* s;
    unsigned int right_shift;
    unsigned int left_shift;
    unsigned int source_offset;
    unsigned int words;
    unsigned int carry;
    register unsigned int merged;
    unsigned int next;

    head = (unsigned int)d & 3;
    s = src + *remaining;
    if (head != 0) {
        *remaining -= head;
        do {
            *--d = *--s;
        } while (--head != 0);
    }
    source_offset = (unsigned int)s & 3;
    left_shift = source_offset * 8;
    right_shift = 32 - left_shift;
    words = *remaining >> 3;
    s += 4 - source_offset;
    carry = *(const unsigned int*)(s -= 4);
    do {
        merged = carry >> right_shift;
        carry = *(const unsigned int*)(s - 4) << left_shift;
        next = *(const unsigned int*)(s - 4) >> right_shift;
        *(unsigned int*)(d - 4) = carry | merged;
        carry = *(const unsigned int*)(s -= 8);
        merged = carry << left_shift;
        *(unsigned int*)(d -= 8) = merged | next;
    } while (--words != 0);

    if ((*remaining & 4) != 0) {
        merged = *(const unsigned int*)(s -= 4);
        next = carry >> right_shift;
        merged <<= left_shift;
        *(unsigned int*)(d -= 4) = merged | next;
    }

    *remaining &= 3;
    if (*remaining != 0) {
        s += source_offset;
        do {
            *--d = *--s;
        } while (--*remaining != 0);
    }
}

void fn_803F63C0(void* dst, const void* src, unsigned long n) {
    char* d = (char*)dst + n;
    CopyBackwardWords((const char*)src, d, &n);
}
