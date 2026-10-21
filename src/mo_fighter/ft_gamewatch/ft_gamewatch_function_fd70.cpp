#pragma force_active on
struct GwGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0xE8];
    unsigned char a[8];
    unsigned char b[8];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern GwGlobals lbl_107_bss_8;
void* fn_107_FDF4(void*);
void* fn_107_BFBC(void*, short);
void fn_107_FE3C(void*, int, int);
void* fn_107_FE48(void*);
void* fn_107_FEA0(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_107_FD70() {
    GwGlobals* base = &lbl_107_bss_8;
    unsigned char (GwGlobals::*chain)[0xC] = &GwGlobals::firstChain;
    fn_107_FDF4(base->firstObject);
    __register_global_object(base->firstObject, fn_107_BFBC, &(base->*chain));
    fn_107_FE3C(base->a, 0xFF, 0);
    fn_107_FE3C(base->b, 0xFF, 1);
    fn_107_FE48(base->secondObject);
    __register_global_object(base->secondObject, fn_107_FEA0, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_107_FD70_ctor = (void*)fn_107_FD70;
