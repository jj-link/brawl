#pragma force_active on
struct Holder
{
    char pad[0x40];
    unsigned int resFile;
};

extern "C" unsigned int GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void *);

extern "C" unsigned int fn_77_1004(const Holder *self)
{
    if (self->resFile != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->resFile);
    return 0;
}
