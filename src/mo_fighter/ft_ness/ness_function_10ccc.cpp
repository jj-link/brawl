#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct NessGlobals {
    unsigned char chain0[0xC];
    unsigned char obj0[0x178];
    unsigned char chain1[0xC];
    unsigned char obj1[0xC];
};

extern "C" {
extern NessGlobals lbl_101_bss_8;
void* fn_101_10D30(void*);
void* fn_101_CE1C(void*, short);
void* fn_101_10D78(void*);
void* fn_101_10DD0(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);

void fn_101_10CCC() {
    NessGlobals* base = &lbl_101_bss_8;
    unsigned char (NessGlobals::*chain)[0xC] = &NessGlobals::chain0;
    fn_101_10D30(base->obj0);
    __register_global_object(base->obj0, fn_101_CE1C, &(base->*chain));
    fn_101_10D78(base->obj1);
    __register_global_object(base->obj1, fn_101_10DD0, base->chain1);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_101_10CCC_ctor = (void*)fn_101_10CCC;
