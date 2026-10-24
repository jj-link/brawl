#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct ZeldaGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x158];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0x18];
};

extern "C" {
extern ZeldaGlobals lbl_104_bss_340;
void* fn_104_1D800(void*);
void* fn_104_1B940(void*, short);
void* fn_104_1D848(void*);
void* fn_104_1D8A0(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);

void fn_104_1D79C() {
    ZeldaGlobals* base = &lbl_104_bss_340;
    unsigned char (ZeldaGlobals::*chain)[0xC] = &ZeldaGlobals::firstChain;
    fn_104_1D800(base->firstObject);
    __register_global_object(base->firstObject, fn_104_1B940, &(base->*chain));
    fn_104_1D848(base->secondObject);
    __register_global_object(base->secondObject, fn_104_1D8A0, base->secondChain);
}
}

#pragma pop

extern "C" void* const fn_104_1D79C_ctor;

__declspec(section ".ctors") extern void* const fn_104_1D79C_ctor = (void*)fn_104_1D79C;
