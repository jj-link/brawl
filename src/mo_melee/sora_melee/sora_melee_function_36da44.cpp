#pragma force_active on
typedef unsigned char u8;

struct soWorkObj {
    void* m_ptr;
    int m_pad4;
    void* m_data;
};

extern "C" void fn_27_1E82E8(soWorkObj*, int);
extern "C" void fn_27_1E847C(soWorkObj*, int, soWorkObj*);
extern "C" void fn_27_36DAC0(void*);
extern "C" void __register_global_object(void*, void*, void*);

extern "C" u8 lbl_27_data_926F8[];
extern soWorkObj lbl_27_bss_82F0;
extern u8 lbl_27_bss_82E4[];

extern "C" {
void fn_27_36DA44() {
    fn_27_1E82E8(&lbl_27_bss_82F0, 0);
    lbl_27_bss_82F0.m_data = lbl_27_data_926F8;
    lbl_27_bss_82F0.m_ptr = lbl_27_data_926F8 + 8;
    fn_27_1E847C(&lbl_27_bss_82F0, 13, &lbl_27_bss_82F0);
    __register_global_object(&lbl_27_bss_82F0, (void*)fn_27_36DAC0, lbl_27_bss_82E4);
}
}

__declspec(section ".ctors") extern void* const fn_27_36DA44_ctor = (void*)fn_27_36DA44;
