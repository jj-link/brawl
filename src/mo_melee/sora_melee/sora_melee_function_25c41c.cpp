#pragma force_active on
extern "C" {
struct FnObj_25C41C {
    char pad[0x48];
    unsigned int m_48;
    unsigned int m_4c;
};

void fn_27_25C41C(FnObj_25C41C* self) {
    self->m_4c = 0;
    self->m_48 = 9;
}
}
