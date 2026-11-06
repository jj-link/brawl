#pragma force_active on

extern "C" {
extern char lbl_27_data_9D4C0[];
extern char lbl_27_bss_8A90[0xC];
void* fn_27_3A6254(void*, int);
void* __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_8A9C;

extern "C" void fn_27_3A6294(void) {
    lbl_27_bss_8A9C.vtable = 0;
    lbl_27_bss_8A9C.vtable = (void*)&lbl_27_data_9D4C0;
    __register_global_object(&lbl_27_bss_8A9C, (void*)fn_27_3A6254, lbl_27_bss_8A90);
}

__declspec(section ".ctors") extern void* const fn_27_3A6294_ctor = (void*)fn_27_3A6294;
