#pragma force_active on
struct Data {
    unsigned char padding[0x72];
    unsigned char reserved : 7;
    unsigned char enabled : 1;
};

struct Object {
    unsigned int unknown;
    Data* data;
};

extern "C" void fn_27_2EF7C(Object* object, bool enabled) {
    object->data->enabled = enabled;
}
