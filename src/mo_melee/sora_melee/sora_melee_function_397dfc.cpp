#pragma force_active on

extern "C" {
extern unsigned char lbl_27_data_9AF08[64];
void* fn_27_397DBC(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_890C;

extern "C" char lbl_27_bss_8900[0xC];

extern "C" void fn_27_397DFC(void) {
    lbl_27_bss_890C.vtable = 0;
    lbl_27_bss_890C.vtable = lbl_27_data_9AF08;
    __register_global_object(&lbl_27_bss_890C, (void*)fn_27_397DBC, lbl_27_bss_8900);
}

__declspec(section ".ctors") extern void* const fn_27_397DFC_ctor;

__declspec(section ".ctors") extern void* const fn_27_397DFC_ctor = (void*)fn_27_397DFC;
