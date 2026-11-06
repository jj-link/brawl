#pragma force_active on

extern "C" {
extern char lbl_27_data_8E190[];
extern char lbl_27_bss_7F98[0xC];
void* fn_27_352154(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7FA4;

extern "C" void fn_27_352194(void) {
    lbl_27_bss_7FA4.vtable = 0;
    lbl_27_bss_7FA4.vtable = (void*)&lbl_27_data_8E190;
    __register_global_object(&lbl_27_bss_7FA4, (void*)fn_27_352154, lbl_27_bss_7F98);
}

__declspec(section ".ctors") extern void* const fn_27_352194_ctor = (void*)fn_27_352194;
