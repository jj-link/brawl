#pragma force_active on
struct Fn154C4CObj {
    unsigned char pad0[0x36c];
    unsigned char a;
    unsigned char pad1[7];
    unsigned char b;
    unsigned char pad2[3];
    void *ptr;
};

extern "C" {
void fn_80154C4C(Fn154C4CObj *self, void *p)
{
    self->ptr = p;
    self->b = 1;
    self->a = 1;
}
}
