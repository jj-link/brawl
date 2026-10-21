#pragma force_active on
extern "C" void fn_8015E020(void* p1, unsigned int p2, unsigned int p3)
{
    *(unsigned int*)((char*)p1 + 0x10) = p2;
    *(unsigned int*)((char*)p1 + 0x14) = p3;
}
