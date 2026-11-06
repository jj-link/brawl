#pragma force_active on

extern "C" {
extern char lbl_27_data_31D90[];
extern char lbl_27_bss_4ED0[0xC];
void fn_27_18E798(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_18E7D8(void);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4EDC;

void fn_27_18E7D8(void) {
    lbl_27_bss_4EDC.vtable = 0;
    lbl_27_bss_4EDC.vtable = (void*)&lbl_27_data_31D90[0];
    __register_global_object(&lbl_27_bss_4EDC, (void*)fn_27_18E798, lbl_27_bss_4ED0);
}

__declspec(section ".ctors") extern void* const fn_27_18E7D8_ctor = (void*)fn_27_18E7D8;
