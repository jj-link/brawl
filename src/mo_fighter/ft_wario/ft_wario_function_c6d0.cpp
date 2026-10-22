#pragma force_active on
struct WarioGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x120];
    unsigned char a[8];
    unsigned char b[8];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern WarioGlobals lbl_110_bss_8;
void* fn_110_C754(void*);
void fn_110_C79C(void*, int, int);
void* fn_110_C7A8(void*);
void* fn_110_92FC(void*, short);
void* fn_110_C800(void*, short);
void __register_global_object(void*, void*, void*);
void fn_110_C6D0() {
    WarioGlobals* base = &lbl_110_bss_8;
    unsigned char (WarioGlobals::*chain)[0xC] = &WarioGlobals::chain1;
    fn_110_C754(base->obj1);
    __register_global_object(base->obj1, (void*)fn_110_92FC, &(base->*chain));
    fn_110_C79C(base->a, 0xFF, 0);
    fn_110_C79C(base->b, 0xFF, 1);
    fn_110_C7A8(base->obj2);
    __register_global_object(base->obj2, (void*)fn_110_C800, base->chain2);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_110_C6D0_ctor = (void*)fn_110_C6D0;
