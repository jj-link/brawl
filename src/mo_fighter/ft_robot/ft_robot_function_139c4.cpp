#pragma force_active on
extern "C" {
extern unsigned char lbl_120_data_7B00[], lbl_120_data_7AAC[];
void* fn_120_13A88(void*, short);
void __register_global_object(void*, void*, void*);
}

struct RobotBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_120_data_7B00;
        return active = 1;
    }
};
struct RobotDerived : RobotBase {
    inline unsigned char initialize() {
        unsigned char initialized = RobotBase::initialize();
        vtable = lbl_120_data_7AAC;
        return initialized;
    }
};
struct RobotRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern signed char lbl_120_bss_378;
extern RobotDerived lbl_120_bss_37C;
extern RobotRegistration lbl_120_bss_318;
}

extern "C" RobotDerived* fn_120_139C4() {
    if (lbl_120_bss_378 == 0) {
        const unsigned char initialized = lbl_120_bss_37C.initialize();
        __register_global_object(&lbl_120_bss_37C,
            reinterpret_cast<void*>(fn_120_13A88), &lbl_120_bss_318);
        lbl_120_bss_378 = initialized;
    }
    return &lbl_120_bss_37C;
}
