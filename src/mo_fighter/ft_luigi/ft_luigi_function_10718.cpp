extern "C" {
extern unsigned char lbl_99_data_6E0C[], lbl_99_data_6DB8[];
void* fn_99_107DC(void*, short);
void __register_global_object(void*, void*, void*);
}

// Input's active flag precedes the vtable; IpNull replaces the base table.
// The existing module retains ownership of the tables and singleton storage.
struct LuigiInputBase {
    unsigned char active;
    void* vtable;
    inline unsigned char initialize() {
        vtable = lbl_99_data_6E0C;
        return active = 1;
    }
};
struct LuigiInputNullSingleton : LuigiInputBase {
    inline unsigned char initialize() {
        unsigned char initialized = LuigiInputBase::initialize();
        vtable = lbl_99_data_6DB8;
        return initialized;
    }
};
struct LuigiInputNullRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_99_bss_25C;
extern LuigiInputNullSingleton lbl_99_bss_260;
extern LuigiInputNullRegistration lbl_99_bss_1F0;
}

extern "C" LuigiInputNullSingleton* fn_99_10718() {
    if (lbl_99_bss_25C == 0) {
        const unsigned char initialized = lbl_99_bss_260.initialize();
        __register_global_object(&lbl_99_bss_260,
            reinterpret_cast<void*>(fn_99_107DC), &lbl_99_bss_1F0);
        lbl_99_bss_25C = initialized;
    }
    return &lbl_99_bss_260;
}
