#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct LucarioGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[4];
    unsigned char secondChain[0xC];
    unsigned char secondObject[4];
    unsigned char thirdChain[0xC];
    unsigned char thirdObject[4];
    unsigned char fourthChain[0xC];
    unsigned char fourthObject[4];
};

extern "C" {
extern LucarioGlobals lbl_118_bss_268;
void* fn_118_10314(void*);
void* fn_118_10324(void*);
void* fn_118_10334(void*);
void* fn_118_10344(void*);
void* fn_118_10238(void*, short);
void* fn_118_101F8(void*, short);
void* fn_118_101B8(void*, short);
void* fn_118_10178(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);

void fn_118_10278() {
    LucarioGlobals* base = &lbl_118_bss_268;
    unsigned char (LucarioGlobals::*chain)[0xC] = &LucarioGlobals::firstChain;

    fn_118_10314(base->firstObject);
    __register_global_object(base->firstObject, fn_118_10238, &(base->*chain));

    fn_118_10324(base->secondObject);
    __register_global_object(base->secondObject, fn_118_101F8, base->secondChain);

    fn_118_10334(base->thirdObject);
    __register_global_object(base->thirdObject, fn_118_101B8, base->thirdChain);

    fn_118_10344(base->fourthObject);
    __register_global_object(base->fourthObject, fn_118_10178, base->fourthChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_118_10278_ctor = (void*)fn_118_10278;
