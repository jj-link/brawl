#pragma force_active on
extern "C" {
void fn_92_F8E8(void* object);
void* fn_92_F860(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);
extern unsigned char lbl_92_bss_244[];
extern unsigned char lbl_92_bss_238[];
void fn_92_F8A0();
}

extern "C" void fn_92_F8A0() {
    fn_92_F8E8(lbl_92_bss_244);
    __register_global_object(lbl_92_bss_244, (void*)fn_92_F860, lbl_92_bss_238);
}

__declspec(section ".ctors") extern void* const fn_92_F8A0_ctor = (void*)fn_92_F8A0;
