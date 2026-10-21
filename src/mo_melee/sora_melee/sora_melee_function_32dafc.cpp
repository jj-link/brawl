#pragma force_active on
extern "C" void fn_27_1E82E8(void* self, int arg);
extern "C" void fn_27_1E847C(void* self, int arg, void* other);
extern "C" void fn_27_32DB78(void* self);
extern "C" int __register_global_object(void* obj, void (*dtor)(void*), void* handle);

extern "C" unsigned char lbl_27_data_88700[];

struct soGlobalObj {
    unsigned char* m_ptr0;
    int m_pad4;
    unsigned char* m_ptr8;
};

extern "C" soGlobalObj lbl_27_bss_7D18;
extern "C" unsigned char lbl_27_bss_7D0C[];

extern "C" void fn_27_32DAFC() {
    fn_27_1E82E8(&lbl_27_bss_7D18, 0);
    lbl_27_bss_7D18.m_ptr8 = lbl_27_data_88700;
    lbl_27_bss_7D18.m_ptr0 = lbl_27_data_88700 + 8;
    fn_27_1E847C(&lbl_27_bss_7D18, 0x66, &lbl_27_bss_7D18);
    __register_global_object(&lbl_27_bss_7D18, (void (*)(void*))fn_27_32DB78, lbl_27_bss_7D0C);
}

__declspec(section ".ctors") extern void* const fn_27_32DAFC_ctor = (void*)fn_27_32DAFC;
