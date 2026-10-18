#pragma force_active on
namespace {
typedef unsigned char Byte;

struct ExtendParamPointers {
    Byte base[0x10];
    const float* floats[2][27];
    const int* ints[2][15];
};

struct ParamBlock {
    float values[23];
};

inline const float* floatBlock(const Byte* data, int offset) {
    return *reinterpret_cast<const float* const*>(data + offset);
}

inline const int* intBlock(const Byte* data, int offset) {
    return *reinterpret_cast<const int* const*>(data + offset);
}

inline const float* floatParams(const Byte* data, int offset) {
    return (*reinterpret_cast<const ParamBlock* const*>(data + offset))->values;
}

inline const int* intParams(const Byte* data, int offset) {
    return reinterpret_cast<const int*>(floatParams(data, offset));
}
}

extern "C" void fn_92_9300(ExtendParamPointers* object, const Byte* data) {
    for (int i = 0; i < 2; ++i) {
        object->floats[i][0] = floatParams(data, 0x7C) + 2;
        object->floats[i][1] = floatParams(data, 0x7C) + 3;
        object->floats[i][2] = floatBlock(data, 0x80);
        object->floats[i][3] = floatParams(data, 0x80) + 1;
        object->floats[i][4] = floatParams(data, 0x80) + 2;
        object->floats[i][5] = floatBlock(data, 0x84);
        object->floats[i][6] = floatParams(data, 0x84) + 1;
        object->floats[i][7] = floatParams(data, 0x84) + 2;
        object->floats[i][8] = floatParams(data, 0x84) + 3;
        object->floats[i][9] = floatParams(data, 0x84) + 4;
        object->floats[i][10] = floatParams(data, 0x84) + 5;
        object->floats[i][11] = floatParams(data, 0x84) + 6;
        object->floats[i][12] = floatParams(data, 0x84) + 7;
        object->floats[i][13] = floatBlock(data, 0x88);
        object->floats[i][14] = floatParams(data, 0x88) + 1;
        object->floats[i][15] = floatParams(data, 0x88) + 2;
        object->floats[i][16] = floatParams(data, 0x8C) + 1;
        object->floats[i][17] = floatParams(data, 0x8C) + 2;
        object->floats[i][18] = floatParams(data, 0x8C) + 3;
        object->floats[i][19] = floatParams(data, 0x8C) + 4;
        object->floats[i][20] = floatParams(data, 0x8C) + 6;
        object->floats[i][21] = floatParams(data, 0x8C) + 7;
        object->floats[i][22] = floatParams(data, 0x8C) + 8;
        object->floats[i][23] = floatParams(data, 0x8C) + 9;
        object->floats[i][24] = floatParams(data, 0x8C) + 10;
        object->floats[i][25] = floatParams(data, 0x8C) + 11;

        object->ints[i][0] = intBlock(data, 0x7C);
        object->ints[i][1] = intParams(data, 0x7C) + 1;
        object->ints[i][2] = intBlock(data, 0x8C);
        object->ints[i][3] = intParams(data, 0x8C) + 5;
        object->ints[i][4] = intParams(data, 0x8C) + 12;
        object->ints[i][5] = intParams(data, 0x8C) + 13;
        object->ints[i][6] = intParams(data, 0x8C) + 14;
        object->ints[i][7] = intParams(data, 0x8C) + 15;
        object->ints[i][8] = intParams(data, 0x8C) + 16;
        object->ints[i][9] = intParams(data, 0x8C) + 17;
        object->ints[i][10] = intParams(data, 0x8C) + 18;
        object->ints[i][11] = intParams(data, 0x8C) + 19;
        object->ints[i][12] = intParams(data, 0x8C) + 20;
        object->ints[i][13] = intParams(data, 0x8C) + 21;
    }
}
