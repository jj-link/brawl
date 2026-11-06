#pragma force_active on
extern "C" {
extern char lbl_27_data_32888[0x40];
extern char lbl_27_bss_5000[12];
void* fn_27_192614(void*, int);
void* __register_global_object(void*, void*, void*);

struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_500C;

void fn_27_192654() {
    lbl_27_bss_500C.vtable = 0;
    lbl_27_bss_500C.vtable = (void*)lbl_27_data_32888;
    __register_global_object(&lbl_27_bss_500C, (void*)fn_27_192614, (void*)lbl_27_bss_5000);
}
}

__declspec(section ".ctors") extern void* const fn_27_192654_ctor = (void*)fn_27_192654;
