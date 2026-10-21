#pragma force_active on
struct YoshiResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};

struct YoshiTaggedResourceHandle {
    YoshiResourceHandle handle;
    int index;
};

struct YoshiResourceStorage {
    void* vtable;
    YoshiResourceHandle primary;
    YoshiTaggedResourceHandle secondary;
    unsigned char module[1];
};

struct YoshiResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};

struct YoshiResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};

extern "C" {
extern const char lbl_95_data_2E5C[], lbl_95_data_36D8[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(YoshiResourceHandle*, void*);
void* fn_27_B5048(void*, YoshiResourceHandle*, YoshiResourceHandle*,
                 YoshiTaggedResourceHandle*, YoshiResourceAccesser*, const void*);
}

extern "C" YoshiResourceStorage* fn_95_7F44(
    YoshiResourceStorage* storage, int, YoshiResourceAccesser* accesser) {
    YoshiResourceFighter* fighter = static_cast<YoshiResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_95_data_2E5C, lbl_95_data_36D8, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);

    resource = static_cast<YoshiResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_95_data_2E5C, lbl_95_data_36D8, 1))->resource;
    YoshiTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;

    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
