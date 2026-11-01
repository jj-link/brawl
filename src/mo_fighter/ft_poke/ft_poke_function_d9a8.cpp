#pragma force_active on
struct PokeGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x108];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern PokeGlobals lbl_116_bss_8;
void* fn_116_DA0C(void*);
void* fn_116_A278(void*, short);
void* fn_116_DA54(void*);
void* fn_116_DAAC(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_116_D9A8() {
    PokeGlobals* base = &lbl_116_bss_8;
    unsigned char (PokeGlobals::*chain)[0xC] = &PokeGlobals::firstChain;
    fn_116_DA0C(base->firstObject);
    __register_global_object(base->firstObject, fn_116_A278, &(base->*chain));
    fn_116_DA54(base->secondObject);
    __register_global_object(base->secondObject, fn_116_DAAC, base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_116_D9A8_ctor = (void*)fn_116_D9A8;
