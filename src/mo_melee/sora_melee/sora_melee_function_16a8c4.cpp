#pragma force_active on
extern "C" {
extern char lbl_27_data_2EF30[];
extern char lbl_27_data_2EFA0[];
extern int lbl_27_bss_4994;

struct Object {
    void* vtable;
    void* ptr;
};

extern Object lbl_27_bss_49C0;
extern char lbl_27_bss_49B0[];

void* fn_27_16A884(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_27_16A8C4() {
    lbl_27_bss_49C0.vtable = lbl_27_data_2EF30;
    lbl_27_bss_49C0.ptr = &lbl_27_bss_4994;
    lbl_27_bss_49C0.vtable = lbl_27_data_2EFA0;
    __register_global_object(
        &lbl_27_bss_49C0,
        (void*)fn_27_16A884,
        lbl_27_bss_49B0
    );
}
}

__declspec(section ".ctors") extern void* const fn_27_16A8C4_ctor = (void*)fn_27_16A8C4;
