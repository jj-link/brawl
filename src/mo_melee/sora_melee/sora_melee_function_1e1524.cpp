#pragma force_active on
struct ResourceHandle {
    const void* vtable;
    bool isNull;
    void* resource;
    int index;
};

struct ResourceStorage {
    ResourceHandle primary;
    ResourceHandle secondary;
    unsigned char module[1];
};

extern "C" {
extern const char lbl_27_data_46568[];
extern const char lbl_27_bss_A48[];

void* fn_27_B5048(void*, void*, void*, void*, void*, const void*);

ResourceStorage* fn_27_1E1524(ResourceStorage* self, void* resource, void* accesser) {
    self->primary.isNull = false;
    self->primary.vtable = lbl_27_data_46568;
    self->primary.resource = resource;
    self->primary.index = -1;

    ResourceHandle* secondary = &self->secondary;
    secondary->isNull = false;
    secondary->vtable = lbl_27_data_46568;
    secondary->resource = resource;
    secondary->index = -1;

    fn_27_B5048(self->module, &self->primary, secondary,
                &self->primary, accesser, lbl_27_bss_A48);
    return self;
}
}
