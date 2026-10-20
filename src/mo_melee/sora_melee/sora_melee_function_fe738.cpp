#pragma force_active on
struct FooFlags {
    unsigned char pad[8];
    unsigned int mode : 3;
};

extern "C" void fn_27_FE738(FooFlags *p, unsigned int v)
{
    p->mode = v;
}
