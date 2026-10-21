#pragma force_active on
extern "C" void fn_8010C52C(char* obj, int idx)
{
    *(int*)(obj + 0x30c) = idx;
    obj = obj + idx;
    obj[0x310] = 1;
}
