#pragma force_active on
struct ObjectLayout {
    unsigned char padding[0x1c];
    const unsigned int* values;
};

extern "C" bool fn_99_8A68(const ObjectLayout* object, unsigned int mask, int index) {
    return (mask & object->values[index]) != 0;
}
