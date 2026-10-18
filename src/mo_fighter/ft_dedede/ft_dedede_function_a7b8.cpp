#pragma force_active on
// fn_117_A7B8: loads a float element from a table at a byte offset of 0x14.
// r3 -> table pointer, r4 -> element index; returns values[index].

struct DededeFloatTable {
    float prefix[5];
    float* values;
};

extern "C" float fn_117_A7B8(DededeFloatTable* table, int index) {
    return table->values[index];
}
