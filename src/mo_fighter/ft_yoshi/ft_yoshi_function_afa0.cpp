#pragma force_active on
typedef unsigned char Byte;

struct ParamBlock {
    float values[41];
};

struct ExtendParamPointers {
    Byte header[0x10];
    const float* floats[2][83];
    const int* ints[2][7];
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

extern "C" void fn_95_AFA0(ExtendParamPointers* object, const Byte* data) {
    for (int i = 0; i < 2; ++i) {
        object->floats[i][0] = floatParams(data, 0x7C) + 3;
        object->floats[i][1] = floatParams(data, 0x7C) + 4;
        object->floats[i][2] = floatParams(data, 0x7C) + 5;
        object->floats[i][3] = floatParams(data, 0x7C) + 6;
        object->floats[i][4] = floatParams(data, 0x7C) + 7;
        object->floats[i][5] = floatParams(data, 0x7C) + 8;
        object->floats[i][6] = floatParams(data, 0x7C) + 9;
        object->floats[i][7] = floatParams(data, 0x7C) + 10;
        object->floats[i][8] = floatParams(data, 0x7C) + 11;
        object->floats[i][9] = floatParams(data, 0x7C) + 12;
        object->floats[i][10] = floatParams(data, 0x7C) + 13;
        object->floats[i][11] = floatParams(data, 0x7C) + 14;
        object->floats[i][12] = floatParams(data, 0x7C) + 15;
        object->floats[i][13] = floatParams(data, 0x7C) + 16;
        object->floats[i][14] = floatParams(data, 0x7C) + 17;
        object->floats[i][15] = floatParams(data, 0x7C) + 18;
        object->floats[i][16] = floatParams(data, 0x7C) + 19;
        object->floats[i][17] = floatParams(data, 0x7C) + 20;
        object->floats[i][18] = floatParams(data, 0x7C) + 21;
        object->floats[i][19] = floatParams(data, 0x7C) + 22;
        object->floats[i][20] = floatParams(data, 0x7C) + 24;
        object->floats[i][21] = floatParams(data, 0x7C) + 25;
        object->floats[i][22] = floatParams(data, 0x7C) + 26;
        object->floats[i][23] = floatParams(data, 0x7C) + 27;
        object->floats[i][24] = floatParams(data, 0x7C) + 28;
        object->floats[i][25] = floatParams(data, 0x7C) + 29;
        object->floats[i][26] = floatParams(data, 0x7C) + 30;
        object->floats[i][27] = floatParams(data, 0x7C) + 31;
        object->floats[i][28] = floatParams(data, 0x7C) + 32;
        object->floats[i][29] = floatParams(data, 0x7C) + 33;
        object->floats[i][30] = floatParams(data, 0x7C) + 34;
        object->floats[i][31] = floatParams(data, 0x7C) + 35;
        object->floats[i][32] = floatParams(data, 0x7C) + 36;
        object->floats[i][33] = floatParams(data, 0x7C) + 38;
        object->floats[i][34] = floatParams(data, 0x7C) + 39;
        object->floats[i][35] = floatParams(data, 0x7C) + 40;

        object->floats[i][36] = floatBlock(data, 0x80);
        object->floats[i][37] = floatParams(data, 0x80) + 1;
        object->floats[i][38] = floatParams(data, 0x80) + 2;
        object->floats[i][39] = floatParams(data, 0x80) + 3;
        object->floats[i][40] = floatParams(data, 0x80) + 4;
        object->floats[i][41] = floatParams(data, 0x80) + 5;
        object->floats[i][42] = floatParams(data, 0x80) + 6;
        object->floats[i][43] = floatParams(data, 0x80) + 7;
        object->floats[i][44] = floatParams(data, 0x80) + 8;
        object->floats[i][45] = floatParams(data, 0x80) + 9;
        object->floats[i][46] = floatParams(data, 0x80) + 10;
        object->floats[i][47] = floatParams(data, 0x80) + 11;
        object->floats[i][48] = floatParams(data, 0x80) + 12;
        object->floats[i][49] = floatParams(data, 0x80) + 13;
        object->floats[i][50] = floatParams(data, 0x80) + 14;

        object->floats[i][51] = floatBlock(data, 0x84);
        object->floats[i][52] = floatParams(data, 0x84) + 1;
        object->floats[i][53] = floatParams(data, 0x84) + 2;

        object->floats[i][54] = floatBlock(data, 0x88);
        object->floats[i][55] = floatParams(data, 0x88) + 1;
        object->floats[i][56] = floatParams(data, 0x88) + 2;
        object->floats[i][57] = floatParams(data, 0x88) + 3;
        object->floats[i][58] = floatParams(data, 0x88) + 4;
        object->floats[i][59] = floatParams(data, 0x88) + 5;
        object->floats[i][60] = floatParams(data, 0x88) + 6;
        object->floats[i][61] = floatParams(data, 0x88) + 7;
        object->floats[i][62] = floatParams(data, 0x88) + 8;
        object->floats[i][63] = floatParams(data, 0x88) + 9;
        object->floats[i][64] = floatParams(data, 0x88) + 10;
        object->floats[i][65] = floatParams(data, 0x88) + 11;
        object->floats[i][66] = floatParams(data, 0x88) + 12;
        object->floats[i][67] = floatParams(data, 0x88) + 13;
        object->floats[i][68] = floatParams(data, 0x88) + 14;
        object->floats[i][69] = floatParams(data, 0x88) + 15;
        object->floats[i][70] = floatParams(data, 0x88) + 16;
        object->floats[i][71] = floatParams(data, 0x88) + 17;
        object->floats[i][72] = floatParams(data, 0x88) + 18;
        object->floats[i][73] = floatParams(data, 0x88) + 19;
        object->floats[i][74] = floatParams(data, 0x88) + 20;
        object->floats[i][75] = floatParams(data, 0x88) + 21;
        object->floats[i][76] = floatParams(data, 0x88) + 22;
        object->floats[i][77] = floatParams(data, 0x88) + 23;
        object->floats[i][78] = floatParams(data, 0x88) + 24;
        object->floats[i][79] = floatParams(data, 0x88) + 25;

        object->floats[i][80] = floatParams(data, 0x8C) + 1;
        object->floats[i][81] = floatParams(data, 0x8C) + 2;

        object->ints[i][0] = intBlock(data, 0x7C);
        object->ints[i][1] = intParams(data, 0x7C) + 1;
        object->ints[i][2] = intParams(data, 0x7C) + 2;
        object->ints[i][3] = intParams(data, 0x7C) + 23;
        object->ints[i][4] = intParams(data, 0x7C) + 37;
        object->ints[i][5] = intBlock(data, 0x8C);
    }
}
