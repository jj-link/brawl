#pragma force_active on
// Accessor for the Fox float parameter table.
// r3 = pointer table held by the caller (array of float pointers at +0x14)
// r4 = index into the selected table

extern "C" float fn_97_B3E0(const float* const* table, unsigned int index) {
    return table[5][index];
}
