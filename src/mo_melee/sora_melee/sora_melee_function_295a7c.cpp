#pragma force_active on
typedef int s32;

extern "C" s32 fn_27_295A7C(void *p) {
    s32 v = *(s32 *)((char *)p + 8);
    return (s32)((v << 8) & 0xF8000000) >> 28;
}
