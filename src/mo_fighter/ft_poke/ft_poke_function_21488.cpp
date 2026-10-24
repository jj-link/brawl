#pragma force_active on
struct PokeGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x90];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern PokeGlobals lbl_116_bss_4D0;
void* fn_116_214EC(void*);
void* fn_116_2034C(void*, short);
void* fn_116_21534(void*);
void* fn_116_2158C(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_116_21488() {
    PokeGlobals* base = &lbl_116_bss_4D0;
    unsigned char (PokeGlobals::*chain)[0xC] = &PokeGlobals::firstChain;
    fn_116_214EC(base->firstObject);
    __register_global_object(base->firstObject, fn_116_2034C, &(base->*chain));
    fn_116_21534(base->secondObject);
    __register_global_object(base->secondObject, fn_116_2158C, base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_116_21488_ctor = (void*)fn_116_21488;
