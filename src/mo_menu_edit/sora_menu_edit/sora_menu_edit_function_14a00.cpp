#pragma force_active on
struct SubObject {
    char padding1[0x1BF4];
    int first;
    char padding2[0x148];
    int second;
};

struct Object {
    char padding[0x1AC];
    SubObject* subobject;
};

extern "C" void fn_5_14A00(Object* object) {
    object->subobject->second = 3;
    object->subobject->first = 1;
}
