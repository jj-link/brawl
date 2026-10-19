#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_47_4248(void*);
void fn_47_4258(void*);
extern char lbl_47_data_1E10[];
}

struct St47Obj {
    char m_00[0x28];
    void* m_28;
    void* m_2c;
    unsigned int m_30;
    char m_34[0x30];
};

extern "C" St47Obj* fn_47_3FB8(St47Obj* self) {
    self->m_28 = lbl_47_data_1E10;
    self->m_2c = lbl_47_data_1E10 + 0x48;
    self->m_30 &= 0x7FFFF;
    __construct_array(self->m_34, (void (*)(void*))fn_47_4248, (void (*)(void*))fn_47_4258, 8, 6);
    return self;
}
