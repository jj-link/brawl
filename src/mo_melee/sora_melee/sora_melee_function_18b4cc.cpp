#pragma force_active on
extern "C" void fn_27_16AD18(void*);
extern "C" void* fn_27_18B48C(void*, int);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" unsigned char lbl_27_bss_4E6C[];
extern "C" unsigned char lbl_27_bss_4E60[];
extern "C" unsigned char lbl_27_data_31880[];

extern "C" void fn_27_18B4CC() {
    fn_27_16AD18(lbl_27_bss_4E6C);
    *reinterpret_cast<void**>(lbl_27_bss_4E6C) = lbl_27_data_31880;
    __register_global_object(
        lbl_27_bss_4E6C,
        reinterpret_cast<void*>(fn_27_18B48C),
        lbl_27_bss_4E60
    );
}

__declspec(section ".ctors") extern void* const fn_27_18B4CC_ctor = (void*)fn_27_18B4CC;
