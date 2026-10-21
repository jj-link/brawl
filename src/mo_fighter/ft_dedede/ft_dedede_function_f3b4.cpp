#pragma force_active on
extern "C" {
void fn_117_F3FC(void* dest);
void* fn_117_F374(void* object, short deleting);
void __register_global_object(void*, void*, void*);
extern unsigned char lbl_117_bss_26C[];
extern unsigned char lbl_117_bss_260[];

void fn_117_F3B4() {
    fn_117_F3FC(lbl_117_bss_26C);
    __register_global_object(lbl_117_bss_26C, reinterpret_cast<void*>(fn_117_F374), lbl_117_bss_260);
}
}

__declspec(section ".ctors") extern void* const fn_117_F3B4_ctor = (void*)fn_117_F3B4;
