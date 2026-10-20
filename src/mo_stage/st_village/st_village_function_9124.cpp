#pragma force_active on
struct Bits {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int f : 2;
    unsigned int rest : 28;
};

extern "C" void fn_70_9124(void *obj, unsigned int v)
{
    struct Bits *w = (struct Bits *)((char *)obj + 8);
    w->f = v;
}
