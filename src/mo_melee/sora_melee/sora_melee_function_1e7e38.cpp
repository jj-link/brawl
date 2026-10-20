#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 top : 4;
    u32 f : 4;
    u32 rest : 24;
};

extern "C" void fn_27_1E7E38(S *self, u32 val)
{
    self->f = val;
}
