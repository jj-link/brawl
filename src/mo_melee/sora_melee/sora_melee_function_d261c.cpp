#pragma force_active on
struct Entry {
    char data[0x68];
};

extern "C" {
Entry* fn_27_D261C(char* base, int index)
{
    return (Entry*)(base + index * 0x68 + 0xC);
}
}
