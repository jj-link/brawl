#pragma force_active on
extern "C" unsigned char lbl_95_bss_39C;
extern "C" unsigned char lbl_95_bss_390;
extern "C" void fn_95_F928(void*);
extern "C" void* fn_95_F8A0(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" void fn_95_F8E0() {
    fn_95_F928(&lbl_95_bss_39C);
    __register_global_object(&lbl_95_bss_39C, (void*)fn_95_F8A0,
                             &lbl_95_bss_390);
}

__declspec(section ".ctors") extern void* const fn_95_F8E0_ctor = (void*)fn_95_F8E0;
