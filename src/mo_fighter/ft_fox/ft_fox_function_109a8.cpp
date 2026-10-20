#pragma force_active on
extern "C" {
extern unsigned char lbl_97_data_7B18[], lbl_97_data_7AC4[];
void* fn_97_10A6C(void*, short);
void __register_global_object(void*, void*, void*);
}

struct FoxInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_97_data_7B18;
        return active = 1;
    }
};
struct FoxInputNullSingleton : FoxInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = FoxInputBase::initialize();
        vtable = lbl_97_data_7AC4;
        return initialized;
    }
};
struct FoxInputNullRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_97_bss_230;
extern FoxInputNullSingleton lbl_97_bss_234;
extern FoxInputNullRegistration lbl_97_bss_1D0;
}

extern "C" FoxInputNullSingleton* fn_97_109A8() {
    if (lbl_97_bss_230 == 0) {
        const unsigned char initialized = lbl_97_bss_234.initialize();
        __register_global_object(&lbl_97_bss_234,
            reinterpret_cast<void*>(fn_97_10A6C), &lbl_97_bss_1D0);
        lbl_97_bss_230 = initialized;
    }
    return &lbl_97_bss_234;
}
