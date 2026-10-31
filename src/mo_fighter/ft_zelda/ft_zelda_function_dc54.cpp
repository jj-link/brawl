#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct ZeldaGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x148];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};

extern "C" {
extern ZeldaGlobals lbl_104_bss_8;
void* fn_104_DCB8(void*);
void* fn_104_A474(void*, short);
void* fn_104_DD00(void*);
void* fn_104_DD58(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);

void fn_104_DC54() {
    ZeldaGlobals* base = &lbl_104_bss_8;
    unsigned char (ZeldaGlobals::*chain)[0xC] = &ZeldaGlobals::firstChain;
    fn_104_DCB8(base->firstObject);
    __register_global_object(base->firstObject, fn_104_A474, &(base->*chain));
    fn_104_DD00(base->secondObject);
    __register_global_object(base->secondObject, fn_104_DD58, base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_104_DC54_ctor = (void*)fn_104_DC54;
