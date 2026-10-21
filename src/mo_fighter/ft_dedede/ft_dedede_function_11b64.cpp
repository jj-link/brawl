#pragma force_active on
struct DededeDataRef;
extern "C" void fn_117_11BAC(DededeDataRef*);
extern "C" void* fn_117_11B24(void*, short);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" {
extern void* lbl_117_bss_2DC;
extern void* lbl_117_bss_2D0;

void fn_117_11B64(void) {
    fn_117_11BAC(reinterpret_cast<DededeDataRef*>(&lbl_117_bss_2DC));
    __register_global_object(&lbl_117_bss_2DC, reinterpret_cast<void*>(fn_117_11B24), &lbl_117_bss_2D0);
}
}

__declspec(section ".ctors") extern void* const fn_117_11B64_ctor = (void*)fn_117_11B64;
