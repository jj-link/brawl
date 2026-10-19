#pragma force_active on
extern "C" void fn_115_6654(void*, bool);
extern "C" unsigned char lbl_115_data_8360[];

namespace {
struct DiddyStorage {
    void* vtable;
    unsigned char nullableStorage[4];
    void* parameters;
    int index;
};
}

extern "C" void* fn_115_1572C(DiddyStorage* object, void* parameters) {
    fn_115_6654(object, false);
    object->vtable = lbl_115_data_8360;
    object->parameters = parameters;
    object->index = -1;
    return object;
}
