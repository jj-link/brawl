#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct PeachResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct PeachTaggedResourceHandle {
    PeachResourceHandle handle;
    int index;
};
struct PeachResourceStorage {
    void* vtable;
    PeachResourceHandle primary;
    PeachTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct PeachResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct PeachResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_103_data_1A24[], lbl_103_data_22A0[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(PeachResourceHandle*, void*);
void* fn_27_B5048(void*, PeachResourceHandle*, PeachResourceHandle*,
                  PeachTaggedResourceHandle*, PeachResourceAccesser*, const void*);
}

extern "C" PeachResourceStorage* fn_103_71E0(
    PeachResourceStorage* storage, int, PeachResourceAccesser* accesser) {
    PeachResourceFighter* fighter = static_cast<PeachResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_103_data_1A24, lbl_103_data_22A0, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<PeachResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_103_data_1A24, lbl_103_data_22A0, 1))->resource;
    PeachTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
