#pragma force_active on
struct DiddyResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct DiddyTaggedResourceHandle {
    DiddyResourceHandle handle;
    int index;
};
struct DiddyResourceStorage {
    void* vtable;
    DiddyResourceHandle primary;
    DiddyTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct DiddyResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct DiddyResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_115_data_2984[], lbl_115_data_3200[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(DiddyResourceHandle*, void*);
void* fn_27_B5048(void*, DiddyResourceHandle*, DiddyResourceHandle*,
                 DiddyTaggedResourceHandle*, DiddyResourceAccesser*, const void*);
}

extern "C" DiddyResourceStorage* fn_115_6668(
    DiddyResourceStorage* storage, int, DiddyResourceAccesser* accesser) {
    void* resource = static_cast<DiddyResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_115_data_2984, lbl_115_data_3200, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    void* resource2 = static_cast<DiddyResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_115_data_2984, lbl_115_data_3200, 1))->resource;
    DiddyTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource2);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
