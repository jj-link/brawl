#pragma force_active on
extern "C" {
void fn_92_F248(void** object);
void* fn_92_F1C0(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);
extern void* lbl_92_bss_204;
extern unsigned char lbl_92_bss_1F8[];
}

extern "C" void fn_92_F200() {
    fn_92_F248(&lbl_92_bss_204);
    __register_global_object(&lbl_92_bss_204, (void*)fn_92_F1C0, lbl_92_bss_1F8);
}

__declspec(section ".ctors") extern void* const fn_92_F200_ctor = (void*)fn_92_F200;
