#pragma force_active on
struct PokeGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x188];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0x18];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern PokeGlobals lbl_116_bss_2E8;
void* fn_116_1A3BC(void*);
void* fn_116_187C4(void*, short);
void* fn_116_1A404(void*);
void* fn_116_1A45C(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_116_1A358() {
    PokeGlobals* base = &lbl_116_bss_2E8;
    unsigned char (PokeGlobals::*chain)[0xC] = &PokeGlobals::firstChain;
    fn_116_1A3BC(base->firstObject);
    __register_global_object(base->firstObject, fn_116_187C4, &(base->*chain));
    fn_116_1A404(base->secondObject);
    __register_global_object(base->secondObject, fn_116_1A45C, base->secondChain);
}
}

__declspec(section ".ctors") extern void* const fn_116_1A358_ctor = (void*)fn_116_1A358;
