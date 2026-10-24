#pragma force_active on
struct LucasGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x178];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern LucasGlobals lbl_114_bss_8;
void* fn_114_10590(void*);
void* fn_114_105D8(void*);
void* fn_114_C858(void*, short);
void* fn_114_10630(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_114_1052C() {
    LucasGlobals* base = &lbl_114_bss_8;
    unsigned char (LucasGlobals::*chain)[0xC] = &LucasGlobals::firstChain;
    fn_114_10590(base->firstObject);
    __register_global_object(base->firstObject, fn_114_C858, &(base->*chain));
    fn_114_105D8(base->secondObject);
    __register_global_object(base->secondObject, fn_114_10630, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_114_1052C_ctor = (void*)fn_114_1052C;
