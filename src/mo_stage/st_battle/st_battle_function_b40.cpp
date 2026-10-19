#pragma force_active on
struct ResObject
{
    unsigned char padding[0x40];
    unsigned int file;
};

extern "C" unsigned int GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

extern "C" unsigned int fn_43_B40(ResObject* self)
{
    if (self->file != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->file);
    return 0;
}
