#pragma force_active on
struct IceClimberGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x208];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern IceClimberGlobals lbl_105_bss_8;
void* fn_105_12CDC(void*);
void* fn_105_D770(void*, short);
void* fn_105_12D24(void*);
void* fn_105_12D7C(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);
void fn_105_12C78() {
    IceClimberGlobals* base = &lbl_105_bss_8;
    unsigned char (IceClimberGlobals::*chain)[0xC] = &IceClimberGlobals::chain1;
    fn_105_12CDC(base->obj1);
    __register_global_object(base->obj1, fn_105_D770, &(base->*chain));
    fn_105_12D24(base->obj2);
    __register_global_object(base->obj2, fn_105_12D7C, base->chain2);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_105_12C78_ctor = (void*)fn_105_12C78;
