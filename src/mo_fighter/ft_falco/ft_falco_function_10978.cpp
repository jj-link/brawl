#pragma force_active on
extern "C" {
extern unsigned char lbl_108_data_7B10[], lbl_108_data_7ABC[];
void* fn_108_10A3C(void*, short);
void __register_global_object(void*, void*, void*);
}

struct FalcoInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_108_data_7B10;
        return active = 1;
    }
};
struct FalcoInputNullSingleton : FalcoInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = FalcoInputBase::initialize();
        vtable = lbl_108_data_7ABC;
        return initialized;
    }
};
struct FalcoInputNullRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern signed char lbl_108_bss_208;
extern FalcoInputNullSingleton lbl_108_bss_20C;
extern FalcoInputNullRegistration lbl_108_bss_1A8;
}

extern "C" FalcoInputNullSingleton* fn_108_10978() {
    if (lbl_108_bss_208 == 0) {
        const unsigned char initialized = lbl_108_bss_20C.initialize();
        __register_global_object(&lbl_108_bss_20C,
            reinterpret_cast<void*>(fn_108_10A3C), &lbl_108_bss_1A8);
        lbl_108_bss_208 = initialized;
    }
    return &lbl_108_bss_20C;
}
