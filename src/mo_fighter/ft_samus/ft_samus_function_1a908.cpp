#pragma force_active on
typedef unsigned char DestructorChain[12];

extern "C" void fn_94_1A950(void*);
extern "C" void fn_94_1A8C8(void*, short);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);

extern "C" unsigned char lbl_94_bss_33C[];
extern "C" DestructorChain lbl_94_bss_330;

extern "C" void fn_94_1A908() {
    fn_94_1A950(lbl_94_bss_33C);
    __register_global_object(
        lbl_94_bss_33C,
        (void*)fn_94_1A8C8,
        &lbl_94_bss_330
    );
}

__declspec(section ".ctors") extern void* const fn_94_1A908_ctor = (void*)fn_94_1A908;
