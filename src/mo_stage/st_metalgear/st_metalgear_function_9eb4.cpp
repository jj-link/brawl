#pragma force_active on
extern "C" void fn_71_9EB4(void *p, unsigned int v)
{
    struct Bits {
        unsigned int a : 2;
        unsigned int b : 2;
        unsigned int c : 28;
    };
    struct Bits *s = (struct Bits *)((char *)p + 8);
    s->b = v;
}
