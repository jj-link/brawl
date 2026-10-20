#pragma force_active on
typedef unsigned int u32;

struct BitfieldObj {
    u32 unk0;
    u32 unk4;
    u32 field : 5;
};

extern "C" {
void fn_27_1CFD44(BitfieldObj* obj, u32 value)
{
    obj->field = value;
}
}
