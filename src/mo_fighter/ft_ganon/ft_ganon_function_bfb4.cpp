#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off
struct GanonGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0xF8];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
extern "C" {
extern GanonGlobals lbl_109_bss_8;
void* fn_109_C018(void*);
void* fn_109_8C7C(void*, short);
void* fn_109_C060(void*);
void* fn_109_C0B8(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_109_BFB4() {
    GanonGlobals* base = &lbl_109_bss_8;
    unsigned char (GanonGlobals::*chain)[0xC] = &GanonGlobals::firstChain;
    fn_109_C018(base->firstObject);
    __register_global_object(base->firstObject, fn_109_8C7C, &(base->*chain));
    fn_109_C060(base->secondObject);
    __register_global_object(base->secondObject, fn_109_C0B8, base->secondChain);
}
}
#pragma pop
extern void* const fn_109_BFB4_ctor;

__declspec(section ".ctors") extern void* const fn_109_BFB4_ctor = (void*)fn_109_BFB4;
