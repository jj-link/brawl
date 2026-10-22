#pragma force_active on
struct CaptainResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct CaptainTaggedResourceHandle {
    CaptainResourceHandle handle;
    int index;
};
struct CaptainResourceStorage {
    void* vtable;
    CaptainResourceHandle primary;
    CaptainTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct CaptainResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct CaptainResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_100_data_18F8[], lbl_100_data_21AC[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(CaptainResourceHandle*, void*);
void* fn_27_B5048(void*, CaptainResourceHandle*, CaptainResourceHandle*,
                 CaptainTaggedResourceHandle*, CaptainResourceAccesser*, const void*);
}

extern "C" CaptainResourceStorage* fn_100_6B9C(
    CaptainResourceStorage* storage, int, CaptainResourceAccesser* accesser) {
    void* resource = static_cast<CaptainResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_100_data_18F8, lbl_100_data_21AC, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<CaptainResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_100_data_18F8, lbl_100_data_21AC, 1))->resource;
    CaptainTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
