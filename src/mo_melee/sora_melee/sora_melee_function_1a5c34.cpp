#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int a : 10;
    unsigned int f : 10;
    unsigned int b : 12;
};

extern "C" void fn_27_1A5C34(Obj* self, unsigned int v)
{
    self->f = v;
}
