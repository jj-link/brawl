#pragma force_active on

extern "C" {

struct GlobalObject_27_50FC {
    void* vtable;
};

extern GlobalObject_27_50FC lbl_27_bss_50FC;
extern char lbl_27_bss_50F0[0xC];
extern char lbl_27_data_45C98[0x40];
void fn_27_1DDBA0(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_27_1DDBE0() {
    lbl_27_bss_50FC.vtable = 0;
    lbl_27_bss_50FC.vtable = (void*)lbl_27_data_45C98;
    __register_global_object(&lbl_27_bss_50FC, (void*)fn_27_1DDBA0, &lbl_27_bss_50F0);
}

}

__declspec(section ".ctors") extern void* const fn_27_1DDBE0_ctor;

__declspec(section ".ctors") extern void* const fn_27_1DDBE0_ctor = (void*)fn_27_1DDBE0;
