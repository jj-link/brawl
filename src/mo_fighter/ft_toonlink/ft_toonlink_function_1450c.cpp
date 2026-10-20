#pragma force_active on
extern "C" {
extern unsigned char lbl_121_data_8F4C[], lbl_121_data_8EF8[];
void* fn_121_145D0(void*, short);
void __register_global_object(void*, void*, void*);
}

struct ToonlinkInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_121_data_8F4C;
        return active = 1;
    }
};
struct ToonlinkInputSingleton : ToonlinkInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = ToonlinkInputBase::initialize();
        vtable = lbl_121_data_8EF8;
        return initialized;
    }
};
struct ToonlinkInputRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_121_bss_220;
extern ToonlinkInputSingleton lbl_121_bss_224;
extern ToonlinkInputRegistration lbl_121_bss_1C0;
}

extern "C" ToonlinkInputSingleton* fn_121_1450C() {
    if (lbl_121_bss_220 == 0) {
        const unsigned char initialized = lbl_121_bss_224.initialize();
        __register_global_object(&lbl_121_bss_224,
            reinterpret_cast<void*>(fn_121_145D0), &lbl_121_bss_1C0);
        lbl_121_bss_220 = initialized;
    }
    return &lbl_121_bss_224;
}
