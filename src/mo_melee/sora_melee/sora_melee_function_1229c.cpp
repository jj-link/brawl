#pragma force_active on
struct Value {
    unsigned char padding[0x5A];
    unsigned char value;
};

struct Link {
    Value* value;
};

struct Object {
    unsigned char padding[0x2C];
    Link* link;
};

extern "C" unsigned char fn_27_1229C(Object* object) {
    return object->link->value->value;
}
