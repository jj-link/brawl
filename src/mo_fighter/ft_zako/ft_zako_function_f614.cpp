#pragma force_active on
struct ZakoGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x28];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0x34];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern ZakoGlobals lbl_126_bss_170;
void* fn_126_F678(void*);
void* fn_126_F504(void*, short);
void* fn_126_F6C0(void*);
void* fn_126_F718(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_126_F614() {
    ZakoGlobals* base = &lbl_126_bss_170;
    unsigned char (ZakoGlobals::*chain)[0xC] = &ZakoGlobals::firstChain;
    fn_126_F678(base->firstObject);
    __register_global_object(base->firstObject, fn_126_F504, &(base->*chain));
    fn_126_F6C0(base->secondObject);
    __register_global_object(base->secondObject, fn_126_F718, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_126_F614_ctor = (void*)fn_126_F614;
