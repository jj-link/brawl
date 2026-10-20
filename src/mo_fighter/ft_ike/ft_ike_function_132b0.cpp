#pragma force_active on
extern "C" {
extern unsigned char lbl_119_data_67FC[], lbl_119_data_67A8[];
extern signed char lbl_119_bss_2CC;
void* fn_119_13374(void*, short);
void __register_global_object(void*, void*, void*);
}

struct IkeInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_119_data_67FC;
        return active = 1;
    }
};
struct IkeInputNull : IkeInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = IkeInputBase::initialize();
        vtable = lbl_119_data_67A8;
        return initialized;
    }
};
struct IkeInputRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern IkeInputNull lbl_119_bss_2D0;
extern IkeInputRegistration lbl_119_bss_278;
}

extern "C" IkeInputNull* fn_119_132B0() {
    if (lbl_119_bss_2CC == 0) {
        const unsigned char initialized = lbl_119_bss_2D0.initialize();
        __register_global_object(&lbl_119_bss_2D0,
            reinterpret_cast<void*>(fn_119_13374), &lbl_119_bss_278);
        lbl_119_bss_2CC = initialized;
    }
    return &lbl_119_bss_2D0;
}
