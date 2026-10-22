#pragma force_active on
extern "C" unsigned char fn_800C8548(void);

extern "C" unsigned int fn_800D904C(int arg0, int arg1) {
    unsigned char temp_r3;
    unsigned char temp_r4;
    unsigned int var_r0;
    unsigned char *base;

    temp_r3 = fn_800C8548();
    if (temp_r3 == 0xFF) {
        var_r0 = 0;
    } else {
        var_r0 = arg0 + (temp_r3 * 0x218) + 0x70;
    }
    if (var_r0 == 0) {
        return 1;
    }
    base = (unsigned char *)arg0 + arg1;
    temp_r4 = base[0xFEF];
    return ((unsigned int)((0xFF - temp_r4) | (temp_r4 - 0xFF))) >> 31;
}
