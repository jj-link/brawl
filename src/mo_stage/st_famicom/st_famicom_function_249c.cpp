#pragma force_active on
extern "C" unsigned int GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

struct Ground
{
    unsigned char pad[0x40];
    unsigned int resFile;

    unsigned int getModelCount();
};

extern "C" unsigned int fn_68_249C(Ground* self)
{
    if (self->resFile != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->resFile);
    return 0;
}
