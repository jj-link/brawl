#pragma force_active on
extern "C" {
    void __ct__18soModelVirtualNodeFv(void*);
    void __register_global_object(void* obj, void (*dtor)(void*, int), void* handle);
    void __dt__18soModelVirtualNodeFv(void*, int);
    extern signed char lbl_27_bss_1880;
    extern char lbl_27_bss_1884[0x14];
    extern char lbl_27_bss_1010[0xC];
}

extern "C" void* fn_27_86008() {
    if (!lbl_27_bss_1880) {
        __ct__18soModelVirtualNodeFv(lbl_27_bss_1884);
        __register_global_object(lbl_27_bss_1884, __dt__18soModelVirtualNodeFv, lbl_27_bss_1010);
        lbl_27_bss_1880 = 1;
    }
    return lbl_27_bss_1884;
}
