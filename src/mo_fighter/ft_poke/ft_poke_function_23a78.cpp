#pragma force_active on
namespace {
struct ArticleAccesser {
    unsigned char unused0[0x14];
    int firstIndex;
    unsigned char unused1[0x1C];
    int* rows[1];
};
}

extern "C" int fn_116_23A78(ArticleAccesser* self, void*, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
