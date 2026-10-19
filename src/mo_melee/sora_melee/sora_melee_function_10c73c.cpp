#pragma force_active on
extern "C" {
    extern void* g_GameGlobal;
    unsigned int fn_8004E96C(void* p);
    void fn_27_145140(void* p);
    void fn_27_11A4C4(void* p);
}

struct fn_27_Obj {
    char pad[0x154];
    void* m_154;
    void* m_158;
    void* m_15c;
};

extern "C" void fn_27_10C73C(fn_27_Obj* self) {
    if (fn_8004E96C(g_GameGlobal) == 1) {
        fn_27_145140(self->m_15c);
        fn_27_11A4C4(self->m_154);
    }
}
