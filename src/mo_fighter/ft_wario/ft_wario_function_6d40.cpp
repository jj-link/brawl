#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct WarioResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct WarioTaggedResourceHandle {
    WarioResourceHandle handle;
    int index;
};
struct WarioResourceStorage {
    void* vtable;
    WarioResourceHandle primary;
    WarioTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct WarioResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct WarioResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_110_data_18B0[], lbl_110_data_212C[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(WarioResourceHandle*, void*);
void* fn_27_B5048(void*, WarioResourceHandle*, WarioResourceHandle*,
                  WarioTaggedResourceHandle*, WarioResourceAccesser*, const void*);
}

extern "C" WarioResourceStorage* fn_110_6D40(
    WarioResourceStorage* storage, int, WarioResourceAccesser* accesser) {
    void* resource = static_cast<WarioResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_110_data_18B0, lbl_110_data_212C, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    void* resource2 = static_cast<WarioResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_110_data_18B0, lbl_110_data_212C, 1))->resource;
    WarioTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource2);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
