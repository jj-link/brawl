#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct IkeResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct IkeTaggedResourceHandle {
    IkeResourceHandle handle;
    int index;
};
struct IkeResourceStorage {
    void* vtable;
    IkeResourceHandle primary;
    IkeTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct IkeResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct IkeResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_119_data_1598[], lbl_119_data_1E14[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(IkeResourceHandle*, void*);
void* fn_27_B5048(void*, IkeResourceHandle*, IkeResourceHandle*,
                  IkeTaggedResourceHandle*, IkeResourceAccesser*, const void*);
}

extern "C" IkeResourceStorage* fn_119_5820(
    IkeResourceStorage* storage, int, IkeResourceAccesser* accesser) {
    void* resource = static_cast<IkeResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_119_data_1598, lbl_119_data_1E14, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<IkeResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_119_data_1598, lbl_119_data_1E14, 1))->resource;
    IkeTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
