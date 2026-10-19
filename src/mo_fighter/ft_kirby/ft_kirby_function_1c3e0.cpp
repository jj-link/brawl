#pragma force_active on
extern "C" {
extern char lbl_96_data_BE54[];
extern void fn_27_C4134(void*);
extern void fn_27_C4160(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct FtKirbyObj {
    void* m_0;
    char* m_4;
    unsigned int m_8;
    char m_c[1];
};

extern "C" FtKirbyObj* fn_96_1C3E0(FtKirbyObj* self) {
    self->m_0 = lbl_96_data_BE54;
    self->m_4 = lbl_96_data_BE54 + 0x48;
    self->m_8 &= 0x7FFFF;
    __construct_array(self->m_c, fn_27_C4134, fn_27_C4160, 0x60, 4);
    return self;
}
