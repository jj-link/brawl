#pragma force_active on
extern "C" void fn_8015B230(void* self);

struct Obj {
    int m_0;
    int m_4;
    void* m_8;
    int m_c[6];
    unsigned int m_24;
};

extern "C" void fn_8015A358(Obj* self) {
    if (self->m_24 >> 31) {
        fn_8015B230(self->m_8);
        self->m_24 &= 0x7FFFFFFF;
    }
}
