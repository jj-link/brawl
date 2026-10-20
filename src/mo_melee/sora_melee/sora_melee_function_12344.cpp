#pragma force_active on
typedef struct Pair {
    void *a;
    void *b;
} Pair;

typedef struct Outer {
    char pad[0x2c];
    Pair *p;
} Outer;

extern "C" void fn_27_12344(Outer *o, unsigned char v)
{
    Pair *p = o->p;
    unsigned char *a = (unsigned char *)p->a;
    a[0x65] = v;
    a[0x40] = 1;
    unsigned char *b = (unsigned char *)p->b;
    b[0x65] = v;
    b[0x40] = 1;
}
