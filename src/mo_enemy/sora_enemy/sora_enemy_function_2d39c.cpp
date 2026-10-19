#pragma force_active on
struct Inner {
    char pad[0x2208];
    int f2208;
};

struct Outer {
    char pad[0x18];
    unsigned char f18;
    char pad2[3];
    Inner *f1c;
};

extern "C" {
void fn_41_2D39C(Outer *p)
{
    if (p->f1c != 0) {
        p->f1c->f2208 = 0;
        p->f1c = 0;
    }
    p->f18 = 0;
}
}
