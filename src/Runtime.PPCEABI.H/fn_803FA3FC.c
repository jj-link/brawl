typedef unsigned int u32;

#pragma force_active on

/* Compare equal-aligned strings wordwise until a mismatch or possible NUL,
   then finish bytewise to preserve unsigned-character ordering. */
int strcmp(const char* lhs, const char* rhs) {
    const unsigned char* l = (const unsigned char*)lhs;
    const unsigned char* r = (const unsigned char*)rhs;
    int byte;
    int difference;
    u32 align;
    u32 head;
    u32 left;
    u32 right;
    u32 mask;
    u32 zeros;

    byte = *l;
    if ((difference = byte - *r) != 0) {
        return difference;
    }
    if (((u32)r & 3u) == (align = (u32)l & 3u)) {
        if (align != 0) {
            if (byte == 0) {
                return 0;
            }
            for (head = 3u - align; head != 0; --head) {
                byte = *++l;
                if ((difference = byte - *++r) != 0) {
                    return difference;
                }
                if (byte == 0) {
                    return 0;
                }
            }
            ++l;
            ++r;
        }
        left = *(const u32*)l;
        mask = 0x80808080u;
        right = *(const u32*)r;
        zeros = left - 0x01010101u;
        zeros &= ~left;
        if ((zeros & mask) == 0) {
            while (left == right) {
                l += 4;
                left = *(const u32*)l;
                r += 4;
                right = *(const u32*)r;
                zeros = left - 0x01010101u;
                if ((zeros & mask) != 0) {
                    break;
                }
            }
        }
        byte = *l;
        if ((difference = byte - *r) != 0) {
            return difference;
        }
    }
    if (byte == 0) {
        return 0;
    }
    do {
        byte = *++l;
        if ((difference = byte - *++r) != 0) {
            return difference;
        }
    } while (byte != 0);
    return 0;
}
