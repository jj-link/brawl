#pragma force_active on
struct ResFileProbe
{
    unsigned char pad[0x40];
    unsigned int data;
};

extern "C" unsigned int GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

extern "C" unsigned int fn_78_26A4(const void* self)
{
    if (((const ResFileProbe*)self)->data != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv((const char*)self + 0x40);
    return 0;
}
