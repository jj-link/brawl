#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

void fn_80350868(u8 *arg0, u32 arg1) {
    u8 *p = arg0;
    u32 i;
    u32 v;
    u32 n;

    for (i = 0; i < 0x100; i++, p++) {
        v = i;
        for (n = 0; n < 8; n++) {
            if (v & 0x80) {
                v = (v << 1) ^ arg1;
            } else {
                v = v << 1;
            }
        }
        *p = v;
    }
}
