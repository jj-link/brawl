#pragma force_active on
extern "C" void fn_104_7858(void*, unsigned char);
extern "C" unsigned char lbl_104_data_7F6C[];

struct Object {
    void* vtable;
    unsigned char padding[4];
    void* value;
    int index;
};

extern "C" Object* fn_104_121F8(Object* object, void* value) {
    fn_104_7858(object, 0);
    object->vtable = lbl_104_data_7F6C;
    object->value = value;
    object->index = -1;
    return object;
}
