#pragma force_active on
typedef int s32;

extern "C" s32 fn_27_351D5C(char* p, s32 unused, s32 a, s32 idx) {
    s32 off = (a - *(s32*)(p + 0x14)) * 4;
    s32* tbl = *(s32**)(p + off + 0x20);
    return tbl[idx];
}
