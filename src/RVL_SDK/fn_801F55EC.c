#pragma force_active on
#pragma peephole off
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct GXData { u16 pad; u16 dirty; } GXData;
extern GXData* const __GXData;
void fn_801F55EC(u32 arg0) {
    *(u8*)0xCC008000 = 0x10;
    *(u32*)0xCC008000 = 0x1005;
    *(u32*)0xCC008000 = arg0;
    __GXData->dirty = 1;
}