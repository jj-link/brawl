#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct LucasResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct LucasTaggedResourceHandle {
    LucasResourceHandle handle;
    int index;
};
struct LucasResourceStorage {
    void* vtable;
    LucasResourceHandle primary;
    LucasTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct LucasResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct LucasResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_114_data_3400[], lbl_114_data_3C7C[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(LucasResourceHandle*, void*);
void* fn_27_B5048(void*, LucasResourceHandle*, LucasResourceHandle*,
                  LucasTaggedResourceHandle*, LucasResourceAccesser*, const void*);
}

extern "C" LucasResourceStorage* fn_114_8AFC(
    LucasResourceStorage* storage, int, LucasResourceAccesser* accesser) {
    LucasResourceFighter* fighter = static_cast<LucasResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_114_data_3400, lbl_114_data_3C7C, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<LucasResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_114_data_3400, lbl_114_data_3C7C, 1))->resource;
    LucasTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
