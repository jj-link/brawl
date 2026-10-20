#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 hi : 4;
    u32 f : 2;
    u32 lo : 26;
};

extern "C" {
void fn_51_66D8(Obj* obj, u32 v)
{
    obj->f = v;
}
}
