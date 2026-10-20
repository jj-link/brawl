#pragma force_active on
typedef unsigned int u32;

struct BitfieldObj {
    u32 unk0;
    u32 unk4;
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_CAD20(BitfieldObj *obj, u32 val)
{
    obj->hi = val;
}
