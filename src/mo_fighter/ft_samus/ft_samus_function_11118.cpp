#pragma force_active on
extern "C" {
void fn_94_11160(void* p);
void* fn_94_110D8(void* p, short flags);
extern char lbl_94_bss_1FC[4];
extern char lbl_94_bss_1F0[12];
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_94_11118() {
    fn_94_11160(lbl_94_bss_1FC);
    __register_global_object(lbl_94_bss_1FC, (void*)fn_94_110D8, lbl_94_bss_1F0);
}
}

__declspec(section ".ctors") extern void* const fn_94_11118_ctor = (void*)fn_94_11118;
