#pragma force_active on
extern "C" {
extern unsigned char lbl_123_data_7234[], lbl_123_data_71E0[];
void* fn_123_13E78(void*, short);
void __register_global_object(void*, void*, void*);
}

struct SonicSomethingBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_123_data_7234;
        return active = 1;
    }
};
struct SonicSomethingDerived : SonicSomethingBase {
    inline unsigned char initialize() {
        unsigned char initialized = SonicSomethingBase::initialize();
        vtable = lbl_123_data_71E0;
        return initialized;
    }
};
struct Registration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_123_bss_3A4;
extern SonicSomethingDerived lbl_123_bss_3A8;
extern Registration lbl_123_bss_338;
}

extern "C" SonicSomethingDerived* fn_123_13DB4() {
    if (lbl_123_bss_3A4 == 0) {
        const unsigned char initialized = lbl_123_bss_3A8.initialize();
        __register_global_object(&lbl_123_bss_3A8,
            reinterpret_cast<void*>(fn_123_13E78), &lbl_123_bss_338);
        lbl_123_bss_3A4 = initialized;
    }
    return &lbl_123_bss_3A8;
}
