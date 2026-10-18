#pragma force_active on
extern "C" {

extern signed char lbl_50_bss_B8;
extern float lbl_50_rodata_C8;
extern void fn_50_4C00(void*);
extern void __register_global_object(void*, void*, void*);

struct Obj50 {
    unsigned char pad_00[0x24];
    float field_24;
    float field_28;
    float field_2C;
    unsigned char pad_30[8];
    unsigned int vtable;
    unsigned char pad_3C[0x2C];
};

extern Obj50 lbl_50_bss_C0;
struct DestructorChain50 { void* next; void* object; void* destructor; };
extern DestructorChain50 lbl_50_bss_30;

Obj50* fn_50_61C8() {
    if (lbl_50_bss_B8 == 0) {
        lbl_50_bss_C0.field_24 = lbl_50_rodata_C8;
        lbl_50_bss_C0.field_28 = lbl_50_rodata_C8;
        lbl_50_bss_C0.field_2C = lbl_50_rodata_C8;
        lbl_50_bss_C0.vtable &= ~0x1F;
        __register_global_object(&lbl_50_bss_C0, fn_50_4C00, &lbl_50_bss_30);
        lbl_50_bss_B8 = 1;
    }
    return &lbl_50_bss_C0;
}

}
