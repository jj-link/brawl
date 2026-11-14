#pragma force_active on
namespace {
typedef unsigned char Byte;

struct ParamBlock {
    float values[23];
};

struct Dest {
    Byte header[0x10];
    const float* floats[2][28];
    const float* extra[2][9];
};

inline const float* floatBlock(const Byte* data, int offset) {
    return *reinterpret_cast<const float* const*>(data + offset);
}
inline const float* floatParams(const Byte* data, int offset) {
    return (*reinterpret_cast<const ParamBlock* const*>(data + offset))->values;
}
} // namespace

extern "C" void fn_111_81A8(Dest* object, const Byte* data) {
    for (int i = 0; i < 2; ++i) {
        object->floats[i][0] = floatBlock(data, 0x7C);
        object->floats[i][1] = floatParams(data, 0x7C) + 1;
        object->floats[i][2] = floatParams(data, 0x7C) + 2;
        object->floats[i][3] = floatParams(data, 0x7C) + 3;
        object->floats[i][4] = floatParams(data, 0x7C) + 4;
        object->floats[i][5] = floatParams(data, 0x7C) + 5;
        object->floats[i][6] = floatParams(data, 0x7C) + 6;
        object->floats[i][7] = floatParams(data, 0x7C) + 7;
        object->floats[i][8] = floatParams(data, 0x7C) + 8;
        object->floats[i][9] = floatParams(data, 0x7C) + 9;
        object->floats[i][10] = floatParams(data, 0x7C) + 10;
        object->floats[i][11] = floatParams(data, 0x7C) + 12;
        object->floats[i][12] = floatParams(data, 0x7C) + 13;
        object->floats[i][13] = floatParams(data, 0x7C) + 14;
        object->floats[i][14] = floatParams(data, 0x7C) + 15;
        object->floats[i][15] = floatParams(data, 0x7C) + 17;
        object->floats[i][16] = floatParams(data, 0x7C) + 18;
        object->floats[i][17] = floatBlock(data, 0x80);
        object->floats[i][18] = floatParams(data, 0x80) + 1;
        object->floats[i][19] = floatParams(data, 0x80) + 2;
        object->floats[i][20] = floatParams(data, 0x80) + 3;
        object->floats[i][21] = floatBlock(data, 0x84);
        object->floats[i][22] = floatParams(data, 0x84) + 1;
        object->floats[i][23] = floatParams(data, 0x84) + 2;
        object->floats[i][24] = floatParams(data, 0x84) + 3;
        object->floats[i][25] = floatParams(data, 0x84) + 4;
        object->floats[i][26] = floatParams(data, 0x84) + 5;

        object->extra[i][0] = floatParams(data, 0x7C) + 11;
        object->extra[i][1] = floatParams(data, 0x7C) + 16;
        object->extra[i][2] = floatParams(data, 0x80) + 4;
        object->extra[i][3] = floatBlock(data, 0x88);
        object->extra[i][4] = floatParams(data, 0x88) + 1;
        object->extra[i][5] = floatParams(data, 0x88) + 2;
        object->extra[i][6] = floatParams(data, 0x88) + 3;
        object->extra[i][7] = floatParams(data, 0x88) + 4;
    }
}
