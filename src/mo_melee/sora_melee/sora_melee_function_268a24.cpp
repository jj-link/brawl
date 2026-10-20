#pragma force_active on
struct Entry24 {
    unsigned char data[0x18];
};

extern "C" {
void* fn_27_268A24(void* base, int index)
{
    return (char*)base + index * sizeof(Entry24) + 0xC;
}
}
