#pragma force_active on
struct IceClimberAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char padding[8];
    int* rows[1];
};

extern "C" int fn_105_1EA34(IceClimberAccesser* self, void*, int index, int element)
{
    return self->rows[index - self->firstIndex][element];
}
