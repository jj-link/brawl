void operator delete(void*);
extern "C" void* fn_118_6C2C(void*, bool);
extern "C" unsigned char lbl_118_data_71AC[];

namespace {
struct ParameterAccesserStorage {
    void* vtable;
    unsigned char nullableStorage[4];
    void* parameters;
    int index;
};
}

extern "C" void* fn_118_13754(ParameterAccesserStorage* object, void* parameters) {
    fn_118_6C2C(object, false);
    object->vtable = lbl_118_data_71AC;
    object->parameters = parameters;
    object->index = -1;
    return object;
}

extern "C" void* fn_118_137AC(void* object, short deleting) {
    if (object != 0) {
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
