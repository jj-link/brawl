#pragma force_active on
struct KirbyResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};

struct KirbyTaggedResourceHandle {
    KirbyResourceHandle handle;
    int index;
};

struct KirbyResourceStorage {
    void* vtable;
    KirbyResourceHandle primary;
    KirbyTaggedResourceHandle secondary;
    unsigned char module[1];
};

struct KirbyResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};

struct KirbyResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};

extern "C" {
extern const char lbl_96_data_6024[], lbl_96_data_68D8[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(KirbyResourceHandle*, void*);
void* fn_27_B5048(void*, KirbyResourceHandle*, KirbyResourceHandle*,
                 KirbyTaggedResourceHandle*, KirbyResourceAccesser*, const void*);
}

extern "C" KirbyResourceStorage* fn_96_25F8(
    KirbyResourceStorage* storage, int, KirbyResourceAccesser* accesser) {
    KirbyResourceFighter* fighter = static_cast<KirbyResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_96_data_6024, lbl_96_data_68D8, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);

    fighter = static_cast<KirbyResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_96_data_6024, lbl_96_data_68D8, 1));
    resource = fighter->resource;
    KirbyTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);
    resource = const_cast<char*>(lbl_27_data_2AB90);
    secondary->handle.vtable = resource;
    secondary->index = -1;

    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
