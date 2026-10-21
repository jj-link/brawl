#pragma force_active on
extern "C" {
extern void* lbl_117_bss_27C;
extern unsigned char lbl_117_bss_270[];
void fn_117_F588(void*);
void* fn_117_F500(void*, short);
void __register_global_object(void*, void*, void*);

void fn_117_F540(void) {
    fn_117_F588(&lbl_117_bss_27C);
    __register_global_object(&lbl_117_bss_27C, reinterpret_cast<void*>(fn_117_F500), lbl_117_bss_270);
}
}

__declspec(section ".ctors") extern void* const fn_117_F540_ctor = (void*)fn_117_F540;
