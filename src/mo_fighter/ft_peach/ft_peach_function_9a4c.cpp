#pragma force_active on
namespace {
typedef unsigned char Byte;

struct ParamBlock {
    float values[23];
};

struct Dest {
    Byte header[0x10];
    const float* floats[2][36];
    const int* ints[2][6];
};

inline const float* floatBlock(const Byte* data, int offset) {
    return *reinterpret_cast<const float* const*>(data + offset);
}
inline const float* floatParams(const Byte* data, int offset) {
    return (*reinterpret_cast<const ParamBlock* const*>(data + offset))->values;
}
inline const int* intParams(const Byte* data, int offset) {
    return reinterpret_cast<const int*>(floatParams(data, offset));
}
inline const int* intBlock(const Byte* data, int offset) {
    return *reinterpret_cast<const int* const*>(data + offset);
}
} // namespace

extern "C" void fn_103_9A4C(Dest* object, const Byte* data) {
    for (int i = 0; i < 2; ++i) {
        object->floats[i][0] = floatBlock(data, 0x7C);
        object->floats[i][1] = floatParams(data, 0x7C) + 1;
        object->floats[i][2] = floatParams(data, 0x7C) + 2;
        object->floats[i][3] = floatParams(data, 0x7C) + 3;
        object->floats[i][4] = floatParams(data, 0x7C) + 4;
        object->floats[i][5] = floatBlock(data, 0x80);
        object->floats[i][6] = floatParams(data, 0x80) + 1;
        object->floats[i][7] = floatParams(data, 0x80) + 2;
        object->floats[i][8] = floatParams(data, 0x80) + 3;
        object->floats[i][9] = floatParams(data, 0x80) + 4;
        object->floats[i][10] = floatParams(data, 0x80) + 5;
        object->floats[i][11] = floatParams(data, 0x80) + 6;
        object->floats[i][12] = floatParams(data, 0x80) + 7;
        object->floats[i][13] = floatParams(data, 0x80) + 8;
        object->floats[i][14] = floatParams(data, 0x80) + 9;
        object->floats[i][15] = floatParams(data, 0x80) + 10;
        object->floats[i][16] = floatParams(data, 0x80) + 11;
        object->floats[i][17] = floatParams(data, 0x80) + 12;
        object->floats[i][18] = floatParams(data, 0x80) + 13;
        object->floats[i][19] = floatParams(data, 0x80) + 14;
        object->floats[i][20] = floatBlock(data, 0x88);
        object->floats[i][21] = floatParams(data, 0x88) + 1;
        object->floats[i][22] = floatParams(data, 0x88) + 2;
        object->floats[i][23] = floatParams(data, 0x88) + 3;
        object->floats[i][24] = floatParams(data, 0x88) + 4;
        object->floats[i][25] = floatParams(data, 0x88) + 5;
        object->floats[i][26] = floatParams(data, 0x88) + 6;
        object->floats[i][27] = floatParams(data, 0x88) + 7;
        object->floats[i][28] = floatParams(data, 0x88) + 8;
        object->floats[i][29] = floatBlock(data, 0x90);
        object->floats[i][30] = floatParams(data, 0x90) + 1;
        object->floats[i][31] = floatParams(data, 0x90) + 2;
        object->floats[i][32] = floatParams(data, 0x90) + 3;
        object->floats[i][33] = floatParams(data, 0x90) + 4;
        object->floats[i][34] = floatParams(data, 0x90) + 5;

        object->ints[i][0] = intParams(data, 0x7C) + 5;
        object->ints[i][1] = intBlock(data, 0x84);
        object->ints[i][2] = intBlock(data, 0x8C);
        object->ints[i][3] = intParams(data, 0x90) + 6;
        object->ints[i][4] = intParams(data, 0x90) + 7;
    }
}
