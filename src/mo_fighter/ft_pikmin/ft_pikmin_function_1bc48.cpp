#pragma force_active on
extern "C" {
extern unsigned char lbl_113_data_813C[], lbl_113_data_80E8[];
void* fn_113_1BD0C(void*, short);
void __register_global_object(void*, void*, void*);
}

struct PikminBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_113_data_813C;
        return active = 1;
    }
};
struct PikminDerived : PikminBase {
    inline unsigned char initialize() {
        unsigned char initialized = PikminBase::initialize();
        vtable = lbl_113_data_80E8;
        return initialized;
    }
};
struct PikminRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern signed char lbl_113_bss_164;
extern PikminDerived lbl_113_bss_168;
extern PikminRegistration lbl_113_bss_F8;
}

extern "C" PikminDerived* fn_113_1BC48() {
    if (lbl_113_bss_164 == 0) {
        const unsigned char initialized = lbl_113_bss_168.initialize();
        __register_global_object(&lbl_113_bss_168,
            reinterpret_cast<void*>(fn_113_1BD0C), &lbl_113_bss_F8);
        lbl_113_bss_164 = initialized;
    }
    return &lbl_113_bss_168;
}
