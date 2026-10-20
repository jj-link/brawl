#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_1118;
extern unsigned char lbl_96_data_CE68[], lbl_96_data_CE14[];
void* fn_96_23ADC(void* p, short flag);
void __register_global_object(void*, void*, void*);
}

struct KirbySingleton {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = (void*)lbl_96_data_CE68;
        return active = 1;
    }
};

struct KirbyDerived : KirbySingleton {
    inline unsigned char initialize() {
        unsigned char initialized = KirbySingleton::initialize();
        vtable = (void*)lbl_96_data_CE14;
        return initialized;
    }
};

struct Registration { void* next; void* object; void* destructor; };

extern "C" {
extern KirbyDerived lbl_96_bss_111C;
extern Registration lbl_96_bss_10B8;
}

extern "C" KirbyDerived* fn_96_23A18() {
    if (lbl_96_bss_1118 == 0) {
        const unsigned char initialized = lbl_96_bss_111C.initialize();
        __register_global_object(&lbl_96_bss_111C,
            reinterpret_cast<void*>(fn_96_23ADC), &lbl_96_bss_10B8);
        lbl_96_bss_1118 = initialized;
    }
    return &lbl_96_bss_111C;
}
