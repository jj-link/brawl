#pragma force_active on
struct Table {
    char pad[0x8];
    int m8;
};

extern "C" {
void* fn_27_D9318(Table* p, int idx)
{
    int i = (p->m8 >> 25) + idx;
    if (i >= 0x26) {
        i -= 0x26;
    }
    return (char*)p + i * 0x30 + 0xc;
}
}
