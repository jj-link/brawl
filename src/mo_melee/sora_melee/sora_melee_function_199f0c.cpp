#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    u32 unk0;
    u32 unk4;
    u32 hi : 8;
    u32 f : 4;
    u32 lo : 20;
};

extern "C" {
void fn_27_199F0C(FieldHolder* p, u32 v)
{
    p->f = v;
}
}
