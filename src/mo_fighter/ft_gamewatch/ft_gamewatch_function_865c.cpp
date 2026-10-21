#pragma force_active on
struct GwResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct GwTaggedResourceHandle {
    GwResourceHandle handle;
    int index;
};
struct GwResourceStorage {
    void* vtable;
    GwResourceHandle primary;
    GwTaggedResourceHandle secondary;
    unsigned char module[1];
};
struct GwResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct GwResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_107_data_3D3C[], lbl_107_data_45B8[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(GwResourceHandle*, void*);
void* fn_27_B5048(void*, GwResourceHandle*, GwResourceHandle*,
                  GwTaggedResourceHandle*, GwResourceAccesser*, const void*);

void* fn_107_865C(void* arg0, int arg1, GwResourceAccesser* arg2) {
    GwResourceStorage* storage = static_cast<GwResourceStorage*>(arg0);
    GwResourceFighter* fighter = static_cast<GwResourceFighter*>(
        __dynamic_cast(arg2->stageObject, 0x3C,
                       lbl_107_data_3D3C, lbl_107_data_45B8, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);
    resource = static_cast<GwResourceFighter*>(
        __dynamic_cast(arg2->stageObject, 0x3C,
                       lbl_107_data_3D3C, lbl_107_data_45B8, 1))->resource;
    GwTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, arg2, lbl_27_bss_A48);
    return arg0;
}
}
