#pragma force_active on
extern "C" {
extern unsigned char lbl_109_data_72E8[], lbl_109_data_7294[];
void* fn_109_11620(void*, short);
void __register_global_object(void*, void*, void*);
}

struct GanonBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_109_data_72E8;
        return active = 1;
    }
};
struct GanonDerived : GanonBase {
    inline unsigned char initialize() {
        unsigned char initialized = GanonBase::initialize();
        vtable = lbl_109_data_7294;
        return initialized;
    }
};
struct GanonRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_109_bss_264;
extern GanonDerived lbl_109_bss_268;
extern GanonRegistration lbl_109_bss_1F8;
}

extern "C" GanonDerived* fn_109_1155C() {
    if (lbl_109_bss_264 == 0) {
        const unsigned char initialized = lbl_109_bss_268.initialize();
        __register_global_object(&lbl_109_bss_268,
            reinterpret_cast<void*>(fn_109_11620), &lbl_109_bss_1F8);
        lbl_109_bss_264 = initialized;
    }
    return &lbl_109_bss_268;
}
