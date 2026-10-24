#pragma force_active on
struct PikminGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x98];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern PikminGlobals lbl_113_bss_8;
void* fn_113_FDF4(void*);
void* fn_113_C5F8(void*, short);
void* fn_113_FE3C(void*);
void* fn_113_FE94(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_113_FD90() {
    PikminGlobals* base = &lbl_113_bss_8;
    unsigned char (PikminGlobals::*chain)[0xC] = &PikminGlobals::firstChain;
    fn_113_FDF4(base->firstObject);
    __register_global_object(base->firstObject, fn_113_C5F8, &(base->*chain));
    fn_113_FE3C(base->secondObject);
    __register_global_object(base->secondObject, fn_113_FE94, base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_113_FD90_ctor = (void*)fn_113_FD90;
