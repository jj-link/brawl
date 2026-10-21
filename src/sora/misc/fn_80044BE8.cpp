#pragma force_active on
extern int lbl_805A00C0;

struct fn_80044BE8_work {
    char pad[0x14];
    int m14;
    void *m18;
};

extern "C" void fn_80044BE8(fn_80044BE8_work *self)
{
    self->m14 = 0;
    self->m18 = &lbl_805A00C0;
}
