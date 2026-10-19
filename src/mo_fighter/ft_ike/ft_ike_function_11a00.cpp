#pragma force_active on
extern "C" void fn_119_580C(void* object, int value);
extern "C" unsigned char lbl_119_data_66A4[];

namespace {
struct ParameterAccesserStorage {
    void* vtable;
    unsigned char nullableStorage[4];
    void* parameters;
    int index;
};
}

extern "C" void* fn_119_11A00(ParameterAccesserStorage* object, void* parameters) {
    fn_119_580C(object, 0);
    object->vtable = lbl_119_data_66A4;
    object->parameters = parameters;
    object->index = -1;
    return object;
}
