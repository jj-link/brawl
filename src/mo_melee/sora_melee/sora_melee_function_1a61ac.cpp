#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    char pad[8];
    u32 a : 20;
    u32 b : 10;
    u32 c : 2;
};

extern "C" {
void fn_27_1A61AC(struct FieldHolder *p, u32 v)
{
    p->b = v;
}
}
