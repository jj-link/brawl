#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* fn_40_288D8(void* base, int index) {
    return (u8*)base + index * 0x90 + 0xc;
}
}
