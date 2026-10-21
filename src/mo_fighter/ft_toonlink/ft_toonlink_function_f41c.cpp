#pragma force_active on
extern "C" {
void fn_121_F464(void **object);
void* fn_121_F3DC(void* ptr, int count);
void* __register_global_object(void* object, void* destructor, void* chain);
extern void* lbl_121_bss_15C;
extern void* lbl_121_bss_150[3];
}

extern "C" void fn_121_F41C() {
    fn_121_F464(&lbl_121_bss_15C);
    __register_global_object(&lbl_121_bss_15C, (void*)fn_121_F3DC, lbl_121_bss_150);
}

__declspec(section ".ctors") extern void* const fn_121_F41C_ctor = (void*)fn_121_F41C;
