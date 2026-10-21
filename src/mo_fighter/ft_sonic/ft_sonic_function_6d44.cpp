#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct SonicResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct SonicTaggedResourceHandle {
    SonicResourceHandle handle;
    int index;
};
struct SonicResourceStorage {
    void* vtable;
    SonicResourceHandle primary;
    SonicTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct SonicResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct SonicResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_123_data_1984[], lbl_123_data_2238[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(SonicResourceHandle*, void*);
void* fn_27_B5048(void*, SonicResourceHandle*, SonicResourceHandle*,
                  SonicTaggedResourceHandle*, SonicResourceAccesser*, const void*);
}

extern "C" SonicResourceStorage* fn_123_6D44(
    SonicResourceStorage* storage, int, SonicResourceAccesser* accesser) {
    SonicResourceFighter* fighter = static_cast<SonicResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_123_data_1984, lbl_123_data_2238, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<SonicResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_123_data_1984, lbl_123_data_2238, 1))->resource;
    SonicTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
