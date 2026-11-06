#pragma force_active on

extern "C" {
extern char lbl_27_data_9CAE8[];
extern char lbl_27_bss_8A48[12];
void* fn_27_3A37E8(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_8A54;

extern "C" void fn_27_3A3828(void) {
    lbl_27_bss_8A54.vtable = 0;
    lbl_27_bss_8A54.vtable = (void*)&lbl_27_data_9CAE8;
    __register_global_object(&lbl_27_bss_8A54, (void*)fn_27_3A37E8, lbl_27_bss_8A48);
}

__declspec(section ".ctors") extern void* const fn_27_3A3828_ctor = (void*)fn_27_3A3828;
