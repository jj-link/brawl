#pragma force_active on
extern "C" {
extern signed char lbl_92_bss_2F8;
extern unsigned char lbl_92_data_73F8[], lbl_92_data_73A4[];
extern void* fn_92_12840(void*, short);
extern void __register_global_object(void*, void*, void*);
}

struct DonkeyInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_92_data_73F8;
        return active = 1;
    }
};

struct DonkeyInputSingleton : DonkeyInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = DonkeyInputBase::initialize();
        vtable = lbl_92_data_73A4;
        return initialized;
    }
};

struct DonkeyInputRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern DonkeyInputSingleton lbl_92_bss_2FC;
extern DonkeyInputRegistration lbl_92_bss_298;
}

extern "C" DonkeyInputSingleton* fn_92_1277C() {
    if (lbl_92_bss_2F8 == 0) {
        const unsigned char initialized = lbl_92_bss_2FC.initialize();
        __register_global_object(&lbl_92_bss_2FC,
            reinterpret_cast<void*>(fn_92_12840), &lbl_92_bss_298);
        lbl_92_bss_2F8 = initialized;
    }
    return &lbl_92_bss_2FC;
}
