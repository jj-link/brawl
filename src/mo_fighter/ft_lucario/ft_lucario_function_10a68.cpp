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
};

extern "C" {
extern LucarioGlobals lbl_118_bss_2A8;
void* fn_118_10AE8(void*);
void* fn_118_10AF8(void*);
void* fn_118_10B08(void*);
void* fn_118_10A28(void*, short);
void* fn_118_109E8(void*, short);
void* fn_118_109A8(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);

void fn_118_10A68() {
    LucarioGlobals* base = &lbl_118_bss_2A8;
    unsigned char (LucarioGlobals::*chain)[0xC] = &LucarioGlobals::firstChain;

    fn_118_10AE8(base->firstObject);
    __register_global_object(base->firstObject, fn_118_10A28, &(base->*chain));

    fn_118_10AF8(base->secondObject);
    __register_global_object(base->secondObject, fn_118_109E8, base->secondChain);

    fn_118_10B08(base->thirdObject);
    __register_global_object(base->thirdObject, fn_118_109A8, base->thirdChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_118_10A68_ctor = (void*)fn_118_10A68;
