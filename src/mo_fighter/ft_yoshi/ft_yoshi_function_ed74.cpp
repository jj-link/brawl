#pragma force_active on
struct YoshiGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x2E0];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern YoshiGlobals lbl_95_bss_8;
void* fn_95_EDD8(void*);
void* fn_95_B2A0(void*, short);
void* fn_95_EE20(void*);
void* fn_95_EE78(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_95_ED74() {
    YoshiGlobals* base = &lbl_95_bss_8;
    unsigned char (YoshiGlobals::*chain)[0xC] = &YoshiGlobals::firstChain;
    fn_95_EDD8(base->firstObject);
    __register_global_object(base->firstObject, fn_95_B2A0, &(base->*chain));
    fn_95_EE20(base->secondObject);
    __register_global_object(base->secondObject, fn_95_EE78, base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_95_ED74_ctor = (void*)fn_95_ED74;
