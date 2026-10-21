#pragma force_active on
extern "C" void fn_801A12AC(unsigned int);
extern "C" void fn_801ACDB0(void*);
extern "C" void fn_801ACE24(void*);

struct Self {
    char pad[0x48];
    void* m_0x48;
};

extern "C" void fn_800B0858(Self* self) {
    fn_801A12AC(0x7FF);
    if (self->m_0x48) {
        fn_801ACDB0(self->m_0x48);
        fn_801ACE24(self->m_0x48);
    }
}
