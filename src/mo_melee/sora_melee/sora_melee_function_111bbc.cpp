#pragma force_active on
struct Value {
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

struct Object {
    unsigned char padding[0x4E8];
    Value value;
};

struct Wrapper {
    Object* object;
};

extern "C" Value fn_27_111BBC(const Wrapper* wrapper) {
    return wrapper->object->value;
}
