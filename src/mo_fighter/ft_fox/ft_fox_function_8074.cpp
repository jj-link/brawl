#pragma force_active on
struct FoxResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct FoxTaggedResourceHandle {
    FoxResourceHandle handle;
    int index;
};
struct FoxResourceStorage {
    void* vtable;
    FoxResourceHandle primary;
    FoxTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct FoxResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct FoxResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_97_data_268C[], lbl_97_data_2F40[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(FoxResourceHandle*, void*);
void* fn_27_B5048(void*, FoxResourceHandle*, FoxResourceHandle*,
                  FoxTaggedResourceHandle*, FoxResourceAccesser*, const void*);
}

extern "C" FoxResourceStorage* fn_97_8074(
    FoxResourceStorage* storage, int, FoxResourceAccesser* accesser) {
    void* resource = static_cast<FoxResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_97_data_268C, lbl_97_data_2F40, 1))->resource;
    fn_27_14033C(&storage->primary, resource);
    void* resource2 = static_cast<FoxResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_97_data_268C, lbl_97_data_2F40, 1))->resource;
    FoxTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource2);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
