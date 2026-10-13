// ABI views for the embedded resource handles and module accesser.
struct DededeResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct DededeTaggedResourceHandle {
    DededeResourceHandle handle;
    int index;
};
struct DededeResourceStorage {
    void* vtable;
    DededeResourceHandle primary;
    DededeTaggedResourceHandle secondary;
    unsigned char module[1]; // Only the module's starting address is used here.
};
struct DededeResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct DededeResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_117_data_38CC[], lbl_117_data_4148[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(DededeResourceHandle*, void*);
void* fn_27_B5048(void*, DededeResourceHandle*, DededeResourceHandle*,
                 DededeTaggedResourceHandle*, DededeResourceAccesser*, const void*);
}

// Each handle acquires the fighter resource independently before module setup.
extern "C" DededeResourceStorage* fn_117_6710(
    DededeResourceStorage* storage, int, DededeResourceAccesser* accesser) {
    DededeResourceFighter* fighter = static_cast<DededeResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_117_data_38CC, lbl_117_data_4148, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    fighter = static_cast<DededeResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_117_data_38CC, lbl_117_data_4148, 1));
    resource = fighter->resource;
    DededeTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
