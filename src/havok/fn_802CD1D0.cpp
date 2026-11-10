#include <types.h>
#pragma force_active on
#pragma global_optimizer off
extern "C" int fn_802CD1D0(void* p, int a, int b) {
    u32 word;
    u32 mask;
    u32 result;
    if (((a ^ b) & 0xFFFF0000) == 0 && (a & 0xFFFF0000) != 0) {
        if (((a >> 5) & 0x1F) == ((b >> 10) & 0x1F)) return 0;
        if (((b >> 5) & 0x1F) == ((a >> 10) & 0x1F)) return 0;
        return 0x01000000;
    }
    word = *(u32*)((char*)p + ((a & 0x1F) << 2) + 0x1C);
    mask = 1 << (b & 0x1F);
    result = word & mask;
    return ((-result | result) >> 7) & 0x01000000;
}