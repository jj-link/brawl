#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct LucarioGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[4];
    unsigned char pad[0x1EC];
    unsigned char secondChain[0xC];
    unsigned char secondObject[4];
};

extern "C" {
extern LucarioGlobals lbl_118_bss_8;
void* fn_118_D2BC(void*);
void* fn_118_9E74(void*, short);
void* fn_118_D304(void*);
void* fn_118_D35C(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);

void fn_118_D258() {
    LucarioGlobals* base = &lbl_118_bss_8;
    unsigned char (LucarioGlobals::*chain)[0xC] = &LucarioGlobals::firstChain;

    fn_118_D2BC(base->firstObject);
    __register_global_object(base->firstObject, fn_118_9E74, &(base->*chain));

    fn_118_D304(base->secondObject);
    __register_global_object(base->secondObject, fn_118_D35C, base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_118_D258_ctor = (void*)fn_118_D258;
