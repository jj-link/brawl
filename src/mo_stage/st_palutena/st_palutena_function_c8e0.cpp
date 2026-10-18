#pragma force_active on
extern "C" void fn_67_C8E0(unsigned char* object)
{
    int value = object[0x150];
    if (value < 4 && value >= 2)
        object[0x150] = 0;
}
