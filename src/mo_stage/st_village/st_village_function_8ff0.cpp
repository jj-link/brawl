#pragma force_active on
extern "C" int fn_70_8FF0(void* param)
{
    return (*(unsigned int*)((char*)param + 8) >> 25) & 1;
}
