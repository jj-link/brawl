#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_30558[0x80];
extern GlobalObject lbl_27_bss_4BDC;
extern char lbl_27_bss_4BD0[12];
void fn_27_17DDE8(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_17DE28(void) {
    lbl_27_bss_4BDC.vtable = 0;
    lbl_27_bss_4BDC.vtable = (void*)&lbl_27_data_30558;
    __register_global_object(&lbl_27_bss_4BDC, (void*)fn_27_17DDE8, lbl_27_bss_4BD0);
}

__declspec(section ".ctors") extern void* const fn_27_17DE28_ctor = (void*)fn_27_17DE28;
