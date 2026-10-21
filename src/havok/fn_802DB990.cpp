#pragma force_active on
struct fn_802DB990_work {
    void* m0;
    void* m4;
    unsigned int m8;
};

extern "C" void fn_802DB990(fn_802DB990_work* self, void* value)
{
    self->m0 = (char*)self + 0xc;
    self->m4 = value;
    self->m8 = 0x80000020;
}
