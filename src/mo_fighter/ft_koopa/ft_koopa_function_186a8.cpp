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
    Registration registration3;
    unsigned char object3[4];
    Registration registration4;
    unsigned char object4[4];
    Registration registration5;
    unsigned char object5[4];
};

extern "C" {
extern KoopaGlobals lbl_102_bss_530;
void fn_102_18760(void*);
void fn_102_18770(void*);
void fn_102_18780(void*);
void fn_102_18790(void*);
void fn_102_187A0(void*);
void* fn_102_18668(void*, short);
void* fn_102_18628(void*, short);
void* fn_102_185E8(void*, short);
void* fn_102_185A8(void*, short);
void* fn_102_18568(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_102_186A8() {
    Registration KoopaGlobals::* reg = &KoopaGlobals::registration1;

    fn_102_18760(lbl_102_bss_530.object1);
    __register_global_object(
        lbl_102_bss_530.object1,
        reinterpret_cast<void*>(fn_102_18668),
        &(lbl_102_bss_530.*reg));

    fn_102_18770(lbl_102_bss_530.object2);
    __register_global_object(
        lbl_102_bss_530.object2,
        reinterpret_cast<void*>(fn_102_18628),
        &lbl_102_bss_530.registration2);

    fn_102_18780(lbl_102_bss_530.object3);
    __register_global_object(
        lbl_102_bss_530.object3,
        reinterpret_cast<void*>(fn_102_185E8),
        &lbl_102_bss_530.registration3);

    fn_102_18790(lbl_102_bss_530.object4);
    __register_global_object(
        lbl_102_bss_530.object4,
        reinterpret_cast<void*>(fn_102_185A8),
        &lbl_102_bss_530.registration4);

    fn_102_187A0(lbl_102_bss_530.object5);
    __register_global_object(
        lbl_102_bss_530.object5,
        reinterpret_cast<void*>(fn_102_18568),
        &lbl_102_bss_530.registration5);
}

__declspec(section ".ctors") extern void* const fn_102_186A8_ctor = (void*)fn_102_186A8;
