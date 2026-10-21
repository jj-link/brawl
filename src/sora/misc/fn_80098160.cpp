#pragma force_active on
struct Obj {
    char pad[0xE0];
    float a;
    float b;
    float c;
};

struct Outer {
    char pad[8];
    Obj** arr;
};

struct Src {
    float x;
    float y;
    float z;
};

extern "C" void fn_80098160(Outer* o, int i, const Src* s)
{
    Obj* p = o->arr[i];
    p->a = s->x;
    p->b = s->y;
    p->c = s->z;
}
