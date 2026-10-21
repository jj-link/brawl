#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
u32 fn_802E1E50(char* self, s32 idx)
{
    s32 n = *(s32*)(self + 0x70);
    if (idx < n) {
        return *(u32*)(*(char**)(self + 0x6c) + idx * 0x24);
    }
    return *(u32*)(*(char**)(self + 0x78) + (idx - n) * 4);
}
}
