#pragma force_active on
struct Elem {
    unsigned int flags;
    unsigned int pad[2];
    float a;
    float b;
    unsigned char rest[0x2c - 0x14];
};

struct Obj {
    unsigned char pad[0x20];
    Elem *arr;
};

extern "C" void fn_27_238838(Obj *self, int idx, float f1, float f2)
{
    if (f1 != self->arr[idx].a | f2 != self->arr[idx].b) {
        self->arr[idx].flags |= 2;
        self->arr[idx].a = f1;
        self->arr[idx].b = f2;
    }
}
