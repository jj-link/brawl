#pragma force_active on
typedef signed short s16;

extern "C" {
extern unsigned char lbl_112_bss_2C4[];
extern unsigned char lbl_112_bss_2B8[];

void fn_112_130E0(void*);
void* fn_112_13058(void*, s16);
void* __register_global_object(void*, void*, void*);

void fn_112_13098(void) {
    void* object = lbl_112_bss_2C4;
    fn_112_130E0(object);
    __register_global_object(lbl_112_bss_2C4,
                             (void*)fn_112_13058,
                             lbl_112_bss_2B8);
}
}

__declspec(section ".ctors") extern void* const fn_112_13098_ctor = (void*)fn_112_13098;
