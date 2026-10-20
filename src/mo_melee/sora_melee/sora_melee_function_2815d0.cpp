#pragma force_active on
extern "C" {
extern const char lbl_27_data_46568[];

struct ResourceHandle {
    const void* vtable;
    bool isNull;
    void* resource;
    int index;
};

void fn_27_2815D0(ResourceHandle* self, void* resource) {
    self->isNull = false;
    self->vtable = lbl_27_data_46568;
    self->resource = resource;
    self->index = -1;
}
}
