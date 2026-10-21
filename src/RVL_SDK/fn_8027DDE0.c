#pragma force_active on
typedef int s32;

s32 fn_8027DDE0(void *arg0, s32 arg1) {
    s32 val = *(s32 *)((char *)arg0 + 8);
    return (arg1 <= val) << 24;
}
