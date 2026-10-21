#pragma force_active on
struct RobotResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct RobotTaggedResourceHandle {
    RobotResourceHandle handle;
    int index;
};
struct RobotResourceStorage {
    void* vtable;
    RobotResourceHandle primary;
    RobotTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct RobotResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct RobotResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_120_data_242C[], lbl_120_data_2CA8[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(RobotResourceHandle*, void*);
void* fn_27_B5048(void*, RobotResourceHandle*, RobotResourceHandle*,
                  RobotTaggedResourceHandle*, RobotResourceAccesser*, const void*);
}

extern "C" RobotResourceStorage* fn_120_5BEC(
    RobotResourceStorage* storage, int, RobotResourceAccesser* accesser) {
    void* resource = static_cast<RobotResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_120_data_242C, lbl_120_data_2CA8, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<RobotResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_120_data_242C, lbl_120_data_2CA8, 1))->resource;
    RobotTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
