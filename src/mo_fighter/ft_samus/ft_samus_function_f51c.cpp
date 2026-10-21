#pragma force_active on
extern "C" {
extern unsigned char lbl_94_bss_1CC[];
extern unsigned char lbl_94_bss_1C0[];

void fn_94_F564(void*);
void fn_94_F4D0(void*, short);
void __register_global_object(void*, void*, void*);

void fn_94_F51C() {
    fn_94_F564(lbl_94_bss_1CC);
    __register_global_object(lbl_94_bss_1CC, (void*)fn_94_F4D0, lbl_94_bss_1C0);
}
}

__declspec(section ".ctors") extern void* const fn_94_F51C_ctor = (void*)fn_94_F51C;
