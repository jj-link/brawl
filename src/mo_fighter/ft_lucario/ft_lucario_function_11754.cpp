#pragma force_active on
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
    unsigned char fifthChain[0xC];
    unsigned char fifthObject[4];
};

extern "C" {
extern LucarioGlobals lbl_118_bss_2D8;
void* fn_118_1180C(void*);
void* fn_118_1181C(void*);
void* fn_118_1182C(void*);
void* fn_118_1183C(void*);
void* fn_118_1184C(void*);
void* fn_118_11714(void*, short);
void* fn_118_116D4(void*, short);
void* fn_118_11694(void*, short);
void* fn_118_11654(void*, short);
void* fn_118_11614(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);

void fn_118_11754() {
    LucarioGlobals* base = &lbl_118_bss_2D8;
    unsigned char (LucarioGlobals::*firstChain)[0xC] = &LucarioGlobals::firstChain;

    fn_118_1180C(base->firstObject);
    __register_global_object(base->firstObject, fn_118_11714, &(base->*firstChain));

    fn_118_1181C(base->secondObject);
    __register_global_object(base->secondObject, fn_118_116D4, base->secondChain);

    fn_118_1182C(base->thirdObject);
    __register_global_object(base->thirdObject, fn_118_11694, base->thirdChain);

    fn_118_1183C(base->fourthObject);
    __register_global_object(base->fourthObject, fn_118_11654, base->fourthChain);

    fn_118_1184C(base->fifthObject);
    __register_global_object(base->fifthObject, fn_118_11614, base->fifthChain);
}
}

__declspec(section ".ctors") extern void* const fn_118_11754_ctor = (void*)fn_118_11754;
