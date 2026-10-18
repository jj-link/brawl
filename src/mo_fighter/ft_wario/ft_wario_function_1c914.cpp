#pragma force_active on
struct WarioArticleIntegerAccesser {
    unsigned char prefix[0x14];
    int firstIndex;                       // +0x14: lowest index served by the table
    unsigned char unused[0x20 - 0x18];
    int* rows[1];                         // +0x20: rows[index - firstIndex]
};

extern "C" int fn_110_1C914(WarioArticleIntegerAccesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
