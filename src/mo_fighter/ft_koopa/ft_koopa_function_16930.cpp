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
extern KoopaGlobals lbl_102_bss_4F0;
void fn_102_16994(void*);
void fn_102_169A4(void*);
void* fn_102_168F0(void*, short);
void* fn_102_168B0(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_102_16930() {
    Registration KoopaGlobals::* reg = &KoopaGlobals::registration1;

    fn_102_16994(lbl_102_bss_4F0.object1);
    __register_global_object(
        lbl_102_bss_4F0.object1,
        reinterpret_cast<void*>(fn_102_168F0),
        &(lbl_102_bss_4F0.*reg));

    fn_102_169A4(lbl_102_bss_4F0.object2);
    __register_global_object(
        lbl_102_bss_4F0.object2,
        reinterpret_cast<void*>(fn_102_168B0),
        &lbl_102_bss_4F0.registration2);
}

__declspec(section ".ctors") extern void* const fn_102_16930_ctor = (void*)fn_102_16930;
