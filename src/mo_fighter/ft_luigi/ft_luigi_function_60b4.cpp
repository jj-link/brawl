// ABI views for the embedded resource handles and module accesser.
struct LuigiResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct LuigiTaggedResourceHandle {
    LuigiResourceHandle handle;
    int index;
};
struct LuigiResourceStorage {
    void* vtable;
    LuigiResourceHandle primary;
    LuigiTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct LuigiResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct LuigiResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_99_data_1940[], lbl_99_data_21F4[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(LuigiResourceHandle*, void*);
void* fn_27_B5048(void*, LuigiResourceHandle*, LuigiResourceHandle*,
                  LuigiTaggedResourceHandle*, LuigiResourceAccesser*, const void*);
}

// Each handle acquires the fighter resource independently before module setup.
extern "C" LuigiResourceStorage* fn_99_60B4(
    LuigiResourceStorage* storage, int, LuigiResourceAccesser* accesser) {
    LuigiResourceFighter* fighter = static_cast<LuigiResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_99_data_1940, lbl_99_data_21F4, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    fighter = static_cast<LuigiResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_99_data_1940, lbl_99_data_21F4, 1));
    resource = fighter->resource;
    LuigiTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
