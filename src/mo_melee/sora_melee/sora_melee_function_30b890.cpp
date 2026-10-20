#pragma force_active on
typedef unsigned int u32;

extern "C" {
unsigned int fn_27_30B890(char* p, int unused, int a, int b)
{
    char* q = *(char**)(p + ((a - *(int*)(p + 0x14)) << 2) + 0x28);
    return *(u32*)(q + (b << 2));
}
}
