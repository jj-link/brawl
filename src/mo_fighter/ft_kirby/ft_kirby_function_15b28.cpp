#pragma force_active on
struct KirbyGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[4];
    unsigned char secondChain[0xC];
    unsigned char secondObject[4];
    unsigned char thirdChain[0xC];
    unsigned char thirdObject[4];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern KirbyGlobals lbl_96_bss_C50;
void fn_96_15BA8(void*);
void fn_96_15BB8(void**);
void* fn_96_15BC8(void*);
void* fn_96_15AE8(void*, short);
void* fn_96_15AA8(void*, short);
void* fn_96_15A68(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_96_15B28() {
    KirbyGlobals* base = &lbl_96_bss_C50;
    unsigned char (KirbyGlobals::*chain)[0xC] = &KirbyGlobals::firstChain;
    fn_96_15BA8(base->firstObject);
    __register_global_object(base->firstObject, fn_96_15AE8, &(base->*chain));
    fn_96_15BB8(reinterpret_cast<void**>(base->secondObject));
    __register_global_object(base->secondObject, fn_96_15AA8, base->secondChain);
    fn_96_15BC8(base->thirdObject);
    __register_global_object(base->thirdObject, fn_96_15A68, base->thirdChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_96_15B28_ctor = (void*)fn_96_15B28;
