#pragma force_active on
extern "C" {
extern unsigned char lbl_104_data_8110[], lbl_104_data_80BC[];
void* fn_104_12788(void*, short);
void __register_global_object(void*, void*, void*);
}

struct BaseClass {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_104_data_8110;
        return active = 1;
    }
};
struct DerivedClass : BaseClass {
    inline unsigned char initialize() {
        unsigned char initialized = BaseClass::initialize();
        vtable = lbl_104_data_80BC;
        return initialized;
    }
};
struct Registration { void* next; void* object; void* destructor; };

extern "C" {
extern signed char lbl_104_bss_264;
extern DerivedClass lbl_104_bss_268;
extern Registration lbl_104_bss_1F8;
}

extern "C" DerivedClass* fn_104_126C4() {
    if (lbl_104_bss_264 == 0) {
        const unsigned char initialized = lbl_104_bss_268.initialize();
        __register_global_object(&lbl_104_bss_268,
            reinterpret_cast<void*>(fn_104_12788), &lbl_104_bss_1F8);
        lbl_104_bss_264 = initialized;
    }
    return &lbl_104_bss_268;
}
