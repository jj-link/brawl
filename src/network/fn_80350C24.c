#pragma force_active on
typedef unsigned int u32;

void fn_80350C24(u32 *arg0, u32 unused, u32 arg2, u32 arg3) {
    if (!(arg2 & 0xFFFFF800)) {
        arg0[0] = (arg0[0] & 0xFFFFF800) | arg2;
    }
    arg0[1] = arg3;
}
