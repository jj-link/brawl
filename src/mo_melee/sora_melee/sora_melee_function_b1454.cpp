#pragma force_active on
struct Fn27B1454Obj {
    void *ptr;
    unsigned char pad[0x1c - 4];
    unsigned char a;
    unsigned char b;
};

extern "C" {
void fn_27_B1454(Fn27B1454Obj *self, void *p)
{
    self->ptr = p;
    self->a = 0;
    self->b = 0;
}
}
