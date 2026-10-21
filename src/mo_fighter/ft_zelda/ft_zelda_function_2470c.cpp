#pragma force_active on
typedef struct DestructorChain DestructorChain;

extern "C" void* fn_104_24754(void*);
extern "C" void* fn_104_246CC(void*, short);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);
extern "C" unsigned char lbl_104_bss_624;
extern "C" unsigned char lbl_104_bss_618;

extern "C" void fn_104_2470C(void) {
    fn_104_24754(&lbl_104_bss_624);
    __register_global_object(
        &lbl_104_bss_624,
        (void*)fn_104_246CC,
        (DestructorChain*)&lbl_104_bss_618
    );
}

__declspec(section ".ctors") extern void* const fn_104_2470C_ctor = (void*)fn_104_2470C;
