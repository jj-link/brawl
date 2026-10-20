#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    u32 unk0;
    u32 unk4;
    u32 hi : 14;
    u32 field : 7;
    u32 lo : 11;
};

extern "C" {
void fn_27_1D02E8(FieldHolder* obj, u32 value)
{
    obj->field = value;
}
}
