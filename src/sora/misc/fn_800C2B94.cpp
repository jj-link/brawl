#pragma force_active on

extern "C" void fn_800C2B94(unsigned int* self, unsigned int value)
{
    self[0x43] = value;
    self[0x40] = 2;
}
