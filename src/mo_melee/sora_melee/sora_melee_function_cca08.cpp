#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_CCA08(void* p) {
    u32 v = ((u32*)p)[2];
    s32 t = (s32)(((v >> 27) & 7u) << 29);
    return t >> 30;
}
}
