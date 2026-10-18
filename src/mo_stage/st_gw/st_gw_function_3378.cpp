#pragma force_active on
typedef unsigned int u32;

extern "C" u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

extern "C" u32 fn_63_3378(const char* self)
{
    if (*(u32*)(self + 0x40))
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(self + 0x40);
    return 0;
}
