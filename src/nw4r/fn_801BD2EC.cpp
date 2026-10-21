#pragma force_active on
extern "C" void fn_801CAF90(int a, void* b);
extern "C" void fn_801CAEC4(int a, void* b);

struct Obj {
    char m_pad[0x10];
    int m_0x10;
    char m_pad2[0x60];
    char m_0x74;
};

extern "C" void fn_801BD2EC(Obj* self, char arg1) {
    int val = self->m_0x10;
    self->m_0x74 = arg1;
    if (val != 0) {
        fn_801CAF90(val, self);
        fn_801CAEC4(self->m_0x10, self);
    }
}
