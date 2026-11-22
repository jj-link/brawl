#include <types.h>
#pragma force_active on

extern "C" void fn_801EC184(void*, void*);

extern "C" void* fn_80190EC8(u32 srcPtr, void* dst) {
    void* src = *(void**)srcPtr;
    float* srcFloats = (float*)((char*)src + 8);
    u8* srcBytes = (u8*)((char*)src + 0xa8);
    float* dstFloats = (float*)((char*)dst + 8);
    u8* dstBytes = (u8*)((char*)dst + 0xa8);
    void* d = dst;
    srcPtr = *(u32*)src;
    *(u32*)dst = srcPtr;
    *(u32*)((char*)dst + 4) = *(u32*)((char*)src + 4);
    while (srcPtr != 0) {
        if (srcPtr & 0xF) {
            dstFloats[0] = srcFloats[0];
            dstFloats[1] = srcFloats[1];
            dstFloats[2] = srcFloats[2];
            dstFloats[3] = srcFloats[3];
            dstFloats[4] = srcFloats[4];
            dstBytes[0] = srcBytes[0];
            dstBytes[1] = srcBytes[1];
            dstBytes[2] = srcBytes[2];
            dstBytes[3] = srcBytes[3];
            fn_801EC184(srcBytes + 4, dstBytes + 4);
        }
        srcPtr >>= 4;
        srcFloats += 5;
        srcBytes += 0x34;
        dstFloats += 5;
        dstBytes += 0x34;
    }
    return d;
}
