#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_734C;
extern char lbl_27_data_7B8B0[];
extern char lbl_27_bss_7340[0xC];
void fn_27_2D9048(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_2D9088() {
    lbl_27_bss_734C.vtable = 0;
    lbl_27_bss_734C.vtable = (void*)&lbl_27_data_7B8B0;
    __register_global_object(&lbl_27_bss_734C, (void*)fn_27_2D9048, lbl_27_bss_7340);
}
}

__declspec(section ".ctors") extern void* const fn_27_2D9088_ctor = (void*)fn_27_2D9088;
