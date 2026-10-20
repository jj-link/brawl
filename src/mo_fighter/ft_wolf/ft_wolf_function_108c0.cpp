#pragma force_active on
extern "C" {
extern unsigned char lbl_125_data_7B5C[], lbl_125_data_7B08[];
extern signed char lbl_125_bss_230;
void* fn_125_10984(void*, short);
void __register_global_object(void*, void*, void*);
}

struct WolfBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_125_data_7B5C;
        return active = 1;
    }
};

struct WolfSingleton : WolfBase {
    inline unsigned char initialize() {
        unsigned char initialized = WolfBase::initialize();
        vtable = lbl_125_data_7B08;
        return initialized;
    }
};

struct WolfRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern WolfSingleton lbl_125_bss_234;
extern WolfRegistration lbl_125_bss_1D0;
}

extern "C" WolfSingleton* fn_125_108C0() {
    if (lbl_125_bss_230 == 0) {
        const unsigned char initialized = lbl_125_bss_234.initialize();
        __register_global_object(&lbl_125_bss_234,
            reinterpret_cast<void*>(fn_125_10984), &lbl_125_bss_1D0);
        lbl_125_bss_230 = initialized;
    }
    return &lbl_125_bss_234;
}
