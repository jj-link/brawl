#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" char lbl_27_data_3C578[];
extern "C" void fn_27_D2A0C(void*);
extern "C" void* fn_27_AB510(void* p, s32 n);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

struct fnS27282964 {
    void* m_0;
    void* m_4;
    u32 m_8;
};

extern "C" {
fnS27282964* fn_27_282964(fnS27282964* p) {
    p->m_0 = lbl_27_data_3C578;
    p->m_4 = lbl_27_data_3C578 + 0x48;
    p->m_8 &= 0x003FFFFF;
    __construct_array((char*)p + 0xc, (void (*)(void*))fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 2);
    return p;
}
}
