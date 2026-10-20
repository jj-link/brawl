#pragma force_active on
typedef unsigned int u32;

struct fn_27_19DD54_Obj {
    char pad[8];
    u32 pre : 5;
    u32 field : 5;
    u32 post : 22;
};

extern "C" {
void fn_27_19DD54(struct fn_27_19DD54_Obj *obj, u32 value)
{
    obj->field = value;
}
}
