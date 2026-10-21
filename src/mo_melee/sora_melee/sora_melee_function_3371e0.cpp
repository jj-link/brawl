#include <types.h>
#pragma force_active on

extern "C" void __register_global_object(void* obj, void (*dtor)(void*), void* dso);

class fnStaticObj {
public:
    fnStaticObj();
    void* m_vptr;
    int m_pad;
    void* m_data;
};

extern "C" void fn_27_1E82E8(fnStaticObj*, int);
extern "C" void fn_27_1E847C(fnStaticObj*, int, fnStaticObj*);
extern "C" void fn_27_33725C(void*);

extern fnStaticObj lbl_27_bss_7DAC;
extern char lbl_27_bss_7DA0[12];
extern char lbl_27_data_8A1E0[24];

extern "C" {
void fn_27_3371E0() {
    fn_27_1E82E8(&lbl_27_bss_7DAC, 0);
    lbl_27_bss_7DAC.m_vptr = lbl_27_data_8A1E0 + 8;
    lbl_27_bss_7DAC.m_data = lbl_27_data_8A1E0;
    fn_27_1E847C(&lbl_27_bss_7DAC, 0x5d, &lbl_27_bss_7DAC);
    __register_global_object(&lbl_27_bss_7DAC, (void (*)(void*))fn_27_33725C, lbl_27_bss_7DA0);
}
}

__declspec(section ".ctors") extern void* const fn_27_3371E0_ctor = (void*)fn_27_3371E0;
