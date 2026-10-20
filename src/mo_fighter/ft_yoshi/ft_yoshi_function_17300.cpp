#pragma force_active on
extern "C" {
extern unsigned char lbl_95_data_8F04[], lbl_95_data_8EB0[];
void* fn_95_173C4(void*, int);
void __register_global_object(void*, void*, void*);
}

struct YoshiBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_95_data_8F04;
        return active = 1;
    }
};
struct YoshiSingleton : YoshiBase {
    inline unsigned char initialize() {
        unsigned char initialized = YoshiBase::initialize();
        vtable = lbl_95_data_8EB0;
        return initialized;
    }
};
struct YoshiRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_95_bss_4C0;
extern YoshiSingleton lbl_95_bss_4C4;
extern YoshiRegistration lbl_95_bss_460;
}

extern "C" YoshiSingleton* fn_95_17300() {
    if (lbl_95_bss_4C0 == 0) {
        const unsigned char initialized = lbl_95_bss_4C4.initialize();
        __register_global_object(&lbl_95_bss_4C4,
            reinterpret_cast<void*>(fn_95_173C4), &lbl_95_bss_460);
        lbl_95_bss_4C0 = initialized;
    }
    return &lbl_95_bss_4C4;
}
