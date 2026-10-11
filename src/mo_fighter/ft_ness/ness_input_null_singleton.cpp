extern "C" {
extern unsigned char lbl_101_data_98E0[], lbl_101_data_988C[];
void* fn_101_15DAC(void*, short);
void __register_global_object(void*, void*, void*);
}

// Original RTTI identifies the base as Input and the derived object as IpNull.
// Keep the assembly-owned tables and storage while reconstructing their initialization.
struct NessInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_101_data_98E0;
        return active = 1;
    }
};
struct NessInputNullSingleton : NessInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = NessInputBase::initialize();
        vtable = lbl_101_data_988C;
        return initialized;
    }
};
struct NessInputNullRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_101_bss_2D8;
extern NessInputNullSingleton lbl_101_bss_2DC;
extern NessInputNullRegistration lbl_101_bss_260;
}

extern "C" NessInputNullSingleton* fn_101_15CE8() {
    if (lbl_101_bss_2D8 == 0) {
        const unsigned char initialized = lbl_101_bss_2DC.initialize();
        __register_global_object(&lbl_101_bss_2DC,
            reinterpret_cast<void*>(fn_101_15DAC), &lbl_101_bss_260);
        lbl_101_bss_2D8 = initialized;
    }
    return &lbl_101_bss_2DC;
}
