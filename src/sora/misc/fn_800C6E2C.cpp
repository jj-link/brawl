#pragma force_active on

extern "C" void fn_800C6E2C(unsigned int* self, unsigned int value)
{
    self[0xE0] = value;
    self[0xD4] = 3;
}
