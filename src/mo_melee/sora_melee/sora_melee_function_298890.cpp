#pragma force_active on
typedef unsigned char u8;

extern "C" {
bool fn_27_298890(void* unused, u8* base)
{
    int x = *(int*)(base + 0x8c0);
    return x != 0x4f;
}
}
