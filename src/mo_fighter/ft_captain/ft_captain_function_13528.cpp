#pragma force_active on
// fn_100_13528 (ft_captain, .text:0x00013528, size 0x20)
//
// Returns a float from a table of row pointers embedded in the object:
//   row = obj->rows[param3 - obj->field_0x10]   (rows start at offset 0x18)
//   return row[param4];
// param2 (r4) is passed but unused by the original.

struct Unk {
    unsigned char pad_0[0x10];
    int m_10;          // 0x10: base index subtracted from param3
    int m_14;          // 0x14
    float* m_18[1];    // 0x18: array of row pointers
};

extern "C" float fn_100_13528(Unk* param1, int param2, int param3, int param4) {
    return param1->m_18[param3 - param1->m_10][param4];
}
