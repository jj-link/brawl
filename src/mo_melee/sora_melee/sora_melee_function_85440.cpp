#pragma force_active on
extern "C" {
void __register_global_object(void* obj, void (*dtor)(void*), void* ctx);
void* fn_27_137B4(void* self);
void fn_27_137EC(void*, int);
extern char lbl_27_bss_1390;
extern char lbl_27_bss_1394[];
extern char lbl_27_bss_F38[];
}

extern "C" void* fn_27_85440() {
    if (!lbl_27_bss_1390) {
        fn_27_137B4(lbl_27_bss_1394);
        __register_global_object(lbl_27_bss_1394, (void (*)(void*))fn_27_137EC, lbl_27_bss_F38);
        lbl_27_bss_1390 = 1;
    }
    return lbl_27_bss_1394;
}
