#pragma force_active on
extern "C" {
extern unsigned char lbl_93_data_8E2C[], lbl_93_data_8DD8[];
void* fn_93_14584(void*, short);
void __register_global_object(void*, void*, void*);
extern signed char lbl_93_bss_220;
}

struct LinkInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_93_data_8E2C;
        return active = 1;
    }
};
struct LinkInputNullSingleton : LinkInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = LinkInputBase::initialize();
        vtable = lbl_93_data_8DD8;
        return initialized;
    }
};
struct LinkInputNullRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern LinkInputNullSingleton lbl_93_bss_224;
extern LinkInputNullRegistration lbl_93_bss_1C0;
}

extern "C" LinkInputNullSingleton* fn_93_144C0() {
    if (lbl_93_bss_220 == 0) {
        const unsigned char initialized = lbl_93_bss_224.initialize();
        __register_global_object(&lbl_93_bss_224,
            reinterpret_cast<void*>(fn_93_14584), &lbl_93_bss_1C0);
        lbl_93_bss_220 = initialized;
    }
    return &lbl_93_bss_224;
}
