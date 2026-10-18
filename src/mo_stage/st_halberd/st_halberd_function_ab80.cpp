#pragma force_active on
struct Bss50Obj {
    char pad0[0x24];
    float a;
    float b;
    float c;
    char pad1[8];
    unsigned int d;
};

extern "C" {
extern signed char lbl_57_bss_48;
extern Bss50Obj lbl_57_bss_50;
extern unsigned char lbl_57_bss_24[];
extern float lbl_57_rodata_274;
void fn_57_9800(void);
void __register_global_object(void*, void*, void*);

void* fn_57_AB80(void) {
    if (lbl_57_bss_48 == 0) {
        Bss50Obj* obj = &lbl_57_bss_50;
        float f = lbl_57_rodata_274;
        obj->a = f;
        obj->b = f;
        obj->c = f;
        obj->d = obj->d & ~31u;
        __register_global_object(obj, (void*)fn_57_9800, lbl_57_bss_24);
        lbl_57_bss_48 = 1;
    }
    return &lbl_57_bss_50;
}
}
