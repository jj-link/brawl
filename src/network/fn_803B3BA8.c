#pragma force_active on
typedef unsigned short u16;
typedef short s16;
typedef unsigned char u8;

void fn_803C2EA4(u16 *a, u16 *b);

u8 fn_803B3BA8(s16 *arg0, s16 *arg1) {
    u16 a[3];
    u16 b[4];

    fn_803C2EA4(a, b);
    *arg0 = (((a[0] - 0x7BC) << 9) & 0xFE00) | ((a[1] << 5) & 0x1E0) | (a[2] & 0x1F);
    *arg1 = (((b[0] << 11) & 0xF800) | ((b[1] << 5) & 0x7E0) | ((b[2] >> 1) & 0x1F));
    return (u8)b[3];
}
