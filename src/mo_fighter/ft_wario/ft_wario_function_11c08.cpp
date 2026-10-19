#pragma force_active on
extern "C" void fn_110_6D2C(void* obj, unsigned char flag);
extern "C" unsigned char lbl_110_data_7094[];

struct WarioStorage {
    void* vtable;
    unsigned char nullableStorage[4];
    void* parameters;
    int index;
};

extern "C" void* fn_110_11C08(void* object, void* parameters) {
    WarioStorage* self = (WarioStorage*)object;
    fn_110_6D2C(object, 0);
    self->vtable = lbl_110_data_7094;
    self->parameters = parameters;
    self->index = -1;
    return object;
}
