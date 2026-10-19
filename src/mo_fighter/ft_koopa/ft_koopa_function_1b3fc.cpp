#pragma force_active on
extern "C" void fn_102_60D0(void *obj, int val);
extern "C" unsigned char lbl_102_data_8334[];

namespace {
struct KoopaParameterAccesser {
    void* vtable;
    unsigned char nullableStorage[4];
    void* parameters;
    int index;
};
}

extern "C" void* fn_102_1B3FC(void* object, void* parameters) {
    fn_102_60D0(object, 0);
    KoopaParameterAccesser* self = (KoopaParameterAccesser*)object;
    self->vtable = lbl_102_data_8334;
    self->parameters = parameters;
    self->index = -1;
    return self;
}
