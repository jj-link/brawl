#pragma force_active on
struct Src {
    char pad0[0xC];
    float a;
    char pad1[0xC];
    float b;
    char pad2[0xC];
    float c;
};

struct Dst {
    float x;
    float y;
    float z;
};

extern "C" void fn_8016F6F8(Src* s, Dst* d)
{
    float c;
    float b;
    float a;
    a = s->a;
    b = s->b;
    c = s->c;
    d->x = a;
    d->y = b;
    d->z = c;
}
