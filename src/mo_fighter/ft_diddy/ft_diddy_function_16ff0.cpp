#pragma force_active on
extern "C" {
extern unsigned char lbl_115_data_84FC[], lbl_115_data_84A8[];
void* fn_115_170B4(void*, short);
void __register_global_object(void*, void*, void*);
}

// Original RTTI identifies the base as Input and the derived object as IpNull.
// The existing tables and singleton storage remain owned by their original units.
struct DiddyInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_115_data_84FC;
        return active = 1;
    }
};
struct DiddyInputNullSingleton : DiddyInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = DiddyInputBase::initialize();
        vtable = lbl_115_data_84A8;
        return initialized;
    }
};
struct DiddyInputNullRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_115_bss_388;
extern DiddyInputNullSingleton lbl_115_bss_38C;
extern DiddyInputNullRegistration lbl_115_bss_328;
}

extern "C" DiddyInputNullSingleton* fn_115_16FF0() {
    if (lbl_115_bss_388 == 0) {
        const unsigned char initialized = lbl_115_bss_38C.initialize();
        __register_global_object(&lbl_115_bss_38C,
            reinterpret_cast<void*>(fn_115_170B4), &lbl_115_bss_328);
        lbl_115_bss_388 = initialized;
    }
    return &lbl_115_bss_38C;
}
