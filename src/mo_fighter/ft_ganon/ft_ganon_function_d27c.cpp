#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off
struct GanonGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x4];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0x4];
    unsigned char thirdChain[0xC];
    unsigned char thirdObject[0x4];
    unsigned char fourthChain[0xC];
    unsigned char fourthObject[0x4];
    unsigned char fifthChain[0xC];
    unsigned char fifthObject[0x4];
};
extern "C" {
extern GanonGlobals lbl_109_bss_158;
void* fn_109_D334(void*);
void fn_109_D344(void**);
void fn_109_D354(void**);
void fn_109_D364(void*);
void fn_109_D374(void**);
void* fn_109_D23C(void*, short);
void* fn_109_D1FC(void*, short);
void* fn_109_D1BC(void*, short);
void* fn_109_D17C(void*, short);
void* fn_109_D13C(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_109_D27C() {
    GanonGlobals* base = &lbl_109_bss_158;
    unsigned char (GanonGlobals::*chain)[0xC] = &GanonGlobals::firstChain;
    fn_109_D334(base->firstObject);
    __register_global_object(base->firstObject, fn_109_D23C, &(base->*chain));
    fn_109_D344((void**)base->secondObject);
    __register_global_object(base->secondObject, fn_109_D1FC, base->secondChain);
    fn_109_D354((void**)base->thirdObject);
    __register_global_object(base->thirdObject, fn_109_D1BC, base->thirdChain);
    fn_109_D364(base->fourthObject);
    __register_global_object(base->fourthObject, fn_109_D17C, base->fourthChain);
    fn_109_D374((void**)base->fifthObject);
    __register_global_object(base->fifthObject, fn_109_D13C, base->fifthChain);
}
}
#pragma pop
extern void* const fn_109_D27C_ctor;

__declspec(section ".ctors") extern void* const fn_109_D27C_ctor = (void*)fn_109_D27C;
