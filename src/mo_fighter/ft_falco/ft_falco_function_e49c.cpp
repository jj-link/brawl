#pragma force_active on
struct FalcoGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x150];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern FalcoGlobals lbl_108_bss_8;
void* fn_108_E500(void*);
void* fn_108_AC08(void*, short);
void* fn_108_E548(void*);
void* fn_108_E5A0(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);
void fn_108_E49C() {
    FalcoGlobals* base = &lbl_108_bss_8;
    unsigned char (FalcoGlobals::*chain)[0xC] = &FalcoGlobals::chain1;
    fn_108_E500(base->obj1);
    __register_global_object(base->obj1, fn_108_AC08, &(base->*chain));
    fn_108_E548(base->obj2);
    __register_global_object(base->obj2, fn_108_E5A0, base->chain2);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_108_E49C_ctor = (void*)fn_108_E49C;
