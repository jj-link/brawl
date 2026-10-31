#pragma force_active on
struct ZakoGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x28];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0x38];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern ZakoGlobals lbl_126_bss_80;
void* fn_126_B790(void*);
void* fn_126_B61C(void*, short);
void* fn_126_B7D8(void*);
void* fn_126_B830(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_126_B72C() {
    ZakoGlobals* base = &lbl_126_bss_80;
    unsigned char (ZakoGlobals::*chain)[0xC] = &ZakoGlobals::firstChain;
    fn_126_B790(base->firstObject);
    __register_global_object(base->firstObject, fn_126_B61C, &(base->*chain));
    fn_126_B7D8(base->secondObject);
    __register_global_object(base->secondObject, fn_126_B830, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_126_B72C_ctor = (void*)fn_126_B72C;
