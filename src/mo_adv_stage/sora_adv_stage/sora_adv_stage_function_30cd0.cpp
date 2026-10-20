#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_40_30CD0(void* p) {
    u32 x = *(u32*)((char*)p + 8);
    return ((int)((x << 10) & 0xFC000000u)) >> 27;
}
}
