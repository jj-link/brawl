// ABI views for the embedded resource handles and module accesser.
struct NessResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct NessTaggedResourceHandle {
    NessResourceHandle handle;
    int index;
};
struct NessResourceStorage {
    void* vtable;
    NessResourceHandle primary;
    NessTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct NessResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct NessResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_101_data_3AB4[], lbl_101_data_4330[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(NessResourceHandle*, void*);
void* fn_27_B5048(void*, NessResourceHandle*, NessResourceHandle*,
                  NessTaggedResourceHandle*, NessResourceAccesser*, const void*);
}

// Each handle acquires the fighter resource independently before module setup.
extern "C" NessResourceStorage* fn_101_9224(
    NessResourceStorage* storage, int, NessResourceAccesser* accesser) {
    NessResourceFighter* fighter = static_cast<NessResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_101_data_3AB4, lbl_101_data_4330, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<NessResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_101_data_3AB4, lbl_101_data_4330, 1))->resource;
    NessTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
