#pragma force_active on
struct ZakoGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x28];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0x18];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern ZakoGlobals lbl_126_bss_8;
void* fn_126_96FC(void*);
void* fn_126_6F58(void*, short);
void* fn_126_9744(void*);
void* fn_126_979C(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_126_9698() {
    ZakoGlobals* base = &lbl_126_bss_8;
    unsigned char (ZakoGlobals::*chain)[0xC] = &ZakoGlobals::firstChain;
    fn_126_96FC(base->firstObject);
    __register_global_object(base->firstObject, fn_126_6F58, &(base->*chain));
    fn_126_9744(base->secondObject);
    __register_global_object(base->secondObject, fn_126_979C, base->secondChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_126_9698_ctor = (void*)fn_126_9698;
