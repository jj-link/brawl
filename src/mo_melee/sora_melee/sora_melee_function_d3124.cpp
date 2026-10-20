#pragma force_active on
struct Entry {
    char pad[0xa0];
};

extern "C" {
Entry* fn_27_D3124(char* base, int index)
{
    return (Entry*)(base + index * 0xa0 + 0xc);
}
}
