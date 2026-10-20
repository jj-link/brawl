#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" u32 fn_27_19A2A8(const u8* self) {
    u32 val = *(const u32*)(self + 8);
    return (val >> 16) & 1;
}
