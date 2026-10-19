#pragma force_active on
struct Obj {
    int a;
    int b;
    char *ptr;
    int count;
};

extern "C" {
int fn_113_24338(Obj *o)
{
    signed char v = *(signed char *)(o->ptr + o->count * 12 + 9);
    return !(v < 0);
}
}
