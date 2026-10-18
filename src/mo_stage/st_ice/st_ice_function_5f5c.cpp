#pragma force_active on
extern "C" {
extern signed char lbl_62_bss_C8;
extern unsigned char lbl_62_bss_D0[];
extern unsigned char lbl_62_bss_40[];
extern float lbl_62_rodata_84;
void fn_62_4948(void);
void __register_global_object(void*, void*, void*);
}

struct Fn62Obj {
    char pad0[0x24];
    float a;
    float b;
    float c;
    char pad1[0x8];
    unsigned int d;
};

extern "C" void* fn_62_5F5C(void) {
    if (lbl_62_bss_C8 == 0) {
        Fn62Obj* o = (Fn62Obj*)lbl_62_bss_D0;
        o->a = lbl_62_rodata_84;
        o->b = lbl_62_rodata_84;
        o->c = lbl_62_rodata_84;
        o->d = o->d & ~31u;
        __register_global_object(lbl_62_bss_D0, (void*)fn_62_4948, lbl_62_bss_40);
        lbl_62_bss_C8 = 1;
    }
    return lbl_62_bss_D0;
}
