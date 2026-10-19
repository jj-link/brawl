#pragma force_active on
struct PeachFloatArray {
    unsigned char padding[0x14];
    float* data;
};

extern "C" float fn_103_A20C(const PeachFloatArray* array, int index) {
    return array->data[index];
}
