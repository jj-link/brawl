#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_2EE78[];
extern char lbl_27_bss_4978[];
extern GlobalObject lbl_27_bss_4984;
void fn_27_169F38(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_169F78() {
    lbl_27_bss_4984.vtable = 0;
    lbl_27_bss_4984.vtable = lbl_27_data_2EE78;
    __register_global_object(&lbl_27_bss_4984, (void*)fn_27_169F38, lbl_27_bss_4978);
}
}

__declspec(section ".ctors") extern void* const fn_27_169F78_ctor = (void*)fn_27_169F78;
