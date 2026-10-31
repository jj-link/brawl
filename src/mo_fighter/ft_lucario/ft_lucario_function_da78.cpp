#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct LucarioGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[4];
    unsigned char secondChain[0xC];
    unsigned char secondObject[4];
};

extern "C" {
extern LucarioGlobals lbl_118_bss_248;
void* fn_118_DADC(void*);
void* fn_118_DAEC(void*);
void* fn_118_DA34(void*, short);
void* fn_118_D9F0(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);

void fn_118_DA78() {
    LucarioGlobals* base = &lbl_118_bss_248;
    unsigned char (LucarioGlobals::*chain)[0xC] = &LucarioGlobals::firstChain;

    fn_118_DADC(base->firstObject);
    __register_global_object(base->firstObject, fn_118_DA34, &(base->*chain));

    fn_118_DAEC(base->secondObject);
    __register_global_object(base->secondObject, fn_118_D9F0, base->secondChain);
}
}

#pragma pop

extern void* const fn_118_DA78_ctor;

__declspec(section ".ctors") extern void* const fn_118_DA78_ctor = (void*)fn_118_DA78;
