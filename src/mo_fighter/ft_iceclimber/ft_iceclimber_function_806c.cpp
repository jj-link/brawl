#pragma force_active on
struct IceClimberResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct IceClimberTaggedResourceHandle {
    IceClimberResourceHandle handle;
    int index;
};
struct IceClimberResourceStorage {
    void* vtable;
    IceClimberResourceHandle primary;
    IceClimberTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct IceClimberResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct IceClimberResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_105_data_2F74[], lbl_105_data_3860[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(IceClimberResourceHandle*, void*);
void* fn_27_B5048(void*, IceClimberResourceHandle*, IceClimberResourceHandle*,
                  IceClimberTaggedResourceHandle*, IceClimberResourceAccesser*, const void*);
}

extern "C" IceClimberResourceStorage* fn_105_806C(
    IceClimberResourceStorage* storage, int, IceClimberResourceAccesser* accesser) {
    void* resource = static_cast<IceClimberResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_105_data_2F74, lbl_105_data_3860, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    void* resource2 = static_cast<IceClimberResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_105_data_2F74, lbl_105_data_3860, 1))->resource;
    IceClimberTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource2);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
