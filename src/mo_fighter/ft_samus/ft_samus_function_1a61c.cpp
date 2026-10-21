#pragma force_active on
extern "C" {
void fn_94_1A664(void* p);
void* fn_94_1A5DC(void* p, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);

extern int lbl_94_bss_32C;
extern char lbl_94_bss_320[12];

void fn_94_1A61C() {
    fn_94_1A664(&lbl_94_bss_32C);
    __register_global_object(&lbl_94_bss_32C, (void*)fn_94_1A5DC, lbl_94_bss_320);
}
}

__declspec(section ".ctors") extern void* const fn_94_1A61C_ctor = (void*)fn_94_1A61C;
