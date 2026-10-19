#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_54_5BDC(void*);
void fn_54_5BEC(void*);
extern char lbl_54_data_20C0[];
}

struct StNorfairObj {
    char pad[0x28];
    void* m_28;
    void* m_2c;
    unsigned long m_30;
};

extern "C" StNorfairObj* fn_54_594C(StNorfairObj* self) {
    char* base = lbl_54_data_20C0;
    self->m_28 = base;
    self->m_2c = base + 0x48;
    self->m_30 &= 0x7FFFF;
    __construct_array((char*)self + 0x34, fn_54_5BDC, fn_54_5BEC, 8, 6);
    return self;
}
