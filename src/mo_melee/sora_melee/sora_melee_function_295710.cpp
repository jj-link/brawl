#pragma force_active on
typedef unsigned int u32;

struct fn_27_295710_s {
    u32 unk0;
    u32 unk4;
    u32 bits : 5;
};

extern "C" {
void fn_27_295710(struct fn_27_295710_s *p, u32 v)
{
    p->bits = v;
}
}
