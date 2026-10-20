#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    char pad[8];
    u32 hi : 6;
    u32 fld : 6;
    u32 lo : 20;
};

extern "C" {
void fn_27_CF834(struct FieldHolder *obj, u32 value)
{
    obj->fld = value;
}
}
