#pragma force_active on

extern "C" void fn_71_9E94(void *p, unsigned int v)
{
    struct Bits {
        unsigned int a : 2;
        unsigned int b : 30;
    };
    struct Bits *s = (struct Bits *)((char *)p + 8);
    s->a = v;
}
