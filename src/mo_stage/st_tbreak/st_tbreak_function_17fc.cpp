#pragma force_active on
typedef unsigned int u32;

struct Object {
    unsigned char pad[0x40];
    u32 field;
};

extern "C" u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void *);

extern "C" u32 fn_89_17FC(Object *self)
{
    if (self->field != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->field);
    return 0;
}
