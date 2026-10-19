#pragma force_active on
struct PeachArray {
    unsigned int padding[3];
    unsigned int* data;
};

extern "C" void fn_103_A2BC(PeachArray* array, unsigned int value, int index) {
    array->data[index] = value;
}
