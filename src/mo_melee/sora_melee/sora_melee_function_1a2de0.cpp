#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 4;
        u32 b : 2;
        u32 c : 26;
    } unk8;
} FnObj;

extern "C" void fn_27_1A2DE0(FnObj *obj, u32 val)
{
    obj->unk8.b = val;
}
