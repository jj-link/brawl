#pragma force_active on
extern "C" {
extern signed char lbl_105_bss_380;
extern unsigned char lbl_105_data_8DF0[], lbl_105_data_8D9C[];
void* fn_105_1828C(void*, short);
void __register_global_object(void*, void*, void*);
}

struct IceClimberInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_105_data_8DF0;
        return active = 1;
    }
};
struct IceClimberInputSingleton : IceClimberInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = IceClimberInputBase::initialize();
        vtable = lbl_105_data_8D9C;
        return initialized;
    }
};
struct IceClimberInputRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern IceClimberInputSingleton lbl_105_bss_384;
extern IceClimberInputRegistration lbl_105_bss_320;
}

extern "C" IceClimberInputSingleton* fn_105_181C8() {
    if (lbl_105_bss_380 == 0) {
        const unsigned char initialized = lbl_105_bss_384.initialize();
        __register_global_object(&lbl_105_bss_384,
            reinterpret_cast<void*>(fn_105_1828C), &lbl_105_bss_320);
        lbl_105_bss_380 = initialized;
    }
    return &lbl_105_bss_384;
}
