#pragma force_active on
extern "C" {
extern unsigned char lbl_117_bss_514[];
extern unsigned char lbl_117_bss_508[];
void fn_117_23E58(void*);
void* fn_117_23DD0(void*, short);
void __register_global_object(void*, void*, void*);

void fn_117_23E10(void) {
    fn_117_23E58(lbl_117_bss_514);
    __register_global_object(lbl_117_bss_514,
                             reinterpret_cast<void*>(fn_117_23DD0),
                             lbl_117_bss_508);
}
}

__declspec(section ".ctors") extern void* const fn_117_23E10_ctor = (void*)fn_117_23E10;
