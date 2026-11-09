#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern int fn_803BE78C(u8* dst, const u8* src, int flags);

u8 fn_803B29D8(u8* arg0) {
    u8 buf[24];
    u8 sum;
    u16 i;
    fn_803BE78C(buf, arg0 + 0x20E, 0);
    sum = 0;
    for (i = 0; i < 11; i++) {
        sum = (u8)((sum >> 1) + ((sum & 1) ? 0x80 : 0) + buf[i]);
    }
    return sum;
}
