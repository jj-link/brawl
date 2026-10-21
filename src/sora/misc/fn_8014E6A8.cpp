#pragma force_active on
extern "C" void fn_8014E6A8(void* p1, unsigned int p2, unsigned int p3)
{
    *(unsigned int*)((char*)p1 + 0x74) = p2;
    *(unsigned int*)((char*)p1 + 0x78) = p3;
}
