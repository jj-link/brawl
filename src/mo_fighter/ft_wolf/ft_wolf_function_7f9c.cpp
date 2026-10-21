#pragma force_active on
struct WolfResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct WolfTaggedResourceHandle {
    WolfResourceHandle handle;
    int index;
};
struct WolfResourceStorage {
    void* vtable;
    WolfResourceHandle primary;
    WolfTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct WolfResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct WolfResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_125_data_26C8[], lbl_125_data_2F7C[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(WolfResourceHandle*, void*);
void* fn_27_B5048(void*, WolfResourceHandle*, WolfResourceHandle*,
                  WolfTaggedResourceHandle*, WolfResourceAccesser*, const void*);
}

extern "C" WolfResourceStorage* fn_125_7F9C(
    WolfResourceStorage* storage, int, WolfResourceAccesser* accesser) {
    void* resource = static_cast<WolfResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_125_data_26C8, lbl_125_data_2F7C, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<WolfResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_125_data_26C8, lbl_125_data_2F7C, 1))->resource;
    WolfTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
