#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct MarioGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0xB0];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xB0];
    unsigned char thirdChain[0xC];
    unsigned char thirdObject[0xC];
    unsigned char fourthChain[0xC];
    unsigned char fourthObject[0xC];
};

extern "C" {
extern MarioGlobals lbl_91_bss_8;

void* fn_91_DB60(void*);
void* fn_91_DBEC(void*);
void* fn_91_DC34(void*);
void* fn_91_DD10(void*);
void* fn_91_A30C(void*, short);
void* fn_91_A188(void*, short);
void* fn_91_DC8C(void*, short);
void* fn_91_DD68(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_91_DAC4() {
    MarioGlobals* base = &lbl_91_bss_8;
    unsigned char (MarioGlobals::*chain)[0xC] = &MarioGlobals::firstChain;

    fn_91_DB60(base->firstObject);
    __register_global_object(base->firstObject, fn_91_A30C, &(base->*chain));

    fn_91_DBEC(base->secondObject);
    __register_global_object(base->secondObject, fn_91_A188, base->secondChain);

    fn_91_DC34(base->thirdObject);
    __register_global_object(base->thirdObject, fn_91_DC8C, base->thirdChain);

    fn_91_DD10(base->fourthObject);
    __register_global_object(base->fourthObject, fn_91_DD68, base->fourthChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_91_DAC4_ctor = (void*)fn_91_DAC4;
