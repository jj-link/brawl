#pragma force_active on

extern "C" {
extern char lbl_27_data_32518[];
extern char lbl_27_bss_4F90[12];
void* fn_27_1911E4(void*, int);
void* __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4F9C;

extern "C" void fn_27_191224(void) {
    lbl_27_bss_4F9C.vtable = 0;
    lbl_27_bss_4F9C.vtable = (void*)&lbl_27_data_32518;
    __register_global_object(&lbl_27_bss_4F9C, (void*)fn_27_1911E4, lbl_27_bss_4F90);
}

__declspec(section ".ctors") extern void* const fn_27_191224_ctor = (void*)fn_27_191224;
