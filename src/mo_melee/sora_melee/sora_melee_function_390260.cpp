#pragma force_active on
typedef unsigned int u32;

struct ObjFlags {
    u32 unk0;
    u32 unk4;
    u32 flags8;
};

extern "C" void fn_27_390260(ObjFlags* obj)
{
    obj->flags8 |= 0x00400000;
}
