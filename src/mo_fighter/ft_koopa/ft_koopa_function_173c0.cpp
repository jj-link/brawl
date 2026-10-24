#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

struct Registration {
    void* next;
    void* destructor;
    void* object;
};

struct KoopaGlobals {
    Registration registration1;
    unsigned char object1[4];
    Registration registration2;
    unsigned char object2[4];
};

extern "C" {
extern KoopaGlobals lbl_102_bss_510;
void fn_102_17424(void*);
void fn_102_17434(void*);
void* fn_102_17380(void*, short);
void* fn_102_17340(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_102_173C0() {
    Registration KoopaGlobals::* reg = &KoopaGlobals::registration1;

    fn_102_17424(lbl_102_bss_510.object1);
    __register_global_object(
        lbl_102_bss_510.object1,
        reinterpret_cast<void*>(fn_102_17380),
        &(lbl_102_bss_510.*reg));

    fn_102_17434(lbl_102_bss_510.object2);
    __register_global_object(
        lbl_102_bss_510.object2,
        reinterpret_cast<void*>(fn_102_17340),
        &lbl_102_bss_510.registration2);
}

__declspec(section ".ctors") extern void* const fn_102_173C0_ctor = (void*)fn_102_173C0;
