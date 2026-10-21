#pragma force_active on
struct MarioResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct MarioTaggedResourceHandle {
    MarioResourceHandle handle;
    int index;
};
struct MarioResourceStorage {
    void* vtable;
    MarioResourceHandle primary;
    MarioTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct MarioResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct MarioResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_91_data_2B20[], lbl_91_data_33D4[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(MarioResourceHandle*, void*);
void* fn_27_B5048(void*, MarioResourceHandle*, MarioResourceHandle*,
                 MarioTaggedResourceHandle*, MarioResourceAccesser*, const void*);
}

extern "C" MarioResourceStorage* fn_91_2098(
    MarioResourceStorage* storage, int, MarioResourceAccesser* accesser) {
    void* resource = static_cast<MarioResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_91_data_2B20, lbl_91_data_33D4, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<MarioResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_91_data_2B20, lbl_91_data_33D4, 1))->resource;
    MarioTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
