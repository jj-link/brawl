#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct LucasObject {
    unsigned char padding0[0x14];
    s32 anchor;
    unsigned char padding1[0x18];
    u32* entries;
};

extern "C" u32 fn_114_15D70(
    LucasObject* object,
    void* unused,
    s32 index,
    s32 entryIndex
) {
    LucasObject* adjusted =
        (LucasObject*)((char*)object + (index - object->anchor) * 4);
    return adjusted->entries[entryIndex];
}
