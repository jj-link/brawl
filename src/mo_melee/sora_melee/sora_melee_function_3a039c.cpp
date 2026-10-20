#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
u32 fn_27_3A039C(char* p, s32 unused, s32 a, s32 idx) {
    s32 off = *(s32*)(p + 0x14);
    s32 i = a - off;
    char* q = p + i * 4;
    u32* arr = *(u32**)(q + 0x5c);
    return arr[idx];
}
}
