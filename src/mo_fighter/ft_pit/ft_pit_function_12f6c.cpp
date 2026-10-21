#pragma force_active on
extern "C" {
extern unsigned char lbl_112_bss_2B4[];
extern unsigned char lbl_112_bss_2A8[];
void fn_112_12FB4(void* p);
void* fn_112_12F2C(void* p, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_112_12F6C(void) {
    fn_112_12FB4(lbl_112_bss_2B4);
    __register_global_object(lbl_112_bss_2B4, (void*)fn_112_12F2C, lbl_112_bss_2A8);
}
}

__declspec(section ".ctors") extern void* const fn_112_12F6C_ctor = (void*)fn_112_12F6C;
