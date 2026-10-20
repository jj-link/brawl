#pragma force_active on
extern "C" {
extern unsigned char lbl_102_data_8444[], lbl_102_data_83F0[];
void* fn_102_1BDA8(void*, short);
void __register_global_object(void*, void*, void*);
}

struct KoopaInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_102_data_8444;
        return active = 1;
    }
};
struct KoopaInputNullSingleton : KoopaInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = KoopaInputBase::initialize();
        vtable = lbl_102_data_83F0;
        return initialized;
    }
};
struct KoopaInputNullRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_102_bss_5E0;
extern KoopaInputNullSingleton lbl_102_bss_5E4;
extern KoopaInputNullRegistration lbl_102_bss_580;
}

extern "C" KoopaInputNullSingleton* fn_102_1BCE4() {
    if (lbl_102_bss_5E0 == 0) {
        const unsigned char initialized = lbl_102_bss_5E4.initialize();
        __register_global_object(&lbl_102_bss_5E4,
            reinterpret_cast<void*>(fn_102_1BDA8), &lbl_102_bss_580);
        lbl_102_bss_5E0 = initialized;
    }
    return &lbl_102_bss_5E4;
}
