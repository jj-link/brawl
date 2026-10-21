#pragma force_active on
struct Data {
    unsigned char padding[0x58];
    unsigned int* arrays[1];
};

extern "C" void fn_27_1D53FC(Data* self, unsigned int value,
                            unsigned int arrayIndex, unsigned int elementIndex) {
    self->arrays[arrayIndex][elementIndex] = value;
}
