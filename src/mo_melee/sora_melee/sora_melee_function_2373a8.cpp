#pragma force_active on
struct Obj {
    char pad[0xc];
    void *sub;
    float f;
};

extern "C" {
void fn_27_26ECCC(void *sub, float f);

void fn_27_2373A8(Obj *self)
{
    fn_27_26ECCC(self->sub, self->f);
}
}
