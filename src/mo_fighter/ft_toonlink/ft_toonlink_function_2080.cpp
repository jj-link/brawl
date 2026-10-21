#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct ToonlinkResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct ToonlinkTaggedResourceHandle {
    ToonlinkResourceHandle handle;
    int index;
};
struct ToonlinkResourceStorage {
    void* vtable;
    ToonlinkResourceHandle primary;
    ToonlinkTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct ToonlinkResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct ToonlinkResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_121_data_3474[], lbl_121_data_3CF0[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(ToonlinkResourceHandle*, void*);
void* fn_27_B5048(void*, ToonlinkResourceHandle*, ToonlinkResourceHandle*,
                  ToonlinkTaggedResourceHandle*, ToonlinkResourceAccesser*, const void*);
}

// Each handle acquires the fighter resource independently before module setup.
extern "C" ToonlinkResourceStorage* fn_121_2080(
    ToonlinkResourceStorage* storage, int, ToonlinkResourceAccesser* accesser) {
    void* resource = static_cast<ToonlinkResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_121_data_3474, lbl_121_data_3CF0, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<ToonlinkResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_121_data_3474, lbl_121_data_3CF0, 1))->resource;
    ToonlinkTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
