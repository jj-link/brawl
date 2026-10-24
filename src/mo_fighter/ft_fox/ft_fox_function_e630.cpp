#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct FoxGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x168];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
    unsigned char chain3[0xC];
    unsigned char obj3[0x14];
};

extern "C" {
extern FoxGlobals lbl_97_bss_8;

void* fn_97_E6B0(void*);
void* fn_97_AD64(void*, short);
void* fn_97_E6F8(void*);
void* fn_97_E750(void*, short);
void fn_97_E7D4(void**);
void* fn_97_E7E4(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_97_E630() {
    FoxGlobals* base = &lbl_97_bss_8;
    unsigned char (FoxGlobals::*chain)[0xC] = &FoxGlobals::chain1;

    fn_97_E6B0(base->obj1);
    __register_global_object(
        base->obj1,
        reinterpret_cast<void*>(fn_97_AD64),
        &(base->*chain));

    fn_97_E6F8(base->obj2);
    __register_global_object(
        base->obj2,
        reinterpret_cast<void*>(fn_97_E750),
        base->chain2);

    fn_97_E7D4(reinterpret_cast<void**>(base->obj3));
    __register_global_object(
        base->obj3,
        reinterpret_cast<void*>(fn_97_E7E4),
        base->chain3);
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_97_E630_ctor = (void*)fn_97_E630;
