#pragma force_active on
extern "C" struct Entry { unsigned int v[2]; };

extern "C" Entry* fn_99_887C(Entry* array, int index)
{
    unsigned int n = (unsigned int)index * 8;
    return (Entry*)(((char*)array) + n + 4);
}
