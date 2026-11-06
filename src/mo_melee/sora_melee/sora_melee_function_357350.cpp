#pragma force_active on

extern "C" {
extern char lbl_27_data_8F3D0[];
extern char lbl_27_bss_8038[12];
void fn_27_357310(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_8044;

extern "C" void fn_27_357350(void) {
    lbl_27_bss_8044.vtable = 0;
    lbl_27_bss_8044.vtable = (void*)&lbl_27_data_8F3D0;
    __register_global_object(&lbl_27_bss_8044, (void*)fn_27_357310, lbl_27_bss_8038);
}

__declspec(section ".ctors") extern void* const fn_27_357350_ctor = (void*)fn_27_357350;
