#pragma force_active on
struct SnakeResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct SnakeTaggedResourceHandle {
    SnakeResourceHandle handle;
    int index;
};
struct SnakeResourceStorage {
    void* vtable;
    SnakeResourceHandle primary;
    SnakeTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct SnakeResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct SnakeResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_122_data_83E4[], lbl_122_data_8C98[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(SnakeResourceHandle*, void*);
void* fn_27_B5048(void*, SnakeResourceHandle*, SnakeResourceHandle*,
                  SnakeTaggedResourceHandle*, SnakeResourceAccesser*, const void*);
}

extern "C" SnakeResourceStorage* fn_122_AAF0(
    SnakeResourceStorage* storage, int, SnakeResourceAccesser* accesser) {
    void* resource = static_cast<SnakeResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_122_data_83E4, lbl_122_data_8C98, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<SnakeResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_122_data_83E4, lbl_122_data_8C98, 1))->resource;
    SnakeTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
