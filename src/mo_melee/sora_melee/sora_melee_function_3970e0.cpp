#pragma force_active on

struct ObjectBase {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_9AE58[];
extern unsigned char lbl_27_bss_88F0[0xC];
extern ObjectBase lbl_27_bss_88FC;
void* fn_27_3970A0(void* ptr, int flag);
void* __register_global_object(void* object, void* destructor, void* chain);
void fn_27_3970E0(void);
}

void fn_27_3970E0() {
    lbl_27_bss_88FC.vtable = 0;
    lbl_27_bss_88FC.vtable = (void*)&lbl_27_data_9AE58;
    __register_global_object(&lbl_27_bss_88FC, (void*)fn_27_3970A0, lbl_27_bss_88F0);
}

__declspec(section ".ctors") extern void* const fn_27_3970E0_ctor = (void*)fn_27_3970E0;
