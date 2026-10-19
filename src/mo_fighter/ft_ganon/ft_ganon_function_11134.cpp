#pragma force_active on
extern "C" void fn_109_6790(void* object, int isNull);
extern "C" unsigned char lbl_109_data_717C[];

struct FtGanonStorage {
    void* vtable;
    unsigned char nullableStorage[4];
    void* parameters;
    int index;
};

extern "C" void* fn_109_11134(void* object, void* parameters) {
    fn_109_6790(object, 0);
    FtGanonStorage* self = (FtGanonStorage*)object;
    self->vtable = lbl_109_data_717C;
    self->parameters = parameters;
    self->index = -1;
    return object;
}
