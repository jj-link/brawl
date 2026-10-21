#pragma force_active on
typedef unsigned char u8;

void fn_8020B2F8(u8 *arg0, unsigned long arg1, unsigned long arg2, unsigned long arg3) {
    int var_r7;

    var_r7 = 0;
    if (arg1 & 1) {
        var_r7 |= 0x10;
    }
    if (arg1 & 2) {
        var_r7 |= 0x20;
    }
    if (arg2 & 1) {
        var_r7 |= 0x4;
    }
    if (arg2 & 2) {
        var_r7 |= 0x8;
    }
    if (arg3 & 1) {
        var_r7 |= 0x1;
    }
    if (arg3 & 2) {
        var_r7 |= 0x2;
    }
    *arg0 = (u8)var_r7;
}
