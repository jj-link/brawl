#pragma force_active on
typedef int s32;

s32 fn_803D620C(s32 arg0) {
    if (arg0 >= 0x61) {
        if (arg0 <= 0x7A) {
            return arg0 - 0x20;
        }
    }
    return arg0;
}
