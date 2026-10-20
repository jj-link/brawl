#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 a : 2;
    u32 b : 30;
};

extern "C" {
void fn_27_1E7BC0(Obj* self, u32 v)
{
    self->a = v;
}
}
