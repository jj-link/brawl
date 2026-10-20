#pragma force_active on
extern "C" {
extern unsigned char lbl_122_data_E28C[], lbl_122_data_E238[];
void* fn_122_18C9C(void*, short);
void __register_global_object(void*, void*, void*);
}

struct SnakeInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_122_data_E28C;
        return active = 1;
    }
};
struct SnakeInputSingleton : SnakeInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = SnakeInputBase::initialize();
        vtable = lbl_122_data_E238;
        return initialized;
    }
};
struct SnakeInputRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_122_bss_238;
extern SnakeInputSingleton lbl_122_bss_23C;
extern SnakeInputRegistration lbl_122_bss_1C0;
}

extern "C" SnakeInputSingleton* fn_122_18BD8() {
    if (lbl_122_bss_238 == 0) {
        const unsigned char initialized = lbl_122_bss_23C.initialize();
        __register_global_object(&lbl_122_bss_23C,
            reinterpret_cast<void*>(fn_122_18C9C), &lbl_122_bss_1C0);
        lbl_122_bss_238 = initialized;
    }
    return &lbl_122_bss_23C;
}
