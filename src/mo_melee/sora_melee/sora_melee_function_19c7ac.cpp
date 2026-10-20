#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_19C920(void*);
void* fn_27_86D8C(void*, int);
char lbl_27_data_3D6A0[];
}

struct Element {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
};

struct S {
    void* m_data;
    void* m_data2;
    int m_flags;
    Element m_array[1];
};

extern "C" S* fn_27_19C7AC(S* self) {
    self->m_data = lbl_27_data_3D6A0;
    self->m_data2 = lbl_27_data_3D6A0 + 0x48;
    self->m_flags &= 0x01FFFFFF;
    __construct_array(self->m_array, (void (*)(void*))fn_27_19C920, (void (*)(void*))fn_27_86D8C, 0x14, 1);
    return self;
}
