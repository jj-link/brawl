#pragma force_active on
extern "C" int fn_80334F74(const signed char* src, int len, signed char* dst, unsigned int dstSize) {
    int u;
    unsigned char sp[4];
    int i;
    int written;
    int count;
    if (len & 3) {
        return -1;
    }
    const signed char* q = src;
    count = 0;
    for (i = 0; i < len; i++) {
        if (*q != 0x2A) {
            count += 6;
        }
        q++;
    }
    int k;
    count /= 8;
    if (dst == 0) {
        return count;
    }
    if (dstSize < (unsigned int)count) {
        return -1;
    }
    if (len == 0) {
        *dst = 0;
        return 0;
    }
    const unsigned char* p = (const unsigned char*)src;
    signed char* o = dst;
    do {
        for (k = 0; k < 4; k++) {
            u = p[k];
            if ((signed char)u >= 0x41 && (signed char)u <= 0x5A) {
                sp[k] = u - 0x41;
            } else if ((signed char)u >= 0x61 && (signed char)u <= 0x7A) {
                sp[k] = u - 0x47;
            } else if ((signed char)u >= 0x30 && (signed char)u <= 0x39) {
                sp[k] = u + 4;
            } else if ((signed char)u == 0x2E) {
                sp[k] = 0x3E;
            } else if ((signed char)u == 0x2D) {
                sp[k] = 0x3F;
            } else {
                sp[k] = 0;
            }
        }
        p += 4;
        o[0] = (signed char)(((signed char)sp[0] << 2) | ((signed char)sp[1] >> 4));
        written = (int)(o + 1 - dst);
        if (written < count) {
            o[1] = (signed char)(((signed char)sp[1] << 4) | ((signed char)sp[2] >> 2));
            written = (int)(o + 2 - dst);
            if (written < count) {
                o[2] = (signed char)(((signed char)sp[2] << 6) | sp[3]);
                o += 3;
                written = (int)(o - dst);
                if (written < count) {
                    continue;
                }
            }
        }
        break;
    } while (1);
    return written;
}