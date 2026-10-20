#pragma force_active on
extern "C" void fn_27_BFE10(char *self, int value, unsigned int mode)
{
    if (mode == 1) {
        self += 0xB8;
    } else {
        self += 0x30;
    }
    *(int *)(self + 0x84) = value;
}
