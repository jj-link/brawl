#pragma force_active on
struct ZeldaResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct ZeldaTaggedResourceHandle {
    ZeldaResourceHandle handle;
    int index;
};
struct ZeldaResourceStorage {
    void* vtable;
    ZeldaResourceHandle primary;
    ZeldaTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct ZeldaResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct ZeldaResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_104_data_2628[], lbl_104_data_2EDC[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(ZeldaResourceHandle*, void*);
void* fn_27_B5048(void*, ZeldaResourceHandle*, ZeldaResourceHandle*,
                  ZeldaTaggedResourceHandle*, ZeldaResourceAccesser*, const void*);
}

extern "C" ZeldaResourceStorage* fn_104_786C(
    ZeldaResourceStorage* storage, int, ZeldaResourceAccesser* accesser) {
    void* resource = static_cast<ZeldaResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_104_data_2628, lbl_104_data_2EDC, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<ZeldaResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_104_data_2628, lbl_104_data_2EDC, 1))->resource;
    ZeldaTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
