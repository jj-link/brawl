#include <types.h>
#pragma force_active on

u8 *fn_801E22F8(u8 *p, u32 *out) {
    u16 low;
    u16 c;
    u32 result;
    c = *(u16 *)p;
    if (c != 0) {
        p += 2;
    }
    if ((c < 0xd800) || (c > 0xdfff)) {
        result = c;
        goto done;
    }
    if (c <= 0xdbff) {
        low = *(u16 *)p;
        p += 2;
        if ((low >= 0xdc00) && (low <= 0xdfff)) {
            result = ((c & 0x3ff) << 10) | (low & 0x3ff);
            result += 0x10000;
            goto done;
        }
        return 0;
    }
    return 0;
done:
    *out = result;
    return p;
}