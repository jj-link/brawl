#pragma force_active on
extern "C" void fn_8008B00C(void* p, int arg);
extern "C" void fn_8008ACE8(void* p, int arg);
extern "C" void fn_80096774(void* p, int arg);

struct Fn27Obj {
    char pad[0x28];
    void* m_28;
    void* m_2c;
    void* m_30;
};

extern "C" void fn_27_10914(Fn27Obj* self) {
    if (self->m_28 != 0) {
        fn_8008B00C(self->m_28, 1);
        self->m_28 = 0;
    }
    if (self->m_2c != 0) {
        fn_8008ACE8(self->m_2c, 1);
        self->m_2c = 0;
    }
    if (self->m_30 != 0) {
        fn_80096774(self->m_30, 1);
        self->m_30 = 0;
    }
}
