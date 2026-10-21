#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

struct GlobalRegistration {
    void* next;
    void* destructor;
    void* object;
};

struct KoopaGlobals {
    GlobalRegistration registration1;
    unsigned char object1[4];
    GlobalRegistration registration2;
    unsigned char object2[4];
};

extern "C" {
extern KoopaGlobals lbl_102_bss_240;
void fn_102_E104(void*);
void fn_102_E114(void*);
void* fn_102_E020(void*, short);
void* fn_102_E060(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_102_E0A0() {
    GlobalRegistration KoopaGlobals::* registration =
        &KoopaGlobals::registration1;

    fn_102_E104(lbl_102_bss_240.object1);
    __register_global_object(
        lbl_102_bss_240.object1,
        reinterpret_cast<void*>(fn_102_E020),
        &(lbl_102_bss_240.*registration));

    fn_102_E114(lbl_102_bss_240.object2);
    __register_global_object(
        lbl_102_bss_240.object2,
        reinterpret_cast<void*>(fn_102_E060),
        &lbl_102_bss_240.registration2);
}

__declspec(section ".ctors") extern void* const fn_102_E0A0_ctor = (void*)fn_102_E0A0;
