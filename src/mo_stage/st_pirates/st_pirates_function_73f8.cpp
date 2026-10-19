#pragma force_active on
extern "C" {

extern unsigned char lbl_52_bss_B8[8];
extern unsigned char lbl_52_bss_C0[0x68];
extern unsigned char lbl_52_bss_30[0xC];
extern float lbl_52_rodata_12C[5];
void __register_global_object(void* object, void* destructor, void* chain);
void* fn_52_5E54(void* p, int size);

struct Obj {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    char pad1[0x38 - 0x30];
    unsigned f38;
    char pad2[0x68 - 0x3C];
};

void* fn_52_73F8() {
    if (*(signed char*)&lbl_52_bss_B8[0] == 0) {
        Obj* obj = reinterpret_cast<Obj*>(&lbl_52_bss_C0[0]);
        unsigned x = obj->f38;
        float f = lbl_52_rodata_12C[0];
        obj->f24 = f;
        obj->f28 = f;
        obj->f2c = f;
        obj->f38 = x & ~0x1Fu;
        __register_global_object(obj, reinterpret_cast<void*>(fn_52_5E54), &lbl_52_bss_30[0]);
        *(signed char*)&lbl_52_bss_B8[0] = 1;
    }
    return &lbl_52_bss_C0[0];
}

} // extern "C"
