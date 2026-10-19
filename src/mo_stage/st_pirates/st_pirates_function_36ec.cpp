#pragma force_active on
typedef unsigned int u32;

extern "C" u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

struct PiratesResource {
    unsigned char padding[0x40];
    void* resFile;
};

extern "C" u32 fn_52_36EC(const PiratesResource* self)
{
    if (self->resFile != 0) {
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->resFile);
    }
    return 0;
}
