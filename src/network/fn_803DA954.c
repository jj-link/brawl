#pragma force_active on
typedef int s32;

extern s32 fn_803DA220(void *, s32);

s32 fn_803DA954(void *arg0) {
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3_2 = fn_803DA220(arg0, *(s32 *)((char *)arg0 + 0x1630));
    if (temp_r3_2 != 0) {
        return temp_r3_2;
    }
    temp_r3 = fn_803DA220(arg0, *(s32 *)((char *)arg0 + 0x1634));
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 0x1F);
}
