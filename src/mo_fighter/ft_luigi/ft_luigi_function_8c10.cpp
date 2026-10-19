#pragma force_active on
struct LuigiTable {
    unsigned int padding[3];
    unsigned int* entries;
};

extern "C" unsigned int fn_99_8C10(LuigiTable* table, unsigned int index) {
    return table->entries[index];
}
