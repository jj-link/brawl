#pragma force_active on
struct MarioFlagTable {
    unsigned char prefix[0x1c];
    unsigned int* table;
};

extern "C" bool fn_91_A768(MarioFlagTable* self, unsigned int mask, unsigned int index) {
    return (self->table[index] & mask) != 0;
}
