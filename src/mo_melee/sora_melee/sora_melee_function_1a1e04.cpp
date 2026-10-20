#pragma force_active on
typedef unsigned int u32;

struct fnS27_1A1E04 {
    void* m_vtbl0;
    void* m_vtbl1;
    u32 m_flags;
    u32 m_arr[1];
};

extern "C" char lbl_27_data_3EF48[];
extern "C" void fn_27_D2A0C(void* p);
extern "C" void* fn_27_AB510(void* p, int n);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

extern "C" fnS27_1A1E04* fn_27_1A1E04(fnS27_1A1E04* p) {
    p->m_vtbl0 = lbl_27_data_3EF48;
    p->m_vtbl1 = lbl_27_data_3EF48 + 0x48;
    p->m_flags &= 0x7FFFF;
    __construct_array((char*)p + 0xc, (void (*)(void*))fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 6);
    return p;
}
