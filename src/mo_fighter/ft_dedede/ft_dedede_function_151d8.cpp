extern "C" {
extern unsigned char lbl_117_data_92F4[], lbl_117_data_92A0[];
void* fn_117_1529C(void*, short);
void __register_global_object(void*, void*, void*);
}

// Original RTTI identifies the base as Input and the derived object as IpNull.
// The existing tables and singleton storage remain owned by their original units.
struct DededeInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_117_data_92F4;
        return active = 1;
    }
};
struct DededeInputNullSingleton : DededeInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = DededeInputBase::initialize();
        vtable = lbl_117_data_92A0;
        return initialized;
    }
};
struct DededeInputNullRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_117_bss_388;
extern DededeInputNullSingleton lbl_117_bss_38C;
extern DededeInputNullRegistration lbl_117_bss_328;
}

extern "C" DededeInputNullSingleton* fn_117_151D8() {
    if (lbl_117_bss_388 == 0) {
        const unsigned char initialized = lbl_117_bss_38C.initialize();
        __register_global_object(&lbl_117_bss_38C,
            reinterpret_cast<void*>(fn_117_1529C), &lbl_117_bss_328);
        lbl_117_bss_388 = initialized;
    }
    return &lbl_117_bss_38C;
}
