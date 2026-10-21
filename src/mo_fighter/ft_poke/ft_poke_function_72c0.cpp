#pragma force_active on
struct PokeResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};

struct PokeTaggedResourceHandle {
    PokeResourceHandle handle;
    int index;
};

struct PokeResourceStorage {
    void* vtable;
    PokeResourceHandle primary;
    PokeTaggedResourceHandle secondary;
    unsigned char module[1];
};

struct PokeResourceAccesser {
    unsigned char prefix[8];
    void* stageObject;
};

struct PokeResourceFighter {
    unsigned char prefix[0x10C];
    void* resource;
};

extern "C" {
extern const char lbl_116_data_2484[], lbl_116_data_2D00[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(PokeResourceHandle*, void*);
void* fn_27_B5048(void*, PokeResourceHandle*, PokeResourceHandle*,
                 PokeTaggedResourceHandle*, PokeResourceAccesser*, const void*);
}

extern "C" PokeResourceStorage* fn_116_72C0(
    PokeResourceStorage* storage, int, PokeResourceAccesser* accesser) {
    PokeResourceFighter* fighter = static_cast<PokeResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_116_data_2484, lbl_116_data_2D00, 1));
    void* resource = fighter->resource;
    fn_27_14033C(&storage->primary, resource);

    fighter = static_cast<PokeResourceFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_116_data_2484, lbl_116_data_2D00, 1));
    resource = fighter->resource;
    PokeTaggedResourceHandle* secondary = &storage->secondary;
    fn_27_14033C(&secondary->handle, resource);

    resource = const_cast<char*>(lbl_27_data_2AB90);
    secondary->handle.vtable = resource;
    secondary->index = -1;

    fn_27_B5048(storage->module, &storage->primary, &storage->primary,
                secondary, accesser, lbl_27_bss_A48);
    return storage;
}
