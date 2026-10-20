#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 a : 10;
    u32 f : 5;
    u32 b : 17;
};

extern "C" {
void fn_27_296084(Obj* self, u32 v)
{
    self->f = v;
}
}
