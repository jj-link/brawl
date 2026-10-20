#pragma force_active on
extern "C" {
extern unsigned char lbl_107_data_9F10[], lbl_107_data_9EBC[];
void* fn_107_16614(void*, short);
void __register_global_object(void*, void*, void*);
}

struct GamewatchBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_107_data_9F10;
        return active = 1;
    }
};
struct GamewatchSingleton : GamewatchBase {
    inline unsigned char initialize() {
        unsigned char initialized = GamewatchBase::initialize();
        vtable = lbl_107_data_9EBC;
        return initialized;
    }
};
struct GamewatchRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern signed char lbl_107_bss_294;
extern GamewatchSingleton lbl_107_bss_298;
extern GamewatchRegistration lbl_107_bss_240;
}

extern "C" GamewatchSingleton* fn_107_16550() {
    if (lbl_107_bss_294 == 0) {
        const unsigned char initialized = lbl_107_bss_298.initialize();
        __register_global_object(&lbl_107_bss_298,
            reinterpret_cast<void*>(fn_107_16614), &lbl_107_bss_240);
        lbl_107_bss_294 = initialized;
    }
    return &lbl_107_bss_298;
}
