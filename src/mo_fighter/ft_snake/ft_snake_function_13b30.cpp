#pragma force_active on
struct SnakeGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x118];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern SnakeGlobals lbl_122_bss_8;
void* fn_122_13B94(void*);
void* fn_122_F1C8(void*, short);
void* fn_122_13BDC(void*);
void* fn_122_13C34(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_122_13B30() {
    SnakeGlobals* base = &lbl_122_bss_8;
    unsigned char (SnakeGlobals::*chain)[0xC] = &SnakeGlobals::firstChain;
    fn_122_13B94(base->firstObject);
    __register_global_object(base->firstObject, fn_122_F1C8, &(base->*chain));
    fn_122_13BDC(base->secondObject);
    __register_global_object(base->secondObject, fn_122_13C34, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_122_13B30_ctor = (void*)fn_122_13B30;
