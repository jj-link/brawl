#pragma force_active on
extern "C" int fn_8004D9E8(void* obj)
{
    void* p = *(void**)((char*)obj + 0x24);
    unsigned char b = *(unsigned char*)((char*)p + 0x82a);
    return (b == 0);
}
