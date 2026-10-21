#pragma force_active on
extern "C" {
void fn_96_28FB8(void* object);
void* fn_96_28F30(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" int lbl_96_bss_122C;
extern "C" char lbl_96_bss_1220[12];

extern "C" void fn_96_28F70() {
    fn_96_28FB8(&lbl_96_bss_122C);
    __register_global_object(&lbl_96_bss_122C, (void*)fn_96_28F30, lbl_96_bss_1220);
}

__declspec(section ".ctors") extern void* const fn_96_28F70_ctor = (void*)fn_96_28F70;
