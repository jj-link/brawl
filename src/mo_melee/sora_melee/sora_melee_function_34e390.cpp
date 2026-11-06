#pragma force_active on

extern "C" {
extern char lbl_27_data_8D8D0[];
extern char lbl_27_bss_7F48[12];
void* fn_27_34E350(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7F54;

extern "C" void fn_27_34E390() {
    lbl_27_bss_7F54.vtable = 0;
    lbl_27_bss_7F54.vtable = (void*)&lbl_27_data_8D8D0;
    __register_global_object(&lbl_27_bss_7F54, (void*)fn_27_34E350, lbl_27_bss_7F48);
}

__declspec(section ".ctors") extern void* const fn_27_34E390_ctor = (void*)fn_27_34E390;
