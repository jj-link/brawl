#pragma force_active on
extern "C" int fn_27_1A3CA8(void* p)
{
    unsigned int v = *(unsigned int*)((char*)p + 8);
    int r = (int)((v << 10) | (v >> 22)) & 0xFFE00000;
    return r >> 22;
}
