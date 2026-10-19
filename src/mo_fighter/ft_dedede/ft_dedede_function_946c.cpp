#pragma force_active on
extern "C" {
extern signed char lbl_117_bss_224;
extern unsigned char lbl_117_bss_228[];
extern unsigned char lbl_117_bss_210[];
void fn_27_395984(void*);
void fn_27_395994(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_117_946C() {
    if (lbl_117_bss_224 == 0) {
        fn_27_395984(lbl_117_bss_228);
        __register_global_object(lbl_117_bss_228,
            reinterpret_cast<void*>(fn_27_395994), lbl_117_bss_210);
        lbl_117_bss_224 = 1;
    }
    return lbl_117_bss_228;
}
