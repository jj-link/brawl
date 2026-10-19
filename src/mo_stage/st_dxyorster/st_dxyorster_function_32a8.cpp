#pragma force_active on
extern "C" char lbl_76_data_1DB8[];
extern "C" void fn_76_33AC(void*);
extern "C" void fn_76_33BC(void*);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

class St {
public:
    char _00[0x28];
    void* m_28;
    void* m_2c;
    unsigned int m_30;
};

extern "C" St* fn_76_32A8(St* self) {
    self->m_28 = lbl_76_data_1DB8;
    self->m_2c = lbl_76_data_1DB8 + 0x48;
    self->m_30 &= 0x7FFFF;
    __construct_array((char*)self + 0x34, fn_76_33AC, fn_76_33BC, 8, 6);
    return self;
}
