#pragma force_active on
struct IkeAccesser
{
    unsigned char unused[0x14];
    int firstIndex;
};

extern "C" int fn_119_136D0(IkeAccesser* self, void*, int index, int element)
{
    int** row = (int**)((char*)self + (index - self->firstIndex) * 4 + 0x20);
    return row[0][element];
}
