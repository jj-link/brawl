#pragma force_active on
extern "C" {
extern unsigned char lbl_116_data_776C[], lbl_116_data_7718[];
void* fn_116_112D4(void* ptr, int count);
void __register_global_object(void*, void*, void*);
}

struct PokeBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_116_data_776C;
        return active = 1;
    }
};
struct PokeSingleton : PokeBase {
    inline unsigned char initialize() {
        unsigned char initialized = PokeBase::initialize();
        vtable = lbl_116_data_7718;
        return initialized;
    }
};
struct PokeRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_116_bss_1E8;
extern PokeSingleton lbl_116_bss_1EC;
extern PokeRegistration lbl_116_bss_170;
}

extern "C" PokeSingleton* fn_116_11210() {
    if (lbl_116_bss_1E8 == 0) {
        const unsigned char initialized = lbl_116_bss_1EC.initialize();
        __register_global_object(&lbl_116_bss_1EC,
            reinterpret_cast<void*>(fn_116_112D4), &lbl_116_bss_170);
        lbl_116_bss_1E8 = initialized;
    }
    return &lbl_116_bss_1EC;
}
