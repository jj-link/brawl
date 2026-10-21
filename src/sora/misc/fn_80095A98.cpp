#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" void fn_80095A98(void* obj) {
    u32 off;
    s32 i;
    for (i = 0, off = 0; i < *(s32*)((u8*)obj + 4); i++, off += 4) {
        ((u8*)*(void**)((u8*)*(void**)obj + off))[0x1C4] = 0;
    }
    ((u8*)obj)[0x5C] = 0;
}
