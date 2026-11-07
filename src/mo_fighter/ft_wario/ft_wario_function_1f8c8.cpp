#pragma force_active on
namespace {
typedef unsigned char Byte;
struct Destination { Byte pad[0x10]; const float* first[2][30]; const float* second[2][8]; };
struct ParamBlock { float values[23]; };
inline const float* blk(const Byte* data, int offset) {
    return *reinterpret_cast<const float* const*>(data + offset);
}
inline const float* prm(const Byte* data, int offset) {
    return (*reinterpret_cast<const ParamBlock* const*>(data + offset))->values;
}
}
extern "C" void fn_110_1F8C8(Destination* dst, const Byte* data) {
    for (int i = 0; i < 2; ++i) {
        dst->first[i][0] = prm(data, 0x7C) + 2;
        dst->first[i][1] = prm(data, 0x7C) + 3;
        dst->first[i][2] = prm(data, 0x7C) + 4;
        dst->first[i][3] = prm(data, 0x7C) + 5;
        dst->first[i][4] = prm(data, 0x7C) + 6;
        dst->first[i][5] = prm(data, 0x7C) + 7;
        dst->first[i][6] = prm(data, 0x7C) + 8;
        dst->first[i][7] = blk(data, 0x80);
        dst->first[i][8] = prm(data, 0x80) + 1;
        dst->first[i][9] = prm(data, 0x80) + 2;
        dst->first[i][10] = prm(data, 0x80) + 3;
        dst->first[i][11] = prm(data, 0x80) + 4;
        dst->first[i][12] = prm(data, 0x80) + 5;
        dst->first[i][13] = blk(data, 0x84);
        dst->first[i][14] = prm(data, 0x84) + 1;
        dst->first[i][15] = prm(data, 0x84) + 2;
        dst->first[i][16] = prm(data, 0x84) + 3;
        dst->first[i][17] = prm(data, 0x84) + 4;
        dst->first[i][18] = prm(data, 0x84) + 5;
        dst->first[i][19] = prm(data, 0x84) + 6;
        dst->first[i][20] = prm(data, 0x88) + 3;
        dst->first[i][21] = prm(data, 0x88) + 4;
        dst->first[i][22] = prm(data, 0x88) + 5;
        dst->first[i][23] = prm(data, 0x88) + 6;
        dst->first[i][24] = prm(data, 0x88) + 7;
        dst->first[i][25] = blk(data, 0x8C);
        dst->first[i][26] = prm(data, 0x8C) + 1;
        dst->first[i][27] = prm(data, 0x8C) + 2;
        dst->first[i][28] = prm(data, 0x8C) + 3;
        dst->second[i][0] = blk(data, 0x7C);
        dst->second[i][1] = prm(data, 0x7C) + 1;
        dst->second[i][2] = prm(data, 0x7C) + 9;
        dst->second[i][3] = prm(data, 0x80) + 6;
        dst->second[i][4] = blk(data, 0x88);
        dst->second[i][5] = prm(data, 0x88) + 1;
        dst->second[i][6] = prm(data, 0x88) + 2;
    }
}
