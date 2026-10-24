#pragma force_active on
struct WolfGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x168];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
    unsigned char chain3[0xC];
    unsigned char obj3[4];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern WolfGlobals lbl_125_bss_8;
void* fn_125_E5C8(void*);
void* fn_125_AC7C(void*, short);
void* fn_125_E610(void*);
void* fn_125_E668(void*, short);
void* fn_125_E6EC(void*);
void* fn_125_E6FC(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_125_E548() {
    WolfGlobals* base = &lbl_125_bss_8;
    unsigned char (WolfGlobals::*chain)[0xC] = &WolfGlobals::chain1;
    fn_125_E5C8(base->obj1);
    __register_global_object(base->obj1, fn_125_AC7C, &(base->*chain));
    fn_125_E610(base->obj2);
    __register_global_object(base->obj2, fn_125_E668, base->chain2);
    fn_125_E6EC(base->obj3);
    __register_global_object(base->obj3, fn_125_E6FC, base->chain3);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_125_E548_ctor = (void*)fn_125_E548;
