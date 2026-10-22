typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

#pragma force_active on
s32 fn_80392AB8(u8 *arg0, s32 arg1) {
    s32 val;
    s32 seen;
    s32 prev;
    s32 i;
    u8 *p;
    s8 c;

    if (arg1 > 0xA) {
        return -1;
    }
    val = 0;
    seen = 0;
    p = arg0;
    for (i = arg1; i > 0; i--, p++) {
        c = (s8)*p;
        if (seen != 0) {
            if (c == 0x20 || c == 0) {
                break;
            }
        }
        if (seen == 0 && c == 0x20) {
            continue;
        }
        if (c < 0x30 || c > 0x39) {
            return -1;
        }
        prev = val;
        seen = 1;
        val = (c + val * 0xA) - 0x30;
        if (prev > val) {
            return -1;
        }
    }
    return val;
}
