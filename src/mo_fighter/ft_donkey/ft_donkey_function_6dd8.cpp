#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct DonkeyResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct DonkeyTaggedResourceHandle {
    DonkeyResourceHandle handle;
    int index;
};
struct DonkeyResourceStorage {
    void* vtable;
    DonkeyResourceHandle primary;
    DonkeyTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct DonkeyResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct DonkeyResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_92_data_1A98[], lbl_92_data_2314[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(DonkeyResourceHandle*, void*);
void* fn_27_B5048(void*, DonkeyResourceHandle*, DonkeyResourceHandle*,
                  DonkeyTaggedResourceHandle*, DonkeyResourceAccesser*, const void*);
}

extern "C" DonkeyResourceStorage* fn_92_6DD8(
    DonkeyResourceStorage* storage, int, DonkeyResourceAccesser* accesser) {
    void* resource = static_cast<DonkeyResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_92_data_1A98, lbl_92_data_2314, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<DonkeyResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_92_data_1A98, lbl_92_data_2314, 1))->resource;
    DonkeyTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
