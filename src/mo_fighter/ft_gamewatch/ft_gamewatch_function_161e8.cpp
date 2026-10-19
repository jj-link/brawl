#pragma force_active on
extern "C" void fn_107_8648(void* object, bool isNull);
extern "C" unsigned char lbl_107_data_9DB8[];

namespace {
struct Fn107Obj {
    void* vtable;
    unsigned char nullableStorage[4];
    void* parameters;
    int index;
};
}

extern "C" void* fn_107_161E8(Fn107Obj* object, void* parameters) {
    fn_107_8648(object, false);
    object->vtable = lbl_107_data_9DB8;
    object->parameters = parameters;
    object->index = -1;
    return object;
}
