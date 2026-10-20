#pragma force_active on
typedef unsigned int u32;

typedef struct Obj {
    u32 unk0;
    u32 unk4;
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
} Obj;

extern "C" {
void fn_27_D14E4(Obj* obj, u32 val)
{
    obj->b = val;
}
}
