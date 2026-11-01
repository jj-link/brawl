#pragma force_active on
struct SamusGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x180];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern SamusGlobals lbl_94_bss_8;
void* fn_94_EB38(void*);
void* fn_94_AD30(void*, short);
void* fn_94_EB80(void*);
void* fn_94_EBD8(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_94_EAD4() {
    SamusGlobals* base = &lbl_94_bss_8;
    unsigned char (SamusGlobals::*chain)[0xC] = &SamusGlobals::firstChain;
    fn_94_EB38(base->firstObject);
    __register_global_object(base->firstObject, fn_94_AD30, &(base->*chain));
    fn_94_EB80(base->secondObject);
    __register_global_object(base->secondObject, fn_94_EBD8, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_94_EAD4_ctor = (void*)fn_94_EAD4;
