#pragma force_active on
extern "C" {
extern unsigned char lbl_117_bss_504[];
extern unsigned char lbl_117_bss_4F8[];
void fn_117_23B34(void*);
void* fn_117_23AAC(void*, short);
void __register_global_object(void*, void*, void*);

void fn_117_23AEC(void) {
    fn_117_23B34(lbl_117_bss_504);
    __register_global_object(lbl_117_bss_504, reinterpret_cast<void*>(fn_117_23AAC), lbl_117_bss_4F8);
}
}

__declspec(section ".ctors") extern void* const fn_117_23AEC_ctor = (void*)fn_117_23AEC;
