#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    u32 unk0;
    u32 unk4;
    u32 hi : 2;
    u32 field : 2;
    u32 lo : 28;
};

extern "C" void fn_27_19EBC8(FieldHolder* obj, u32 value)
{
    obj->field = value;
}
