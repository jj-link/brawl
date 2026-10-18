#pragma force_active on
struct ZeldaArticleIntegerAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[0x34 - 0x18];
    int* rows[1];
};

extern "C" int fn_104_24370(ZeldaArticleIntegerAccesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
