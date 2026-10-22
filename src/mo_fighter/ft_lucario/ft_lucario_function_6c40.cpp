#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct LucarioResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct LucarioTaggedResourceHandle {
    LucarioResourceHandle handle;
    int index;
};
struct LucarioResourceStorage {
    void* vtable;
    LucarioResourceHandle primary;
    LucarioTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct LucarioResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct LucarioResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_118_data_19D4[], lbl_118_data_2250[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(LucarioResourceHandle*, void*);
void* fn_27_B5048(void*, LucarioResourceHandle*, LucarioResourceHandle*,
                  LucarioTaggedResourceHandle*, LucarioResourceAccesser*, const void*);
}

// Each handle acquires the fighter resource independently before module setup.
extern "C" LucarioResourceStorage* fn_118_6C40(
    LucarioResourceStorage* storage, int, LucarioResourceAccesser* accesser) {
    void* resource = reinterpret_cast<LucarioResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_118_data_19D4, lbl_118_data_2250, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = reinterpret_cast<LucarioResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_118_data_19D4, lbl_118_data_2250, 1))->resource;
    LucarioTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
