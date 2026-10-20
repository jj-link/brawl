#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 4;
        u32 f : 4;
        u32 rest : 24;
    } unk8;
} Obj;

extern "C" void fn_27_19F6F0(Obj* obj, u32 v)
{
    obj->unk8.f = v;
}
