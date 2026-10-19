#pragma force_active on
typedef unsigned int u32;

struct Fn42Object
{
    unsigned char pad[0x40];
    u32 resFile;
};

extern "C" u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void *);

extern "C" u32 fn_42_79C(Fn42Object *self)
{
    if (self->resFile != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->resFile);
    return 0;
}
