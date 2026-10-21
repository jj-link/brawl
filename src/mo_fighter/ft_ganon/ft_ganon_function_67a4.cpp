#pragma force_active on
struct GanonResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct GanonTaggedResourceHandle {
    GanonResourceHandle handle;
    int index;
};
struct GanonResourceStorage {
    void* vtable;
    GanonResourceHandle primary;
    GanonTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct GanonResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct GanonResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_109_data_1894[], lbl_109_data_2148[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(GanonResourceHandle*, void*);
void* fn_27_B5048(void*, GanonResourceHandle*, GanonResourceHandle*,
                  GanonTaggedResourceHandle*, GanonResourceAccesser*, const void*);
}

extern "C" GanonResourceStorage* fn_109_67A4(
    GanonResourceStorage* storage, int, GanonResourceAccesser* accesser) {
    void* resource = static_cast<GanonResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_109_data_1894, lbl_109_data_2148, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<GanonResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_109_data_1894, lbl_109_data_2148, 1))->resource;
    GanonTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
