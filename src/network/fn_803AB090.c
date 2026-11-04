#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

int fn_803AB090(u8 *arg0, u32 *arg1) {
    if (arg0 == 0 || arg1 == 0) {
        return 1;
    }
    arg1[0] = arg0[0x1E8] | (arg0[0x1E9] << 8) | (arg0[0x1EA] << 16) | (arg0[0x1EB] << 24);
    arg1[1] = arg0[0x1EC] | (arg0[0x1ED] << 8) | (arg0[0x1EE] << 16) | (arg0[0x1EF] << 24);
    return 0;
}
