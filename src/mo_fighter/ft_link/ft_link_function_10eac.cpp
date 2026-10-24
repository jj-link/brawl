#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct LinkGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[4];
    unsigned char chain2[0xC];
    unsigned char obj2[4];
    unsigned char chain3[0xC];
    unsigned char obj3[4];
};

extern "C" {
extern LinkGlobals lbl_93_bss_180;

void fn_93_10F2C(unsigned char*);
void fn_93_10F3C(unsigned char*);
void** fn_93_10F4C(void**);

void* fn_93_10E6C(void*, short);
void* fn_93_10E2C(void*, short);
void* fn_93_10DEC(void*, short);

void* __register_global_object(void*, void* (*)(void*, short), void*);
}

extern "C" void fn_93_10EAC() {
    LinkGlobals* base = &lbl_93_bss_180;
    unsigned char (LinkGlobals::*chain)[0xC] = &LinkGlobals::chain1;

    fn_93_10F2C(base->obj1);
    __register_global_object(base->obj1, fn_93_10E6C, &(base->*chain));

    fn_93_10F3C(base->obj2);
    __register_global_object(base->obj2, fn_93_10E2C, base->chain2);

    fn_93_10F4C(reinterpret_cast<void**>(base->obj3));
    __register_global_object(base->obj3, fn_93_10DEC, base->chain3);
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_93_10EAC_ctor = (void*)fn_93_10EAC;
