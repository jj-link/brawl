#pragma force_active on
typedef struct Obj
{
    char pad0[0x51c];
    void *f51c;
    char pad1[4];
    void *f524;
} Obj;

extern "C" void fn_50_5B3C(Obj *self, void *a, void *b)
{
    self->f51c = a;
    self->f524 = b;
}
