#pragma force_active on
extern "C" {
void fn_110_DC80(void* p);
void* fn_110_DBF8(void* p, short flags);
void* __register_global_object(void* object, void* destructor, void* chain);
extern unsigned char lbl_110_bss_1D4[4];
extern unsigned char lbl_110_bss_1C8[12];

void fn_110_DC38() {
    fn_110_DC80(lbl_110_bss_1D4);
    __register_global_object(lbl_110_bss_1D4, (void*)fn_110_DBF8, lbl_110_bss_1C8);
}
}

__declspec(section ".ctors") extern void* const fn_110_DC38_ctor = (void*)fn_110_DC38;
