#pragma force_active on
extern "C" void fn_10_1D4A8(void* self);

struct Obj {
    int m_0;
    void* m_4;
};

extern "C" void fn_10_1DE50(Obj* self) {
    if (self->m_4 != 0) {
        fn_10_1D4A8(self);
        self->m_4 = 0;
    }
}
