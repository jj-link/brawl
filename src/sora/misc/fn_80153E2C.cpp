#pragma force_active on
struct FnObj_80153E2C {
    char pad[0xB4];
    void *m_b4;
    void *m_b8;
};

extern "C" void fn_80153E2C(FnObj_80153E2C *self, void *value) {
    self->m_b8 = value;
    self->m_b4 = 0;
}
