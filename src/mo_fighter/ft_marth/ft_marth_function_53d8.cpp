#pragma force_active on
struct ResourceHandle106 {
    void* vtable;
    unsigned char state[0x10];
};
struct TaggedResourceHandle106 {
    ResourceHandle106 handle;
    int index;
};
struct ResourceStorage106 {
    void* vtable;
    ResourceHandle106 primary;
    TaggedResourceHandle106 secondary;
    unsigned char module[1];
};
struct ResourceAccesser106 {
    unsigned char prefix[8];
    void* stageObject;
};
struct ResourceFighter106 {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_106_data_10BC[], lbl_106_data_17F0[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(ResourceHandle106*, void*);
void* fn_27_B5048(void*, ResourceHandle106*, ResourceHandle106*,
                 TaggedResourceHandle106*, ResourceAccesser106*, const void*);
}

extern "C" ResourceStorage106* fn_106_53D8(
    ResourceStorage106* storage, int, ResourceAccesser106* accesser) {
    void* resource = static_cast<ResourceFighter106*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_106_data_10BC, lbl_106_data_17F0, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<ResourceFighter106*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_106_data_10BC, lbl_106_data_17F0, 1))->resource;
    TaggedResourceHandle106* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
