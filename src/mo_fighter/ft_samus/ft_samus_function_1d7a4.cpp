#pragma force_active on
extern "C" {
extern unsigned char lbl_94_data_D084[], lbl_94_data_D030[];
extern signed char lbl_94_bss_3BC;
void* fn_94_1D868(void* p, short n);
void __register_global_object(void*, void*, void*);
}

struct SamusInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_94_data_D084;
        return active = 1;
    }
};
struct SamusInputDerived : SamusInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = SamusInputBase::initialize();
        vtable = lbl_94_data_D030;
        return initialized;
    }
};
struct SamusInputRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern SamusInputDerived lbl_94_bss_3C0;
extern SamusInputRegistration lbl_94_bss_350;
}

extern "C" SamusInputDerived* fn_94_1D7A4() {
    if (lbl_94_bss_3BC == 0) {
        const unsigned char initialized = lbl_94_bss_3C0.initialize();
        __register_global_object(&lbl_94_bss_3C0,
            reinterpret_cast<void*>(fn_94_1D868), &lbl_94_bss_350);
        lbl_94_bss_3BC = initialized;
    }
    return &lbl_94_bss_3C0;
}
