#pragma force_active on
extern "C" bool fn_68_62B0(void* arg)
{
    return (*(unsigned int*)((char*)arg + 8) >> 25) & 1;
}
