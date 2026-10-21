#pragma force_active on
extern "C" void fn_800CC1A4(void* p1, unsigned int p2, unsigned int p3)
{
    if ((*(unsigned char*)((char*)p1 + 0xFCB) >> 7) & 1) {
        return;
    }
    *(unsigned int*)((char*)p1 + 0x1048) = p2;
    *(unsigned int*)((char*)p1 + 0x104C) = p3;
}
