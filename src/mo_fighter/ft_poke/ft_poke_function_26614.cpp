#pragma force_active on
typedef unsigned char u8;

namespace {
struct PokeTableAccesser {
    u8 prefix[0x14];
    int firstIndex;
    u8 unused[0x0C];
    int* rows[1];
};
}

extern "C" int fn_116_26614(PokeTableAccesser* self, void*, int index, int element)
{
    return self->rows[index - self->firstIndex][element];
}
