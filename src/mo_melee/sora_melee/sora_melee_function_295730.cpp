#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    char pad[8];
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

extern "C" void fn_27_295730(FieldHolder* p, u32 v)
{
    p->b = v;
}
