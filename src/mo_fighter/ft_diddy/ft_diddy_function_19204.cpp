#pragma force_active on
extern "C" {
extern unsigned char lbl_115_bss_3DC[];
extern unsigned char lbl_115_bss_3D0[];
void* fn_115_1924C(void** object);
void* fn_115_191C4(void* object, short shouldDelete);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_115_19204() {
    fn_115_1924C((void**)lbl_115_bss_3DC);
    __register_global_object(lbl_115_bss_3DC, (void*)fn_115_191C4, lbl_115_bss_3D0);
}
}

__declspec(section ".ctors") extern void* const fn_115_19204_ctor = (void*)fn_115_19204;
