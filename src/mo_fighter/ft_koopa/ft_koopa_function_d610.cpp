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
    unsigned int object1;
    Registration registration2;
    unsigned int object2;
};

extern "C" {
extern KoopaGlobals lbl_102_bss_220;
void fn_102_D674(void*);
void fn_102_D684(unsigned int*);
void* fn_102_D5CC(void*, short);
void* fn_102_D588(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_102_D610() {
    Registration KoopaGlobals::* reg = &KoopaGlobals::registration1;

    fn_102_D674(&lbl_102_bss_220.object1);
    __register_global_object(
        &lbl_102_bss_220.object1,
        reinterpret_cast<void*>(fn_102_D5CC),
        &(lbl_102_bss_220.*reg));

    fn_102_D684(&lbl_102_bss_220.object2);
    __register_global_object(
        &lbl_102_bss_220.object2,
        reinterpret_cast<void*>(fn_102_D588),
        &lbl_102_bss_220.registration2);
}

__declspec(section ".ctors") extern void* const fn_102_D610_ctor = (void*)fn_102_D610;
