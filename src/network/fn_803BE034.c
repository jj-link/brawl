#pragma force_active on
void fn_803BE034(void* p1, unsigned int p2, unsigned int p3)
{
    *(unsigned int*)((char*)p1 + 0x0) = p2;
    *(unsigned int*)((char*)p1 + 0x4) = p2;
    *(unsigned int*)((char*)p1 + 0xC) = p3;
}
#pragma force_active reset
