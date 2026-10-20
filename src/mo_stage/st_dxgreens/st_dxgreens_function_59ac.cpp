#pragma force_active on
struct Entry {
    char pad[0x68];
};

extern "C" void* fn_79_59AC(char* base, int index)
{
    return base + index * sizeof(Entry) + 0xc;
}
