#pragma force_active on
#include <types.h>

extern "C" void free__13gfHeapManagerFPv(void*);
extern "C" u32 NETCalcCRC32(void* p, s32 size);

extern "C" s32 fn_80153504(u8* arg0, u8* arg1) {
    if (arg0[4] != 0) {
        void* p = *(void**)arg0;
        if (p != 0) free__13gfHeapManagerFPv(p);
    }
    arg0[4] = 0;
    *(u32*)arg0 = 0;
    s32 v = 0;
    if (arg1 == 0) {
        v = 0;
    } else {
        if (arg1[0x17] != 0xdb) {
            v = 0;
        } else if (arg1[0x15] >= 4) {
            v = 0;
        } else if (arg1[0x16] >= 4) {
            v = 0;
        } else {
            u32 size = *(u32*)(arg1 + 0x1C);
            if (size >= 0x80000) {
                v = 0;
            } else {
                u32 old = *(u32*)(arg1 + 0x10);
                *(u32*)(arg1 + 0x10) = 0xDEADBEEF;
                u32 crc = NETCalcCRC32(arg1, (s32)(size + 0x20));
                *(u32*)(arg1 + 0x10) = old;
                v = (s32)((u32)__cntlzw(crc - old) >> 5);
            }
        }
    }
    if (v == 0) return 0;
    *(void**)arg0 = arg1;
    return 1;
}