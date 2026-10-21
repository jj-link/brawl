#pragma force_active on
extern "C" {
extern unsigned char lbl_112_bss_2D4[];
extern unsigned char lbl_112_bss_2C8[];

void fn_112_133A0(void*);
void fn_112_13318(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_112_13358() {
    fn_112_133A0(lbl_112_bss_2D4);
    __register_global_object(lbl_112_bss_2D4, (void*)fn_112_13318, lbl_112_bss_2C8);
}
}

__declspec(section ".ctors") extern void* const fn_112_13358_ctor = (void*)fn_112_13358;
