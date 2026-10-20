#pragma force_active on
extern "C" {
extern unsigned char lbl_112_data_7678[], lbl_112_data_7624[];
}

struct FtPitBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_112_data_7678;
        return active = 1;
    }
};
struct FtPitSingleton : FtPitBase {
    inline unsigned char initialize() {
        unsigned char initialized = FtPitBase::initialize();
        vtable = lbl_112_data_7624;
        return initialized;
    }
};
struct FtPitRegistration { void* next; void* object; void* destructor; };

extern "C" {
FtPitBase* fn_112_111F4(FtPitBase* self, short size);
void __register_global_object(void*, void*, void*);
extern signed char lbl_112_bss_248;
extern FtPitSingleton lbl_112_bss_24C;
extern FtPitRegistration lbl_112_bss_1D0;
}

extern "C" FtPitSingleton* fn_112_11130() {
    if (lbl_112_bss_248 == 0) {
        const unsigned char initialized = lbl_112_bss_24C.initialize();
        __register_global_object(&lbl_112_bss_24C,
            reinterpret_cast<void*>(fn_112_111F4), &lbl_112_bss_1D0);
        lbl_112_bss_248 = initialized;
    }
    return &lbl_112_bss_24C;
}
