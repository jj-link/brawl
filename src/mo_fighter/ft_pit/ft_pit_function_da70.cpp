#pragma force_active on
struct PitGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x148];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};

#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern PitGlobals lbl_112_bss_8;
void* fn_112_DAD4(void*);
void* fn_112_A44C(void*, short);
void* fn_112_DB1C(void*);
void* fn_112_DB74(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_112_DA70() {
    PitGlobals* base = &lbl_112_bss_8;
    unsigned char (PitGlobals::*chain)[0xC] = &PitGlobals::firstChain;
    fn_112_DAD4(base->firstObject);
    __register_global_object(base->firstObject, fn_112_A44C, &(base->*chain));
    fn_112_DB1C(base->secondObject);
    __register_global_object(base->secondObject, fn_112_DB74, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_112_DA70_ctor = (void*)fn_112_DA70;
