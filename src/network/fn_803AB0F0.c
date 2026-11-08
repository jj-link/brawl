#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
int fn_803AB0F0(u32 *a, u8 *b) {
    if (b == 0 || a == 0) return 1;
    b[0] = 0x52;
    b[1] = 0x52;
    b[2] = 0x61;
    b[3] = 0x41;
    b[0x1e4] = 0x72;
    b[0x1e5] = 0x72;
    b[0x1e6] = 0x41;
    b[0x1e7] = 0x61;
    b[0x1e8] = a[0];
    b[0x1e9] = (u8)(a[0] >> 8);
    b[0x1ea] = (u8)(a[0] >> 16);
    b[0x1eb] = a[0] >> 24;
    b[0x1ec] = a[1];
    b[0x1ed] = (u8)(a[1] >> 8);
    b[0x1ee] = (u8)(a[1] >> 16);
    b[0x1ef] = a[1] >> 24;
    b[0x1fc] = 0;
    b[0x1fd] = 0;
    b[0x1fe] = 0x55;
    b[0x1ff] = 0xaa;
    return 0;
}