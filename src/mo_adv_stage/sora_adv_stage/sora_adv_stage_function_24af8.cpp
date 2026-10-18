#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_40_24AF8(void* p) {
    return (((u32*)p)[2] >> 25) & 1;
}
