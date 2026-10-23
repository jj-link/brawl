#pragma force_active on
extern "C" int fn_800BC8D4(void* self)
{
    int x = *(int*)((char*)self + 0x44);
    return x >= 10;
}
