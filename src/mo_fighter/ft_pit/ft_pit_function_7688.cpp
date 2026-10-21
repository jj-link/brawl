#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct FtPitResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct FtPitTaggedResourceHandle {
    FtPitResourceHandle handle;
    int index;
};
struct FtPitResourceStorage {
    void* vtable;
    FtPitResourceHandle primary;
    FtPitTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct FtPitResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct FtPitResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_112_data_1F10[], lbl_112_data_27C4[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(FtPitResourceHandle*, void*);
void* fn_27_B5048(void*, FtPitResourceHandle*, FtPitResourceHandle*,
                  FtPitTaggedResourceHandle*, FtPitResourceAccesser*, const void*);
}

extern "C" FtPitResourceStorage* fn_112_7688(
    FtPitResourceStorage* storage, int, FtPitResourceAccesser* accesser) {
    FtPitResourceFighter* fighter = static_cast<FtPitResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_112_data_1F10, lbl_112_data_27C4, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<FtPitResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_112_data_1F10, lbl_112_data_27C4, 1))->resource;
    FtPitTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
