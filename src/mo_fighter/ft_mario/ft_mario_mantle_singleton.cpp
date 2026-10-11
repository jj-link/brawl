struct MarioMantleSingleton {
    unsigned char enabled;
    unsigned char padding[3];
    void* vtable;
};
struct MarioMantleSingletonRegistration {
    void* next;
    void* object;
    void* destructor;
};
extern "C" {
extern signed char lbl_91_bss_274;
extern MarioMantleSingleton lbl_91_bss_278;
extern MarioMantleSingletonRegistration lbl_91_bss_208;
extern unsigned char lbl_91_data_8054[];
extern unsigned char lbl_91_data_8000[];
void* fn_91_100C0(void*, short);
void __register_global_object(void*, void*, void*);
MarioMantleSingleton* fn_91_FFFC(void*) {
    if (lbl_91_bss_274 == 0) {
        lbl_91_bss_278.vtable = lbl_91_data_8054;
        lbl_91_bss_278.enabled = 1;
        lbl_91_bss_278.vtable = lbl_91_data_8000;
        __register_global_object(&lbl_91_bss_278, reinterpret_cast<void*>(fn_91_100C0), &lbl_91_bss_208);
        lbl_91_bss_274 = 1;
    }
    return &lbl_91_bss_278;
}
}
