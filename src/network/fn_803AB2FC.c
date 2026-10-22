#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

s32 fn_803AB2FC(u8 *arg0, s32 *arg1) {
    u32 a;
    u32 b;
    u32 c;

    if (arg0 == 0 || arg1 == 0) {
        return 1;
    }
    a = arg0[0] | (arg0[1] << 8) | (arg0[2] << 16) | (arg0[3] << 24);
    b = arg0[0x1E4] | (arg0[0x1E5] << 8) | (arg0[0x1E6] << 16) | (arg0[0x1E7] << 24);
    c = arg0[0x1FC] | (arg0[0x1FD] << 8) | (arg0[0x1FE] << 16) | (arg0[0x1FF] << 24);
    if (a == 0x41615252 && b == 0x61417272 && c == 0xAA550000) {
        *arg1 = 1;
    } else {
        *arg1 = 0;
    }
    return 0;
}
