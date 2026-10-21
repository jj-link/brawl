#pragma force_active on
extern "C" {
extern void* lbl_92_bss_264;
extern char lbl_92_bss_258[];
void fn_92_FDBC(void** dst);
void* fn_92_FD34(void* ptr, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_92_FD74(void) {
    fn_92_FDBC(&lbl_92_bss_264);
    __register_global_object(&lbl_92_bss_264, (void*)fn_92_FD34, lbl_92_bss_258);
}
}

__declspec(section ".ctors") extern void* const fn_92_FD74_ctor = (void*)fn_92_FD74;
