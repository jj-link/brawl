#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Fn11B964Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" {
void fn_27_11B964(Fn11B964Obj* obj)
{
    obj->flags |= 0x10000;
}
}
