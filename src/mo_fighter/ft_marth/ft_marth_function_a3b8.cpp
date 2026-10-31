#pragma force_active on
struct MarthGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x158];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern MarthGlobals lbl_106_bss_8;
void* fn_106_A41C(void*);
void* fn_106_7C78(void*, short);
void* fn_106_A464(void*);
void* fn_106_A4BC(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);
void fn_106_A3B8() {
    MarthGlobals* base = &lbl_106_bss_8;
    unsigned char (MarthGlobals::*chain)[0xC] = &MarthGlobals::chain1;
    fn_106_A41C(base->obj1);
    __register_global_object(base->obj1, fn_106_7C78, &(base->*chain));
    fn_106_A464(base->obj2);
    __register_global_object(base->obj2, fn_106_A4BC, base->chain2);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_106_A3B8_ctor = (void*)fn_106_A3B8;
