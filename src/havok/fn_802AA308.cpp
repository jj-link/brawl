#pragma force_active on
struct fn_802AA308_work {
    void* m0;
    int m4;
    unsigned int m8;
};

extern "C" void __ct__14Class_802A4DA4Fi(fn_802AA308_work* self, int value) {
    self->m0 = (char*)self + 0xC;
    self->m4 = value;
    self->m8 = 0x80000080;
}
