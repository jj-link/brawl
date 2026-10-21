#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct FtResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct FtTaggedResourceHandle {
    FtResourceHandle handle;
    int index;
};
struct FtResourceStorage {
    void* vtable;
    FtResourceHandle primary;
    FtTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct FtResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct FtResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_108_data_26CC[], lbl_108_data_2F80[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(FtResourceHandle*, void*);
void* fn_27_B5048(void*, FtResourceHandle*, FtResourceHandle*,
                  FtTaggedResourceHandle*, FtResourceAccesser*, const void*);
}

extern "C" FtResourceStorage* fn_108_7F44(
    FtResourceStorage* storage, int, FtResourceAccesser* accesser) {
    void* resource = static_cast<FtResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_108_data_26CC, lbl_108_data_2F80, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<FtResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_108_data_26CC, lbl_108_data_2F80, 1))->resource;
    FtTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
