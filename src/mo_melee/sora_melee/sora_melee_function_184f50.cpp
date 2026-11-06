#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4CAC;
extern char lbl_27_bss_4CA0[12];
extern char lbl_27_data_30B90[];
void fn_27_184F10(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_184F50();
}

void fn_27_184F50(void) {
    lbl_27_bss_4CAC.vtable = 0;
    lbl_27_bss_4CAC.vtable = (void*)&lbl_27_data_30B90;
    __register_global_object(&lbl_27_bss_4CAC, (void*)fn_27_184F10, lbl_27_bss_4CA0);
}

__declspec(section ".ctors") extern void* const fn_27_184F50_ctor = (void*)fn_27_184F50;
