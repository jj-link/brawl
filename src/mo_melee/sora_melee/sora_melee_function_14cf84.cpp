#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_27_14CF84(char* self, void* a, void* b)
{
    u32 n = *(u32*)(self + 0x48);
    char* base = self + (n << 3);
    *(void**)(base + 0x28) = a;
    *(void**)(base + 0x2c) = b;
    *(u32*)(self + 0x48) = *(u32*)(self + 0x48) + 1;
}
}
