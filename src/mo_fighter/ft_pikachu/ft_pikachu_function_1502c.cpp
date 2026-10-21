#pragma force_active on
extern "C" {
extern char lbl_98_bss_314[];
extern char lbl_98_bss_308[];
void fn_98_15074(void* ptr);
void* fn_98_15084(void*, int);
void __register_global_object(void*, void*, void*);

void fn_98_1502C() {
    fn_98_15074(lbl_98_bss_314);
    __register_global_object(lbl_98_bss_314, reinterpret_cast<void*>(fn_98_15084), lbl_98_bss_308);
}
}

__declspec(section ".ctors") extern void* const fn_98_1502C_ctor = (void*)fn_98_1502C;
