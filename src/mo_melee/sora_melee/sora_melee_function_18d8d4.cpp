#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_4E9C;
extern char lbl_27_data_31BA0[0x40];
extern int lbl_27_bss_4E90[3];
void* fn_27_18CF34(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_18D8D4(void);
}

void fn_27_18D8D4() {
    lbl_27_bss_4E9C.vtable = 0;
    lbl_27_bss_4E9C.vtable = (void*)&lbl_27_data_31BA0;
    __register_global_object(&lbl_27_bss_4E9C, (void*)fn_27_18CF34, lbl_27_bss_4E90);
}

__declspec(section ".ctors") extern void* const fn_27_18D8D4_ctor = (void*)fn_27_18D8D4;
