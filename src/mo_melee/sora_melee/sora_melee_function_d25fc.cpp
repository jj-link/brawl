#pragma force_active on
extern "C" int fn_27_D25FC(void* p)
{
    unsigned int x = *(unsigned int*)((char*)p + 8);
    return (int)((x << 2) & 0xE0000000) >> 30;
}
