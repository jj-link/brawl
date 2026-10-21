#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct PikminResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct PikminTaggedResourceHandle {
    PikminResourceHandle handle;
    int index;
};
struct PikminResourceStorage {
    void* vtable;
    PikminResourceHandle primary;
    PikminTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct PikminResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct PikminResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_113_data_20D4[], lbl_113_data_2950[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(PikminResourceHandle*, void*);
void* fn_27_B5048(void*, PikminResourceHandle*, PikminResourceHandle*,
                  PikminTaggedResourceHandle*, PikminResourceAccesser*, const void*);
}

// Each handle acquires the fighter resource independently before module setup.
extern "C" PikminResourceStorage* fn_113_7FC4(
    PikminResourceStorage* storage, int, PikminResourceAccesser* accesser) {
    void* resource;
    PikminResourceFighter* fighter = static_cast<PikminResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_113_data_20D4, lbl_113_data_2950, 1));
    resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<PikminResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_113_data_20D4, lbl_113_data_2950, 1))->resource;
    PikminTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
