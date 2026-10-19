#pragma force_active on
struct Ground
{
    unsigned char pad[0x40];
    unsigned long resFile;
};

extern "C" unsigned long GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

extern "C" unsigned long fn_79_1B64(Ground* self)
{
    if (self->resFile != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->resFile);
    return 0;
}
