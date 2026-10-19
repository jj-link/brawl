#pragma force_active on
extern "C" int fn_72_51BC(void* arg)
{
    unsigned int x = *(unsigned int*)((char*)arg + 8);
    return (x >> 25) & 1;
}
