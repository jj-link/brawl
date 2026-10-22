#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct SamusResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct SamusTaggedResourceHandle {
    SamusResourceHandle handle;
    int index;
};
struct SamusResourceStorage {
    void* vtable;
    SamusResourceHandle primary;
    SamusTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct SamusResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct SamusResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_94_data_4794[], lbl_94_data_5010[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(SamusResourceHandle*, void*);
void* fn_27_B5048(void*, SamusResourceHandle*, SamusResourceHandle*,
                  SamusTaggedResourceHandle*, SamusResourceAccesser*, const void*);
}

extern "C" SamusResourceStorage* fn_94_6C34(
    SamusResourceStorage* storage, int, SamusResourceAccesser* accesser) {
    void* resource = static_cast<SamusResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_94_data_4794, lbl_94_data_5010, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    void* resource2 = static_cast<SamusResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_94_data_4794, lbl_94_data_5010, 1))->resource;
    SamusTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource2);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
