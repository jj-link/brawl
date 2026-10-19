#pragma force_active on
typedef unsigned int u32;

extern "C" u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

struct DolpicResHolder
{
    unsigned char pad[0x40];
    u32 resFile;
};

extern "C" u32 fn_46_4860(DolpicResHolder* self)
{
    if (self->resFile != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->resFile);
    return 0;
}
