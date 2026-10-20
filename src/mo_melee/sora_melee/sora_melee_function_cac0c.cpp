#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 hi : 12;
    u32 f : 6;
    u32 lo : 14;
} FnObj;

extern "C" {
void fn_27_CAC0C(FnObj *obj, u32 value)
{
    obj->f = value;
}
}
