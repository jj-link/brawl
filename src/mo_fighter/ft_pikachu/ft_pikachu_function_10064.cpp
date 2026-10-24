#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

struct PikachuGlobals {
    unsigned char reg1[0x0C];
    unsigned char obj1[0x04];
    unsigned char reg2[0x0C];
    unsigned char obj2[0x04];
    unsigned char reg3[0x0C];
    unsigned char obj3[0x04];
};

extern "C" {
extern PikachuGlobals lbl_98_bss_220;
void fn_98_100E4(void*);
void fn_98_100F4(void*);
void fn_98_10104(void*);
void* fn_98_10020(void*, int);
void* fn_98_FFE0(void*, int);
void* fn_98_FF98(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_98_10064() {
    PikachuGlobals* base = &lbl_98_bss_220;
    unsigned char (PikachuGlobals::*reg1_ptr)[0x0C] = &PikachuGlobals::reg1;

    fn_98_100E4(base->obj1);
    __register_global_object(base->obj1, (void*)fn_98_10020, &(base->*reg1_ptr));

    fn_98_100F4(base->obj2);
    __register_global_object(base->obj2, (void*)fn_98_FFE0, base->reg2);

    fn_98_10104(base->obj3);
    __register_global_object(base->obj3, (void*)fn_98_FF98, base->reg3);
}

__declspec(section ".ctors") extern void* const fn_98_10064_ctor;

__declspec(section ".ctors") extern void* const fn_98_10064_ctor = (void*)fn_98_10064;
