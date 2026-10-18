#pragma force_active on
struct SamusArticleIntegerAccesser
{
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[8];
    int *rows[1];
};

extern "C" int fn_94_202BC(
    SamusArticleIntegerAccesser *self,
    void *unused,
    int index,
    int element)
{
    return self->rows[index - self->firstIndex][element];
}
