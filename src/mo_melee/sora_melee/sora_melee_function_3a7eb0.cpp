#pragma force_active on
extern "C" void fn_27_1E82E8(void* self, int flag);
extern "C" void fn_27_1E847C(void* self, int size, void* arg);
extern "C" void* fn_27_3A7F2C(void* self, int flag);
extern "C" void __register_global_object(void* obj, void* dtor, void* handle);

extern char lbl_27_data_9DA28[];
extern void* lbl_27_bss_8AB8[3];
extern char lbl_27_bss_8AAC[];

extern "C" void fn_27_3A7EB0() {
    fn_27_1E82E8(lbl_27_bss_8AB8, 0);
    lbl_27_bss_8AB8[2] = lbl_27_data_9DA28;
    lbl_27_bss_8AB8[0] = lbl_27_data_9DA28 + 8;
    fn_27_1E847C(lbl_27_bss_8AB8, 0x8b, lbl_27_bss_8AB8);
    __register_global_object(lbl_27_bss_8AB8, (void*)fn_27_3A7F2C, lbl_27_bss_8AAC);
}

__declspec(section ".ctors") extern void* const fn_27_3A7EB0_ctor = (void*)fn_27_3A7EB0;
