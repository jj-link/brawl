#pragma force_active on
struct GameWatchAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[0x10];
    int* rows[1];
};

extern "C" int fn_107_1FA1C(GameWatchAccesser* self, void*, int index, int element)
{
    return self->rows[index - self->firstIndex][element];
}
