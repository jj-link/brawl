#pragma force_active on
namespace {
struct ArticleIntegerAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[0x20 - 0x18];
    int* rows[1];
};
}

extern "C" int fn_92_12B9C(ArticleIntegerAccesser* self, void* accesser, int index, int element)
{
    return self->rows[index - self->firstIndex][element];
}
