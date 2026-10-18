#pragma force_active on
struct fn_27_2322C4_Obj {
    void* pad[0x13];
    void** m_4c;
    int m_50;
};

extern "C" void fn_27_2322C4(fn_27_2322C4_Obj* self, void* p) {
    self->m_4c[self->m_50] = p;
    self->m_50 = self->m_50 + 1;
}
