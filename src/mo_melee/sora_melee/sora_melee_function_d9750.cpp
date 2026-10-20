#pragma force_active on
extern "C" {
struct Entry {
    int unk0;
    int unk4;
    int unk8;
    char data[0x54];
};

void* fn_27_D9750(Entry* p, int i)
{
    int n = (p->unk8 >> 30) + i;
    if (n >= 1)
        n--;
    return (char*)p + n * 0x60 + 0xC;
}
}
