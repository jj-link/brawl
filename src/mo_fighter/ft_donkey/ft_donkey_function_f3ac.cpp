#pragma force_active on
extern "C" {
typedef void (*Destructor)(void*, short);

extern void fn_92_F3F4(void**);
extern void* fn_92_F36C(void*, short);
extern void __register_global_object(void*, void*, void*);

extern unsigned char lbl_92_bss_214[];
extern unsigned char lbl_92_bss_208[];

void fn_92_F3AC(void) {
    fn_92_F3F4((void**)lbl_92_bss_214);
    __register_global_object(
        lbl_92_bss_214,
        (void*)fn_92_F36C,
        (void*)lbl_92_bss_208
    );
}
}

__declspec(section ".ctors") extern void* const fn_92_F3AC_ctor = (void*)fn_92_F3AC;
