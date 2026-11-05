#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_2E910[];
extern char lbl_27_bss_48B8[];
extern GlobalObject lbl_27_bss_48C4;
void fn_27_1667FC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_16683C() {
    lbl_27_bss_48C4.vtable = 0;
    lbl_27_bss_48C4.vtable = lbl_27_data_2E910;
    __register_global_object(&lbl_27_bss_48C4, (void*)fn_27_1667FC, lbl_27_bss_48B8);
}
}

__declspec(section ".ctors") extern void* const fn_27_16683C_ctor = (void*)fn_27_16683C;
