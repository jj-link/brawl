#pragma force_active on
struct Data
{
    unsigned int reserved[2];
    int encodedIndex;
};

extern "C" int* fn_27_1AF7C4(Data* data, int index)
{
    int entry = (data->encodedIndex >> 22) + index;
    if (entry >= 301)
        entry -= 301;

    return (int*)((char*)data + 12 + entry * 4);
}
