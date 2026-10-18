#pragma force_active on
namespace {
struct PikminAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[0x18];
    int* rows[1];
};
}

extern "C" int fn_113_2D540(PikminAccesser* self, void* accesser, int index, int element)
{
    return self->rows[index - self->firstIndex][element];
}
