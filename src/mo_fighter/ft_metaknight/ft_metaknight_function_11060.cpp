#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

struct Fn11111060Object {
    u8 pad00[0x14];
    s32 index;
};

extern "C" u32 fn_111_11060(
    Fn11111060Object* object,
    u32 unused,
    s32 index,
    u32 subindex
) {
    u32* entries = (u32*)((u8*)object + (index - object->index) * 4 + 0x20);
    return ((u32*)*entries)[subindex];
}
