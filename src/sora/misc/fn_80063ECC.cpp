#pragma force_active on
extern "C" void fn_80063ECC(unsigned char* p, int a, int b)
{
    *(unsigned short*)(p + 0x56) = *(unsigned short*)(p + 0x56) | 0x80;
    if (a == 0) {
        return;
    }
    *(int*)(p + 0x70) = a;
    *(int*)(p + 0x74) = b;
}
