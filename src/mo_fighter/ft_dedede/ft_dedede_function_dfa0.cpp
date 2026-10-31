#pragma force_active on
struct DededeGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x1D8];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern DededeGlobals lbl_117_bss_8;
void* fn_117_E004(void*);
void* fn_117_A140(void*, short);
void* fn_117_E04C(void*);
void* fn_117_E0A4(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);
void fn_117_DFA0() {
    DededeGlobals* base = &lbl_117_bss_8;
    unsigned char (DededeGlobals::*chain)[0xC] = &DededeGlobals::chain1;
    fn_117_E004(base->obj1);
    __register_global_object(base->obj1, fn_117_A140, &(base->*chain));
    fn_117_E04C(base->obj2);
    __register_global_object(base->obj2, fn_117_E0A4, base->chain2);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_117_DFA0_ctor = (void*)fn_117_DFA0;
