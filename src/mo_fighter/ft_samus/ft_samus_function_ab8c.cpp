#pragma force_active on
namespace {
typedef unsigned char Byte;
struct ParamBlock { float values[23]; };
struct Dest { Byte header[0x10]; const float* floats[2][39]; const int* ints[2][7]; };
inline const float* floatBlock(const Byte* data, int offset) { return *reinterpret_cast<const float* const*>(data + offset); }
inline const float* floatParams(const Byte* data, int offset) { return (*reinterpret_cast<const ParamBlock* const*>(data + offset))->values; }
inline const int* intBlock(const Byte* data, int offset) { return *reinterpret_cast<const int* const*>(data + offset); }
inline const int* intParams(const Byte* data, int offset) { return reinterpret_cast<const int*>(floatParams(data, offset)); }
}
extern "C" void fn_94_AB8C(Dest* object, const Byte* data) {
 for (int i = 0; i < 2; ++i) {
 object->floats[i][0] = floatParams(data, 0x7c) + 1;
 object->floats[i][1] = floatParams(data, 0x7c) + 2;
 object->floats[i][2] = floatParams(data, 0x7c) + 3;
 object->floats[i][3] = floatBlock(data, 0x80);
 object->floats[i][4] = floatParams(data, 0x80) + 1;
 object->floats[i][5] = floatParams(data, 0x80) + 2;
 object->floats[i][6] = floatParams(data, 0x80) + 3;
 object->floats[i][7] = floatParams(data, 0x80) + 4;
 object->floats[i][8] = floatParams(data, 0x80) + 5;
 object->floats[i][9] = floatParams(data, 0x80) + 6;
 object->floats[i][10] = floatBlock(data, 0x84);
 object->floats[i][11] = floatParams(data, 0x84) + 1;
 object->floats[i][12] = floatParams(data, 0x84) + 2;
 object->floats[i][13] = floatParams(data, 0x84) + 3;
 object->floats[i][14] = floatParams(data, 0x84) + 4;
 object->floats[i][15] = floatParams(data, 0x84) + 5;
 object->floats[i][16] = floatParams(data, 0x84) + 6;
 object->floats[i][17] = floatParams(data, 0x84) + 7;
 object->floats[i][18] = floatParams(data, 0x84) + 8;
 object->floats[i][19] = floatParams(data, 0x84) + 9;
 object->floats[i][20] = floatParams(data, 0x84) + 10;
 object->floats[i][21] = floatParams(data, 0x84) + 11;
 object->floats[i][22] = floatParams(data, 0x84) + 13;
 object->floats[i][23] = floatParams(data, 0x84) + 14;
 object->floats[i][24] = floatParams(data, 0x84) + 15;
 object->floats[i][25] = floatParams(data, 0x84) + 16;
 object->floats[i][26] = floatParams(data, 0x84) + 17;
 object->floats[i][27] = floatParams(data, 0x84) + 18;
 object->floats[i][28] = floatParams(data, 0x88) + 1;
 object->floats[i][29] = floatParams(data, 0x88) + 2;
 object->floats[i][30] = floatParams(data, 0x88) + 3;
 object->floats[i][31] = floatBlock(data, 0x8c);
 object->floats[i][32] = floatParams(data, 0x8c) + 1;
 object->floats[i][33] = floatParams(data, 0x8c) + 2;
 object->floats[i][34] = floatParams(data, 0x8c) + 3;
 object->floats[i][35] = floatParams(data, 0x8c) + 4;
 object->floats[i][36] = floatParams(data, 0x8c) + 5;
 object->floats[i][37] = floatBlock(data, 0x94);
 object->ints[i][0] = intBlock(data, 0x7c);
 object->ints[i][1] = intParams(data, 0x84) + 12;
 object->ints[i][2] = intBlock(data, 0x88);
 object->ints[i][3] = intParams(data, 0x8c) + 6;
 object->ints[i][4] = intBlock(data, 0x90);
 object->ints[i][5] = intParams(data, 0x90) + 1;
 }
}