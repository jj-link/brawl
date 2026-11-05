#pragma force_active on
struct PurinGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x1C8];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern PurinGlobals lbl_124_bss_8;
void* __ct__26ftPurinExtendParamAccesserFv(void*);
void* __dt__26ftPurinExtendParamAccesserFv(void*, short);
void* fn_124_B1C8(void*);
void* fn_124_B220(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);
void fn_124_B11C() {
    PurinGlobals* base = &lbl_124_bss_8;
    unsigned char (PurinGlobals::*chain)[0xC] = &PurinGlobals::firstChain;
    __ct__26ftPurinExtendParamAccesserFv(base->firstObject);
    __register_global_object(base->firstObject, __dt__26ftPurinExtendParamAccesserFv, &(base->*chain));
    fn_124_B1C8(base->secondObject);
    __register_global_object(base->secondObject, fn_124_B220, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_124_B11C_ctor = (void*)fn_124_B11C;
