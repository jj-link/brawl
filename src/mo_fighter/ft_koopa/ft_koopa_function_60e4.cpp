#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct KoopaResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct KoopaTaggedResourceHandle {
    KoopaResourceHandle handle;
    int index;
};
struct KoopaResourceStorage {
    void* vtable;
    KoopaResourceHandle primary;
    KoopaTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct KoopaResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct KoopaResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_102_data_1718[], lbl_102_data_1F48[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(KoopaResourceHandle*, void*);
void* fn_27_B5048(void*, KoopaResourceHandle*, KoopaResourceHandle*,
                  KoopaTaggedResourceHandle*, KoopaResourceAccesser*, const void*);
}

// Each handle acquires the fighter resource independently before module setup.
extern "C" KoopaResourceStorage* fn_102_60E4(
    KoopaResourceStorage* storage, int, KoopaResourceAccesser* accesser) {
    void* resource = static_cast<KoopaResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_102_data_1718, lbl_102_data_1F48, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    void* resource2 = static_cast<KoopaResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_102_data_1718, lbl_102_data_1F48, 1))->resource;
    KoopaTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource2);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
