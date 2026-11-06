#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_9B808[0x40];
extern char lbl_27_bss_8970[0xC];
extern GlobalObject lbl_27_bss_897C;
void* fn_27_39BD40(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_27_39BD80(void) {
    lbl_27_bss_897C.vtable = 0;
    lbl_27_bss_897C.vtable = (void*)lbl_27_data_9B808;
    __register_global_object(&lbl_27_bss_897C, (void*)fn_27_39BD40, (void*)lbl_27_bss_8970);
}
}

__declspec(section ".ctors") extern void* const fn_27_39BD80_ctor = (void*)fn_27_39BD80;
