#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" s32 fn_27_198B00(Obj* self)
{
    return (s32)((self->flags & 0x0F800000) << 4) >> 28;
}
