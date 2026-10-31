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
    unsigned char object1[0x1C8];
    Registration registration2;
    unsigned char object2[0xC];
};

extern "C" {
extern KoopaGlobals lbl_102_bss_8;
void fn_102_BEF8(void*);
void* fn_102_8C1C(void*, short);
void fn_102_BF40(void*);
void* fn_102_BF98(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_102_BE94() {
    Registration KoopaGlobals::* reg = &KoopaGlobals::registration1;

    fn_102_BEF8(lbl_102_bss_8.object1);
    __register_global_object(
        lbl_102_bss_8.object1,
        reinterpret_cast<void*>(fn_102_8C1C),
        &(lbl_102_bss_8.*reg));

    fn_102_BF40(lbl_102_bss_8.object2);
    __register_global_object(
        lbl_102_bss_8.object2,
        reinterpret_cast<void*>(fn_102_BF98),
        &lbl_102_bss_8.registration2);
}

__declspec(section ".ctors") extern void* const fn_102_BE94_ctor = (void*)fn_102_BE94;
