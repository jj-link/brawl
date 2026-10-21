#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct Fn126ResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct Fn126TaggedResourceHandle {
    Fn126ResourceHandle handle;
    int index;
};
struct Fn126ResourceStorage {
    void* vtable;
    Fn126ResourceHandle primary;
    Fn126TaggedResourceHandle secondary;
    unsigned char module[1];
};
struct Fn126ResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct Fn126ResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_126_data_1004[], lbl_126_data_1738[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(Fn126ResourceHandle*, void*);
void* fn_27_B5048(void*, Fn126ResourceHandle*, Fn126ResourceHandle*,
                  Fn126TaggedResourceHandle*, Fn126ResourceAccesser*, const void*);
}

extern "C" Fn126ResourceStorage* fn_126_5104(
    Fn126ResourceStorage* storage, int, Fn126ResourceAccesser* accesser) {
    Fn126ResourceFighter* fighter = static_cast<Fn126ResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_126_data_1004, lbl_126_data_1738, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<Fn126ResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_126_data_1004, lbl_126_data_1738, 1))->resource;
    Fn126TaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
