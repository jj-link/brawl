#pragma force_active on
extern "C" void fn_97_8060(void* object, bool isNull);
extern "C" unsigned char lbl_97_data_79C0[];

namespace {
struct ParameterAccesserStorage {
    void* vtable;
    unsigned char nullableStorage[4];
    void* parameters;
    int index;
};
}

extern "C" void* fn_97_10760(ParameterAccesserStorage* object, void* parameters) {
    fn_97_8060(object, false);
    object->vtable = lbl_97_data_79C0;
    object->parameters = parameters;
    object->index = -1;
    return object;
}
