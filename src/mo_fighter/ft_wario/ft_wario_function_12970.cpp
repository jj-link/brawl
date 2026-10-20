#pragma force_active on
extern "C" {
extern signed char lbl_110_bss_2B0;
extern unsigned char lbl_110_data_7230[], lbl_110_data_71DC[];
void* fn_110_12A34(void*, short);
void __register_global_object(void*, void*, void*);
}

struct WarioInputBase {
    signed char active;
    void* vtable;
    inline signed char initialize() {
        vtable = lbl_110_data_7230;
        return active = 1;
    }
};
struct WarioInputSingleton : WarioInputBase {
    inline signed char initialize() {
        signed char initialized = WarioInputBase::initialize();
        vtable = lbl_110_data_71DC;
        return initialized;
    }
};
struct WarioInputRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern WarioInputSingleton lbl_110_bss_2B4;
extern WarioInputRegistration lbl_110_bss_228;
}

extern "C" WarioInputSingleton* fn_110_12970() {
    if (lbl_110_bss_2B0 == 0) {
        const signed char initialized = lbl_110_bss_2B4.initialize();
        __register_global_object(&lbl_110_bss_2B4,
            reinterpret_cast<void*>(fn_110_12A34), &lbl_110_bss_228);
        lbl_110_bss_2B0 = initialized;
    }
    return &lbl_110_bss_2B4;
}
