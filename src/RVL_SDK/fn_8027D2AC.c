#pragma force_active on
typedef signed int s32;

s32 fn_8027D2AC(void *arg0, s32 arg1) {
    s32 v = *(s32 *)((char *)arg0 + 8);
    return (arg1 <= v) << 24;
}
