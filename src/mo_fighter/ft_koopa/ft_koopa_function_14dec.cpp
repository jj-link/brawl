#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

struct KoopaReg { void* next; void* obj; void* dtor; };
struct KoopaGlobals {
    KoopaReg registration;
    unsigned char parameterObject[0x1E0];
    KoopaReg classRegistration;
    unsigned char classObject[0xC];
};

extern "C" {
extern KoopaGlobals lbl_102_bss_2B0;
void* fn_102_14E50(void*);
void* fn_102_1403C(void*, short);
void* fn_102_14E98(void*);
void* fn_102_14EF0(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_102_14DEC() {
    KoopaReg KoopaGlobals::* reg = &KoopaGlobals::registration;

    fn_102_14E50(lbl_102_bss_2B0.parameterObject);
    __register_global_object(
        lbl_102_bss_2B0.parameterObject,
        reinterpret_cast<void*>(fn_102_1403C),
        &(lbl_102_bss_2B0.*reg));

    fn_102_14E98(lbl_102_bss_2B0.classObject);
    __register_global_object(
        lbl_102_bss_2B0.classObject,
        reinterpret_cast<void*>(fn_102_14EF0),
        &lbl_102_bss_2B0.classRegistration);
}

__declspec(section ".ctors") extern void* const fn_102_14DEC_ctor = (void*)fn_102_14DEC;
