#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern s32 fn_80397664(void *arg0, u32 arg1);

s32 fn_80399EE0(void *arg0, u32 arg1, u32 arg2) {
    s32 temp;
    s32 result;

    if (arg0 == 0) {
        return -5;
    }
    temp = fn_80397664(arg0, arg2 + 1);
    if (temp == 0) {
        return -5;
    }
    if ((u32) temp > arg2) {
        return -6;
    }
    result = 0;
    if ((u32) temp < arg1) {
        result = -0x18;
    }
    return result;
}
