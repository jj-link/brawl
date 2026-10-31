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
extern ZakoGlobals lbl_126_bss_F8;
void* fn_126_D704(void*);
void* fn_126_D590(void*, short);
void* fn_126_D74C(void*);
void* fn_126_D7A4(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_126_D6A0() {
    ZakoGlobals* base = &lbl_126_bss_F8;
    unsigned char (ZakoGlobals::*chain)[0xC] = &ZakoGlobals::firstChain;
    fn_126_D704(base->firstObject);
    __register_global_object(base->firstObject, fn_126_D590, &(base->*chain));
    fn_126_D74C(base->secondObject);
    __register_global_object(base->secondObject, fn_126_D7A4, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_126_D6A0_ctor = (void*)fn_126_D6A0;
