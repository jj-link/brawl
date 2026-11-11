#pragma force_active on
namespace {
typedef unsigned char Byte;

struct ParamBlock {
    float values[23];
};

struct Dest {
    Byte header[0x10];
    const float* floats[2][61];
    const float* extra[2][2];
};

inline const float* floatBlock(const Byte* data, int offset) {
    return *reinterpret_cast<const float* const*>(data + offset);
}
inline const float* floatParams(const Byte* data, int offset) {
    return (*reinterpret_cast<const ParamBlock* const*>(data + offset))->values;
}
} // namespace

extern "C" void fn_105_D548(Dest* object, const Byte* data) {
    for (int i = 0; i < 2; ++i) {
        object->floats[i][0] = floatBlock(data, 0x8C);
        object->floats[i][1] = floatParams(data, 0x8C) + 1;
        object->floats[i][2] = floatParams(data, 0x8C) + 2;
        object->floats[i][3] = floatParams(data, 0x8C) + 3;
        object->floats[i][4] = floatBlock(data, 0x90);
        object->floats[i][5] = floatParams(data, 0x90) + 1;
        object->floats[i][6] = floatParams(data, 0x90) + 2;
        object->floats[i][7] = floatBlock(data, 0x94);
        object->floats[i][8] = floatParams(data, 0x94) + 1;
        object->floats[i][9] = floatParams(data, 0x94) + 2;
        object->floats[i][10] = floatParams(data, 0x94) + 3;
        object->floats[i][11] = floatParams(data, 0x94) + 4;
        object->floats[i][12] = floatParams(data, 0x94) + 5;
        object->floats[i][13] = floatParams(data, 0x94) + 6;
        object->floats[i][14] = floatParams(data, 0x94) + 7;
        object->floats[i][15] = floatParams(data, 0x94) + 8;
        object->floats[i][16] = floatParams(data, 0x94) + 9;
        object->floats[i][17] = floatParams(data, 0x94) + 10;
        object->floats[i][18] = floatParams(data, 0x94) + 11;
        object->floats[i][19] = floatParams(data, 0x94) + 12;
        object->floats[i][20] = floatParams(data, 0x94) + 13;
        object->floats[i][21] = floatParams(data, 0x94) + 14;
        object->floats[i][22] = floatParams(data, 0x94) + 15;
        object->floats[i][23] = floatParams(data, 0x94) + 16;
        object->floats[i][24] = floatParams(data, 0x94) + 17;
        object->floats[i][25] = floatParams(data, 0x94) + 19;
        object->floats[i][26] = floatParams(data, 0x94) + 20;
        object->floats[i][27] = floatBlock(data, 0x98);
        object->floats[i][28] = floatParams(data, 0x98) + 1;
        object->floats[i][29] = floatParams(data, 0x98) + 2;
        object->floats[i][30] = floatParams(data, 0x98) + 3;
        object->floats[i][31] = floatParams(data, 0x98) + 4;
        object->floats[i][32] = floatParams(data, 0x98) + 5;
        object->floats[i][33] = floatParams(data, 0x98) + 6;
        object->floats[i][34] = floatParams(data, 0x98) + 7;
        object->floats[i][35] = floatParams(data, 0x98) + 8;
        object->floats[i][36] = floatParams(data, 0x98) + 9;
        object->floats[i][37] = floatParams(data, 0x98) + 10;
        object->floats[i][38] = floatParams(data, 0x98) + 11;
        object->floats[i][39] = floatParams(data, 0x98) + 12;
        object->floats[i][40] = floatParams(data, 0x98) + 13;
        object->floats[i][41] = floatParams(data, 0x98) + 14;
        object->floats[i][42] = floatParams(data, 0x98) + 15;
        object->floats[i][43] = floatParams(data, 0x98) + 16;
        object->floats[i][44] = floatParams(data, 0x98) + 17;
        object->floats[i][45] = floatParams(data, 0x98) + 18;
        object->floats[i][46] = floatParams(data, 0x98) + 19;
        object->floats[i][47] = floatParams(data, 0x98) + 20;
        object->floats[i][48] = floatParams(data, 0x98) + 21;
        object->floats[i][49] = floatBlock(data, 0x9C);
        object->floats[i][50] = floatParams(data, 0x9C) + 1;
        object->floats[i][51] = floatParams(data, 0x9C) + 2;
        object->floats[i][52] = floatParams(data, 0x9C) + 3;
        object->floats[i][53] = floatParams(data, 0x9C) + 4;
        object->floats[i][54] = floatParams(data, 0x9C) + 5;
        object->floats[i][55] = floatParams(data, 0x9C) + 6;
        object->floats[i][56] = floatParams(data, 0x9C) + 7;
        object->floats[i][57] = floatParams(data, 0x9C) + 8;
        object->floats[i][58] = floatParams(data, 0x9C) + 9;
        object->floats[i][59] = floatBlock(data, 0xA0);
        object->extra[i][0] = floatParams(data, 0x94) + 18;
    }
}
