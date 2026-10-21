#pragma force_active on
struct fn_27_2DB9BC_obj {
    void* m0;
    void* m4;
    void* m8;
};

extern "C" void fn_802DB9BC(fn_27_2DB9BC_obj* self, void* value)
{
    self->m0 = (char*)self + 0xc;
    self->m4 = value;
    self->m8 = (void*)0x80000020;
}
