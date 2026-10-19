#pragma force_active on
struct Object {
    unsigned char padding[12];
    unsigned int* data;
};

extern "C" void fn_118_A558(Object* object, unsigned int value, unsigned int index) {
    object->data[index] = value;
}
